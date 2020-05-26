#ifndef TESTS_HPP
#define TESTS_HPP

#include <sstream>
#include <exception>
#include <iostream>
#include <string>

#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "queue.h"

using namespace std;


template<typename T>
ostream& operator<< (ostream & out, const DynamicArray<T>& a) //обязательно ли писать 3 одинаковых оператора для разных классов?
{														      //или есть другой способ?
	for (int i = 0; i < a.getLength(); ++i)				      //шаблон для всех не сработал(
		out << a[i] << " ";
	return out;
}

template<typename T>
ostream& operator<< (ostream & out, const LinkedList<T>& a)
{
	for (int i = 0; i < a.getLength(); ++i)
		out << a[i] << " ";
	return out;
}

template<typename T>
ostream& operator<< (ostream & out, const Sequence<T>& a)
{
	for (int i = 0; i < a.getLength(); ++i)
		out << a.Get(i) << " ";
	return out;
}

template<typename T>
ostream& operator<< (ostream & out, const Queue<T>& a)
{
	for (int i = 0; i < a.getLength(); ++i)
		out << a.Get(i) << " ";
	return out;
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint)
{
  if (t != u) {
	ostringstream os;
	os << "Assertion failed: " << t << " != " << u << " hint: " << hint;
	throw runtime_error(os.str());
  }
}


class TestRunner
{
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cout << test_name << " OK" << endl;
		} catch (runtime_error& e) {
			++fail_count;
			cout << test_name << " fail: " << e.what() << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cout << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}
private:
	int fail_count = 0;
};


void test_dynamic_array_function ()
{
	AssertEqual(DynamicArray<int>().getLength(), 0, "The length is 0");

	int A[5] = {1, 2, 3, 4, 5};
	DynamicArray<int> dynamic_array(A, 5);

	DynamicArray<int> array2 = dynamic_array;
	AssertEqual(dynamic_array, array2, "copyconstructor");

	dynamic_array.Set(0, 7);
	dynamic_array.Set(6, 9);

	AssertEqual(dynamic_array.operator[](3), 3, "Element 3 is in the third position");
	AssertEqual(dynamic_array.GetLast(), 9, "Element 9 is in the last position");
	AssertEqual(dynamic_array.GetFirst(), 7, "Element 7 is in the first position");

	int exp[7] = {7, 1, 2, 3, 4, 5, 9};
	DynamicArray<int> new_array(exp, 7);

	AssertEqual(dynamic_array, new_array, "Adding an element '7' to the beginning and '9' to the end of the array");
}


void test_array_sequence() {
	AssertEqual(ArraySequence<int>().getLength(), 0, "The length is 0");

	int a[] = {1, 2, 3, 4, 6, 7, 8, 4};
	auto ar = ArraySequence<int>(a, 8);
	AssertEqual(ar.getLength(), 8, "The length is 8");
	AssertEqual(ar.Get(3), 4, "Get");

	ar.Append(9);

	int res[] = {9, 1, 2, 3, 4, 6, 7, 8, 4};
	auto Res = ArraySequence<int>(res, 9);
	AssertEqual(ar, Res, "Append");
}


void test_LinkedList_function () {

	int a[] = {1, 2, 3, 4, 5};
	auto list = LinkedList<int>(a, 5);

	int b[] = {1, 2, 3, 4};
	auto list_n = LinkedList<int>(b, 4);

	AssertEqual(list_n.operator[](2), 3, "Get");
	AssertEqual(*list.GetSubList(0 , 3), list_n, "GetSubList");

	int res[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	auto list_now = LinkedList<int>(res, 10);

	AssertEqual(*list_now.GetSubList(5, 9), list, "GetSubList");
	AssertEqual(*list.Concat(&list), list_now, "Concat" );

	list_n.Prepend(5);
	AssertEqual(list_n, list, "Prepend");

	AssertEqual(list_n.getLength(), 5, "The length is 5");

	list_now.pop_back();
	list_now.pop_front();

	int re[] = {2, 3, 4, 5, 1, 2, 3, 4};
	auto li = LinkedList<int>(re, 8);
	AssertEqual(li, list_now, "Deleting the first and last element");

	li.clear();
	AssertEqual(li.getLength(), LinkedList<int>().getLength(), "The length is 0");
}

void tests_list_sequence() {

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	auto err = ListSequence<int>(a, 8);
	auto err2 = ListSequence<int>(a, 8);

	AssertEqual(err.GetFirst(), 1, "The first element is 1");

	err.Append(0);
	err.Prepend(9);

	int ar[10];
	for (int i = 0; i < 10; i++)
		ar[i] = i;
	auto li = ListSequence<int>(ar, 10);

	AssertEqual(err, li, "Append, Prepend and equality");

	li.pop_front();
	li.pop_back();

	AssertEqual(li, err2, "pop_front and pop_back");

	li.erase();
	AssertEqual(li.getLength(), ListSequence<int>().getLength(), "erase");
}

void tests_queue() {

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	auto qu = Queue<int>(a, 8);
	auto qu2 = Queue<int>(a, 8);

	AssertEqual(qu.getLength(), 8, "The length is 8");

	qu.Append(0);
	qu.Prepend(9);

	int res[10];
	for (int i = 0; i < 10; i++)
		res[i] = i;
	auto Res = Queue<int>(res, 10);

	AssertEqual(qu, Res, "Append and Prepend");

	Res.pop_back();
	Res.pop_front();
	AssertEqual(Res, qu2, "pop_back and pop_front");

	qu.erase();
	AssertEqual(qu.getLength(), 0, "empty and size");

	AssertEqual(qu, qu, "comparison of zero lengths");
}

#endif // TESTS_HPP
