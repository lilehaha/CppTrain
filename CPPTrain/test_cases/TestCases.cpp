#include "TestCases.h"
#include "../string/KString.h"
#include "../array/KArray.h"
#include "../list/KList.h"
#include "../ring_buffer/KRingBuffer.h"
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
	cout << ret[0] << endl;
	cout << ret[1] << endl;
}

void TestCases::TestKArray()
{
	auto arr = new KArray<int>();
	arr->reserve(4);
	arr->push(1);
	arr->push(2);
	arr->insert(1, 3);
	arr->remove(1);
	arr->pop();
	arr->clear();
	arr->print();
}

void TestCases::TestKList()
{
	auto list1 = new KList<int>();
	auto node1 = list1->push(1);
	auto node2 = list1->push(2);
	auto node3 = list1->insert(node2, 3);
	auto ret = list1->find(2);
	list1->remove(node2);
	list1->popAll();
	list1->printlist();
}

void TestCases::TestKRingBuffer()
{
	//auto ringBuffer = new KRingBuffer(10);
	//auto c = "abcdefghij";
	//ringBuffer->write(c, 10);
	//ringBuffer->write(c, 20);
	//ringBuffer->capacity();
}
