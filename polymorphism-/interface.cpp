#include <iostream>
#include <string>
#include "interface.h"
#include <cstring>

template<typename T>
ostream& operator<< (ostream & out, const Queue<T>& a)
{
	for (int i = 0; i < a.getLength(); ++i)
		out << a.Get(i) << " ";
	return out;
}

template<typename F>
Queue<F> creation(bool condition, int data) {
	F *a = new F[data];

	if(condition) {
		cout << "Enter the values of the queue: ";
		for (int i = 0; i < data; i++)
			cin >> a[i];
	}

	auto qu = Queue<F>(a, data);
	return qu;
}

void interface_queue() {

	cout << "Choose a type of queue: Integer / Real / String" << endl;
	string cmd;
	cin >> cmd;

	while ( cmd != "Integer" && cmd != "Real" && cmd != "String") {
		cout << "Invalid keyword. Try again: ";
		cin >> cmd;
	}

	int data = 0;
	cout << "Write down size of queue: ";
	cin >> data;

	auto Int = creation<int>(cmd == "Integer", data);
	auto Real = creation<double>(cmd == "Real", data);
	auto Str = creation<string>(cmd == "String", data);

	cout << "What do you want to do with queue? (Select the item number)" << endl;
	cout << "1. Add an item by index\n" << "2. Get an item by index\n"
		 << "3. Get the length\n" << "4. Check empty queue\n"
		 << "5. Remove the first element\n" << "6. Remove the last element\n"
		 << "7. Remove queue\n";

	int a;
	cin >> a;

	if (a == 1) {
		cout << "Write the index: ";
		int index;
		cin >> index;

		if (index > data || index < 0) {
			cout << "Try again: ";
			cin >> index;
		}

		cout << "Write value: ";

		if (cmd == "Integer") {
			int value;
			cin >> value;
			Int.Assign(index, value);
			cout << Int << endl;
		}
		if (cmd == "Real") {
			double value;
			cin >> value;
			Real.Assign(index, value);
			cout << Real << endl;
		}
		if (cmd == "String") {
			string value;
			cin >> value;
			Str.Assign(index, value);
			cout << Str << endl;
		}

		cout << "Select the item number: ";
		cin >> a;
	}

	if (a == 2) {
		cout << "Write the index: ";
		int index;
		cin >> index;

		if (index > data || index < 0) {
			cout << "Try again: ";
			cin >> index;
		}

		if (cmd == "Integer") {
			int in = Int.Get(index);
			cout << in << endl;
		}

		if (cmd == "Real") {
			double in = Real.Get(index);
			cout << in << endl;
		}

		if (cmd == "String") {
			string in = Str.Get(index);
			cout << in << endl;
		}

		cout << "Select the item number: ";
		cin >> a;
	}

	if (a == 3) {
		if (cmd == "Integer")
			cout << "Length is " << Int.getLength() << endl;
		if (cmd == "Real")
			cout << "Length is " << Real.getLength() << endl;
		if (cmd == "String")
			cout << "Length is " << Str.getLength() << endl;

		cout << "Select the item number: ";
		cin >> a;
	}

	if (a == 4) {
		if (cmd == "Integer") {
			bool len = Int.empty();
			if (len == 1)
				cout << "Queue is empty" << endl;
			else
				cout << "Length greater than 0" << endl;
		}

		if (cmd == "Real") {
			bool len = Real.empty();
			if (len == 1)
				cout << "Queue is empty " << endl;
			else
				cout << "Length greater than 0" << endl;
		}

		if (cmd == "String") {
			bool len = Str.empty();
			if (len == 1)
				cout << "Queue is empty " << endl;
			else
				cout << "Length greater than 0" << endl;
		}

		cout << "Select the item number: ";
		cin >> a;
	}

	if (a == 5) {
		if (cmd == "Integer") {
			Int.pop_front();
			cout << Int << endl;
		}

		if (cmd == "Real") {
			Real.pop_front();
			cout << Real << endl;
		}

		if (cmd == "String") {
			Str.pop_front();
			cout << Str << endl;
		}

		cout << "Select the item number: ";
		cin >> a;
	}

	if (a == 6) {
		if (cmd == "Integer") {
			Int.pop_back();
			cout << Int << endl;
		}

		if (cmd == "Real") {
			Real.pop_back();
			cout << Real << endl;
		}

		if (cmd == "String") {
			Str.pop_back();
			cout << Str << endl;
		}

		cout << "Select the item number: ";
		cin >> a;
	}

	if (a == 7) {
		if (cmd == "Integer")
			Int.erase();

		if (cmd == "Real")
			Real.erase();
		cout << "The queue is erased" << endl;

		if (cmd == "String")
			Str.erase();
		cout << "The queue is erased" << endl;
	}
}
