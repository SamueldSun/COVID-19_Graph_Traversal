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

	bool test3() {
		Graph testGraph; 
		ASSERT_TRUE(testGraph.addPerson(Graph::Person("AB", "Dave", "8/05/2020", false)))
			ASSERT_TRUE(testGraph.addPerson(Graph::Person("BC", "Tom", "7/21/2020", true)))
			ASSERT_TRUE(testGraph.addPerson(Graph::Person("CD", "Richard", "9/20/2020", true)))
			ASSERT_TRUE(testGraph.addEdge(2, "Park", "AB", "BC"))
			ASSERT_TRUE(testGraph.addEdge(4, "Library", "BC", "CD"))
			ASSERT_TRUE(testGraph.count_virus_positive_contacts("AB") == 2)
			return true;
	}

	bool test4() {
		Graph testGraph;
		ASSERT_TRUE(testGraph.addPerson(Graph::Person("AB", "Dave", "8/05/2020", false)))
			ASSERT_TRUE(testGraph.addPerson(Graph::Person("BC", "Tom", "7/21/2020", true)))
			ASSERT_TRUE(testGraph.addPerson(Graph::Person("CD", "Richard", "9/20/2020", false)))
			ASSERT_TRUE(testGraph.addPerson(Graph::Person("EF", "Bill", "5/19/2020", true)))
			ASSERT_TRUE(testGraph.addPerson(Graph::Person("FG", "Dan", "5/15/2020", false)))
			ASSERT_TRUE(testGraph.addEdge(2, "Park", "AB", "BC"))
			ASSERT_TRUE(testGraph.addEdge(4, "Library", "BC", "CD"))
			ASSERT_TRUE(testGraph.addEdge(1, "Restaurant", "EF", "FG"))
			ASSERT_TRUE(testGraph.count_virus_positive_contacts("AB") == 1)
			ASSERT_TRUE(testGraph.count_virus_positive_contacts("FG") == 1)
			ASSERT_TRUE(testGraph.find_largest_cluster_with_two_positive() == 0)
			return true;
	}
};

#endif
