#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : capacity_( capacity ) { }

void Writer::push( string data )
{
  // Your code here.
  if (!is_closed()) {
    if (available_capacity() <= 0) {
      std::cout << "The stream is FULL, so you cannot push any data!" << std::endl;
    } else {
      uint64_t current_bytes_pushed = min(available_capacity(), data.size());
      buffer_ += data.substr(0, current_bytes_pushed);
      bytes_pushed_ += current_bytes_pushed;
    }
  } else {
    std::cout << "The stream is CLOSED, so you cannot push any data!" << std::endl;
  }

}

void Writer::close()
{
  // Your code here.
  closed_ = true;
}

bool Writer::is_closed() const
{
  return closed_; // Your code here.
}

uint64_t Writer::available_capacity() const
{
  return capacity_ - buffer_.size(); // Your code here.
}

uint64_t Writer::bytes_pushed() const
{
  return bytes_pushed_; // Your code here.
}

string_view Reader::peek() const
{
  // Your code here.
  if (!buffer_.empty()) {
    std::string_view top_byte(buffer_);
    return top_byte; 
  } else {
    std::cout << "The stream is empty, so you cannot peek any bytes!" << std::endl;
    std::string_view empty_str("");
    return empty_str;
  }

}

void Reader::pop( uint64_t len )
{
  // Your code here.
  if (buffer_.empty()) {
    std::cout << "The stream is empty, so no more bytes will be popped out!" << std::endl;
  } else {
    uint64_t current_bytes_popped = min(len, buffer_.size());
    buffer_.erase(0, current_bytes_popped);
    bytes_popped_ += current_bytes_popped;
  }  
}

bool Reader::is_finished() const
{
  return closed_ && buffer_.empty(); // Your code here.
}

uint64_t Reader::bytes_buffered() const
{
  return buffer_.size(); // Your code here.
}

uint64_t Reader::bytes_popped() const
{
  return bytes_popped_; // Your code here.
}

