#pragma once

class KRingBuffer
{
	KRingBuffer() {}
	~KRingBuffer() {}
public:
	int write(char* data, int len);
	void read();
private:
	void expend();
	void shrink();
private:
	char* buffer_;
	int size_;
	int capacity_;
	int shrink_threshold_;
	int expend_threshold_;
	static const int DEFAULTCAPACITY = 16;
	static const int MINCAPACITY = 4;
};

