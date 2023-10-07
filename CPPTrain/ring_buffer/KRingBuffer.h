#pragma once
#include <vector>

template<class T>
class KRingBuffer
{
public:
	KRingBuffer() : buffer(8), readIndex(0), writeIndex(0), bufferSize(8), size(0) {}

	void push(const T& data) {
		if (size == bufferSize) {
			resizeBuffer(bufferSize * 2);
		}
		buffer[writeIndex] = data;
		writeIndex = (writeIndex + 1) % bufferSize;
		size++;
	}

	T pop() {
		if (size == 0) {
			throw std::out_of_range("Buffer is empty");
		}
		T data = buffer[readIndex];
		readIndex = (readIndex + 1) % bufferSize;
		size--;
		if (size <= bufferSize / 4) {
			shrinkBuffer();
		}
		return data;
	}

	size_t getSize() const {
		return bufferSize;
	}

private:
	void resizeBuffer(size_t newSize) {
		std::vector<T> newBuffer(newSize);
		for (size_t i = 0; i < size; i++) {
			newBuffer[i] = buffer[(readIndex + i) % bufferSize];
		}
		buffer = std::move(newBuffer);
		bufferSize = newSize;
		readIndex = 0;
		writeIndex = size;
	}

	void shrinkBuffer() {
		size_t newBufferSize = size * 2;
		if (newBufferSize >= bufferSize) {
			return;
		}
		resizeBuffer(newBufferSize);
	}

private:
	std::vector<T> buffer;
	size_t readIndex;
	size_t writeIndex;
	size_t bufferSize;
	size_t size;
};