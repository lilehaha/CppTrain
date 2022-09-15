#include "TestCases.h"
#include "../KString/KString.h"
#include "iostream"

using namespace std;

TestCases::TestCases()
{
}

TestCases::~TestCases()
{
}

void TestCases::TestKString()
{
	KString str1 = KString("test1");
	KString str2 = KString("test2,test3");
	str1 = "test";
	int len = str1.Len();
	str1.Append("append");
	cout << str1 << endl;
	cout << str1.Len() << endl;

	KString sub1 = str2.Sub(1, 2);
	cout << sub1 << endl;

	bool equal = str1 == str2;
	cout << equal << endl;

	int index = str1.Find("es");
	cout << index << endl;

	KString* ret = str2.Split(",");
	cout << ret << endl;
}
