#include "DynamicArray.h"
#include "LinkedList.h"
#include "tests.hpp"
#include "interface.h"

#include <iostream>

using namespace std;

int main()
{
	TestRunner runner;
	runner.RunTest(test_dynamic_array_function, "test_dynamic_array_function");
	runner.RunTest(test_array_sequence, "test_array_sequence");
	runner.RunTest(test_LinkedList_function, "test_LinkedList_function");
	runner.RunTest(tests_list_sequence, "tests_list_sequence");
	runner.RunTest(tests_queue, "tests_queue");

	cout << endl;
	interface_queue();

	return 0;
}
