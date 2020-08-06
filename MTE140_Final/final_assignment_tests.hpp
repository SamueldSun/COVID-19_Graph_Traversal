#pragma once
#ifndef FINAL_ASSIGNMENT_TESTS
#define FINAL_ASSIGNMENT_TESTS

#include <iostream>
#include <string>

using namespace std;

#include "final_assignment.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class GraphTest {
public:
	bool test1() {
		// Add people
		Graph testGraph;
		ASSERT_TRUE(testGraph.addPerson(Graph::Person("AB", "Dave", "8/05/2020", false)))
			ASSERT_TRUE(testGraph.addPerson(Graph::Person("BC", "Tom", "7/21/2020", false)))
			return true;
	}

	bool test2() {
		// Add people and edges
		Graph testGraph;
		ASSERT_TRUE(testGraph.addPerson(Graph::Person("AB", "Dave", "8/05/2020", false)))
			ASSERT_TRUE(testGraph.addPerson(Graph::Person("BC", "Tom", "7/21/2020", false)))
			ASSERT_TRUE(testGraph.addEdge(2, "Park", "AB", "BC"))
			return true;
	}
};

#endif
