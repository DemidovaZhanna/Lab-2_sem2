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

	string *a = new string[data];

	int *ress = new int[data];
	double *doub = new double[data];

		cout << "Enter the values of the queue: ";
		for (int i = 0; i < data; i++) {
			cin >> a[i];

			while(1) {
				try {
					if (cmd == "Integer")
						ress[i] = stoi(a[i]);
					if (cmd == "Real")
						doub[i] = stod(a[i]);
					break;
				}
				catch (std::invalid_argument&) {
					cout << "The value was entered incorrectly " << endl;
					cin >> a[i];
				}
			}
		}
	auto Int = Queue<int>(ress, data);
	auto Real = Queue<double>(doub, data);
	auto Str = Queue<string>(a, data);

	cout << "What do you want to do with queue? (Select the item number)" << endl;
	cout << "1. Add an item by index\n" << "2. Get an item by index\n"
		 << "3. Get the length\n" << "4. Check empty queue\n"
		 << "5. Remove the first element\n" << "6. Remove the last element\n"
		 << "7. Remove queue\n";

	int input;
	cin >> input;

	if (input == 1) {
		cout << "Write the index: ";
		int index;
		cin >> index;

		while (index > data || index < 0) {
			cout << "Try again: ";
			cin >> index;
		}

		cout << "Write value: ";
		string value;
		cin >> value;

		if (cmd == "Integer") {

			int val;
			while(1) {
				try {
					val = stoi(value);
					break;
				}
				catch (std::invalid_argument&) {
					cout << "Enter integer values: "<< endl;
					cin >> value;
				}
			}

			Int.Assign(index, val);
			cout << Int << endl;
		}

		if (cmd == "Real") {

			try { stod(value);}
			catch (std::invalid_argument&) {
				cout << "Enter integer values: " << endl;
				cin >> value;
			}

			Real.Assign(index, stod(value));
			cout << Real << endl;
		}
		if (cmd == "String") {
			Str.Assign(index, value);
			cout << Str << endl;
		}

		cout << "Select the item number: ";
		cin >> input;
	}

	if (input == 2) {
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
		cin >> input;
	}

	if (input == 3) {
		if (cmd == "Integer")
			cout << "Length is " << Int.getLength() << endl;
		if (cmd == "Real")
			cout << "Length is " << Real.getLength() << endl;
		if (cmd == "String")
			cout << "Length is " << Str.getLength() << endl;

		cout << "Select the item number: ";
		cin >> input;
	}

	if (input == 4) {
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
		cin >> input;
	}

	if (input == 5) {
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
		cin >> input;
	}

	if (input == 6) {
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
		cin >> input;
	}

	if (input == 7) {
		if (cmd == "Integer")
			Int.erase();

		if (cmd == "Real")
			Real.erase();

		if (cmd == "String")
			Str.erase();
		cout << "The queue is erased" << endl;
	}
}
