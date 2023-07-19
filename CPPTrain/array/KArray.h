#pragma once

#include <assert.h>
#include <iostream>

template<typename T>
class KArray
{
public:
	KArray() :mSize(0), mBuff(nullptr), mCapacity(0) {}
	~KArray() {
		clear();
	}
	void reserve(size_t capacity) 
	{
		T* tempBuff = new T[capacity];
		mCapacity = capacity;
		if (mBuff)
		{
			memcpy(tempBuff, mBuff, mSize * sizeof(T));
			delete[] mBuff;
		}
		mBuff = tempBuff;
	}
	void push(const T& val)
	{
		_expand();
		mBuff[mSize] = val;
		mSize++;
	}
	void insert(size_t index, T val)
	{
		_expand();
		for (size_t i = mSize - 1; i >= index; i--)
		{
			mBuff[i + 1] = mBuff[i];
		}
		mBuff[index] = val;
		mSize++;
	}
	void remove(size_t index)
	{
		if (index >= mSize)return;
		for (size_t i = index; i < mSize - 1; i++) {
			mBuff[i] = mBuff[i + 1];
		}
		mSize--;
	}
	T pop()
	{
		assert(mSize);
		mSize--;
		return mBuff[mSize - 1];
	}
	void clear()
	{
		mSize = 0;
		mCapacity = 0;
		if (mBuff)
		{
			delete[] mBuff;
			mBuff = nullptr;
		}

	}
	T findIndex(size_t index)
	{

	}
	T& operator[](size_t index) {
		assert(index < mSize);
		return *(mBuff + index);
	}
	void print()
	{
		for (auto i = 0; i < mSize; ++i)
		{
			std::cout << mBuff[i] << "  ";
		}
		std::cout << "\n";
	}
private:
	void _expand()
	{
		if (mCapacity == mSize) {
			mCapacity = mCapacity ? mCapacity << 1 : 2;
		}
		T* tempBuff = new T[mCapacity];
		if (mBuff)
		{
			memcpy(tempBuff, mBuff, mSize * sizeof(T));
			delete[] mBuff;
		}
		mBuff = tempBuff;
	}
private:
	T* mBuff;
	int mSize;
	int mCapacity;
};

