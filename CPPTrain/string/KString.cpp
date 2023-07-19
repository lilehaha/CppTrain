#include "KString.h"
#include <cassert>

KString::KString(const char* str) : mLen(0), mData(nullptr)
{
	if (str == nullptr)
	{
		mData = new char[0];
		*mData = '\0';
	}
	else
	{
		mLen = strlen(str);
		mData = new char[mLen + 1];
		strcpy(mData, str);
	}
}

KString::KString(const KString& other)
{
	mLen = strlen(other.mData);
	mData = new char[mLen + 1];
	strcpy(mData, other.mData);
}

KString& KString::operator=(const KString& other)
{
	if (this != &other)
	{
		if (!mData) delete[] mData;
		mLen = other.Len();
		mData = new char[mLen + 1];
		strcpy(mData, other.mData);
	}
	return *this;
}

unsigned int KString::Len() const
{
	return mLen;
}

void KString::Append(const char* str)
{
	assert(str != nullptr);
	if (mLen != 0)
	{
		int oldLen = mLen;
		mLen += strlen(str);
		mData = (char*)realloc(mData, (mLen+1) * sizeof(char));
		for (int i = oldLen; i < mLen; i++)
		{
			mData[i] = str[i - oldLen];
		}
		mData[mLen] = '\0';
	}
	else
	{
		*this = str;
	}
}

KString KString::Sub(int start, int count)
{
	assert(start < mLen);
	assert(start + count <= mLen);
	char* substring = new char[count + 1];
	for (int i = start; i < start + count; ++i)
	{
		substring[i - start] = this->mData[i];
	}
	substring[count] = '\0';
	return KString(substring);
}

int KString::Find(const char* cstr)
{
	int currentLength = this->strlen(cstr);
	for (int i = 0; i < this->Len(); ++i)
	{
		bool isMatch = true;
		for (int ii = 0; ii < currentLength; ++ii)
		{
			if (this->mData[i + ii] != cstr[ii])
			{
				isMatch = false;
				break;
			}
		}
		if (isMatch)
		{
			return i;
		}
	}
	return -1;
}

KString* KString::Split(const char* str)
{
	int alength = 0, length = Len();
	for (int i = 0; i < length; i++)
		if (mData[i] == *str)
			alength++;
	KString* StrArr = new KString[alength + 1];
	StrArr->Len();
	int Begin = 0, aIndex = 0;
	for (int i = 0; i < length;)
	{
		while (i <= length && mData[i++] != *str) {}

		StrArr[aIndex++] = Sub(Begin, i - Begin - 1);
		Begin = i;
	}
	StrArr->Len();
	return StrArr;
}

KString::~KString()
{
	delete[] mData;
}

char KString::operator[](int index) const
{
	if (index >= this->mLen)
	{
		throw 1;
	}
	return this->mData[index];

}

unsigned int KString::strlen(const char* str)
{
	assert(str != nullptr);
	const char* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

char* KString::strcpy(char* dest, const char* src)
{
	assert(dest != nullptr && src != nullptr);
	if (dest == nullptr || src == nullptr) {
		return nullptr;
	}
	if (dest == src) {
		return dest;
	}
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

bool operator==(const KString& lkstr, const KString& rkstr)
{
	if (lkstr.Len() != rkstr.Len())
	{
		return false;
	}
	int llength = lkstr.Len();
	int count = 0;
	while ((count < llength) && (lkstr[count] == rkstr[count]))
	{
		count++;
	}
	return (count == llength);

}

ostream& operator<<(ostream& os, const KString& str)
{
	os << str.mData;
	return os;
}

istream& operator>>(istream& is, KString& str)
{
	char temp[CINLIM];
	is.get(temp, CINLIM);
	if (is)
		str = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
