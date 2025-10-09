#include "reassembler.hh"
#include "debug.hh"

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring )
{
  // cannot push any substrings because connection is close
  if ( output_.writer().is_closed() )
    return;

  // eof mark
  if ( is_last_substring ) {
    eof_ = true;
    eof_idx_ = first_index + data.size();
  }

  uint64_t first_unacceptable_idx = first_unassembled_idx_ + output_.writer().available_capacity();
  // truncate bytes exceeding the capacity (cut off suffix)
  data = data.substr( 0, min( data.size(), first_unacceptable_idx - first_index ) );

  if ( data.size() > 0 && first_index + data.size() > first_unassembled_idx_ ) {
    // exactly adjacent or overlapped with assembled bytes, so cut off prefix
    if ( first_index < first_unassembled_idx_ ) {
      data = data.substr( first_unassembled_idx_ - first_index );
      first_index = first_unassembled_idx_;
    }

    // Core: MERGE
    uint64_t new_head = first_index;
    uint64_t new_tail = first_index + data.size();
    string new_bytes = data;

    // find the first overlapped segment in the buffer
    auto it = buf_.lower_bound( first_index );
    if ( it != buf_.begin() ) {
      --it;
    }

    // try to merge all possible segments in the buffer
    while ( it != buf_.end() ) {
      uint64_t item_head = it->first;
      uint64_t item_tail = it->first + it->second.size();

      // no overlap
      if ( new_head > item_tail || new_tail < item_head ) {
        ++it;
        continue;
      }

      // merge!
      uint64_t merged_head = min( new_head, item_head );
      uint64_t merged_tail = max( new_tail, item_tail );
      string merged_bytes( merged_tail - merged_head, '\0' );
      memcpy( &merged_bytes[new_head - merged_head], new_bytes.data(), new_bytes.size() );
      memcpy( &merged_bytes[item_head - merged_head], it->second.data(), it->second.size() );

      // update bytes to be inserted
      new_head = merged_head;
      new_tail = merged_tail;
      new_bytes = merged_bytes;

      // remove the original one
      it = buf_.erase( it );
    }

    // put the new bytes in the buffer (temporarily)
    buf_[new_head] = new_bytes;

    // push adjacent segments in the buffer to ByteStream
    while ( !buf_.empty() && buf_.begin()->first == first_unassembled_idx_ ) {
      output_.writer().push( buf_.begin()->second );
      first_unassembled_idx_ += buf_.begin()->second.size();
      buf_.erase( buf_.begin() );
    }
  }
  // otherwise this substring has been already assembled

  // close connection if all substrings are assembled
  if ( eof_ && first_unassembled_idx_ >= eof_idx_ )
    output_.writer().close();
}

// How many bytes are stored in the Reassembler itself?
// This function is for testing only; don't add extra state to support it.
uint64_t Reassembler::count_bytes_pending() const
{
  uint64_t cnt = 0;
  for ( auto it = buf_.begin(); it != buf_.end(); ++it ) {
    cnt += it->second.size();
  }
  return cnt;
}
