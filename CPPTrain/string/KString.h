#pragma once
#include "iostream"

using std::ostream;
using std::istream;

static const int CINLIM = 80;
class KString
{
public:
	KString(const char* str = nullptr);
	KString(const KString& other);
	KString& operator = (const KString& other);
	unsigned int Len() const;
	void Append(const char* str);
	KString Sub(int start,int count);
	int Find(const char* cstr);
	KString* Split(const char* str);
	~KString();
	char operator[](int index) const;
	friend bool operator==(const KString& lkstr, const KString& rkstr);
	friend ostream& operator<<(ostream& os, const KString& str);
	friend istream& operator>>(istream& is, KString& str);
protected:
	unsigned int strlen(const char* str);
	char* strcpy(char* dest, const char* src);
private:
	unsigned int mLen;
	char* mData;
};

