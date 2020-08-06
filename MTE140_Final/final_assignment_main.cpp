#include <iostream>
#include <string>

#include "final_assignment_tests.hpp"

using namespace std;

string get_status_str(bool status) {
	return status ? "TEST PASSED" : "TEST FAILED";
}

int main() {
	GraphTest final_assignment_tests;

	const int numTests = 2;

	// Store test descriptions
	string test_description[numTests] = {
		"Test1: Add some people",
		"Test2: Add 2 people and an edge"
	};

	// Conduct the tests
	bool test_results[numTests];
	test_results[0] = final_assignment_tests.test1();
	test_results[1] = final_assignment_tests.test2();

	// Print Graph ADT test results to console
	cout << "CONTACT TRACING TEST RESULTS" << endl;
	cout << "----------------------------" << endl;
	for (int index = 0; index < numTests; index++) {
		cout << test_description[index] << endl;
		cout << get_status_str(test_results[index]) << endl << endl;
	}
}