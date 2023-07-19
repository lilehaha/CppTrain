#include "KRingBuffer.h"
#include <cstring>

//KRingBuffer::KRingBuffer() :
//	capacity_(DEFAULTCAPACITY),
//	size_(0),
//	buffer_(new char[capacity_]),
//	shrink_threshold_(capacity_ / 4),
//	expend_threshold_(capacity_ * 3 / 4)
//{}

int KRingBuffer::write(char* data, int len)
{
	if (len > capacity_ - size_)
	{
		expend();
	}
	memcpy(buffer_, data, len);
	size_ += len;

	if (capacity_ > MINCAPACITY && capacity_ < shrink_threshold_)
	{
		shrink();
	}
	return len;
}
void KRingBuffer::read()
{

}

void KRingBuffer::expend() {

}

void KRingBuffer::shrink() {

}
