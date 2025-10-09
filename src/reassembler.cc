#include "reassembler.hh"
#include "debug.hh"

#include <algorithm>
#include <string>

using namespace std;

void Reassembler::insert( uint64_t first_index, string data, bool is_last_substring )
{
  // cannot push any substrings because connection is close
  if (output_.writer().is_closed())
    return;

  // check the available capacity
  uint64_t first_unacceptable_idx = first_unassembled_idx_ + output_.writer().available_capacity();

  // truncate bytes exceeding the capacity
  uint64_t true_size = std::min(data.size(), first_unacceptable_idx - first_index);

  if (first_index == first_unassembled_idx_) {
    // remove the overlapping substring already in the buffer
    while (!buf_.empty() && first_index + true_size >= buf_.top().first) {
      current_size_ -= buf_.top().second.size();
      buf_.pop();
    }

    // write to the byte stream
    output_.writer().push(data.substr(0, true_size));
    first_unassembled_idx_ += true_size;

    // check internal storage
    // only pop out adjacent bytes
    while (!buf_.empty() && buf_.top().first == first_unassembled_idx_) {
      true_size = std::min(buf_.top().second.size(), first_unacceptable_idx - buf_.top().first);
      output_.writer().push(buf_.top().second);
      first_unassembled_idx_ = buf_.top().first + true_size;
      current_size_ -= buf_.top().second.size();
      buf_.pop();
    }
  } else if (first_index > first_unassembled_idx_) {      // earlier bytes remain unknown
    current_size_ += true_size;
    buf_.push({first_index, data.substr(0, true_size)});
  }
  // ignore overlap case (i.e. first_index <= first_unassembled_idx_)
  
  // close connection if the substring is the last one
  if (is_last_substring)
    output_.writer().close();
}

// How many bytes are stored in the Reassembler itself?
// This function is for testing only; don't add extra state to support it.
uint64_t Reassembler::count_bytes_pending() const
{
  return current_size_;
}
