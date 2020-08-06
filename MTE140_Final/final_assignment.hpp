#pragma once
#ifndef FINAL_ASSIGNMENT_HPP
#define FINAL_ASSIGNMENT_HPP

#include <string>
#include <vector>

using namespace std;


class Graph {
protected:
	// Forward declaration of stucts
	struct Person;
	struct Edge;

	// Full declaration of structs
	struct Person {
		// Empty Constructor
		Person() : testResult(NULL) {}
		// Full Parametric Constructor
		Person(string newID, string newFirstName, string newRecentTestDate, bool newTestResult) :
			ID(newID), firstName(newFirstName), recentTestDate(newRecentTestDate), testResult(newTestResult) {}

		// Object data
		vector<Edge> contactList;
		string ID, firstName, recentTestDate;
		bool testResult;

		// Equal operator override - only check ID
		bool operator==(const Person& rhs) {
			return ID == rhs.ID;
		}
	};
	struct Edge {
		// Empty Constructor
		Edge() : numDays(NULL), contact(nullptr) {}
		// Full Parametric Constructor
		Edge(int newNumDays, string newLocation, Person* newContact) :
			numDays(newNumDays), location(newLocation), contact(newContact) {}

		// Object data
		int numDays;
		string location;
		Person* contact;
		bool operator==(const Edge& rhs) {
			return numDays == rhs.numDays && location == rhs.location && contact == rhs.contact;
		}
	};

	// Give access of protected objects to test class
	friend class GraphTest;

	// Number of people
	int numPeople = 0;
	// Vector that holds all people
	vector<Person*> populationList;

public:
	// STEP 1:
	// CONSTRUCTOR & DESTRUCTOR

	// Purpose: Default/empty contructor
	Graph();
	// Purpose: Destructor
	~Graph();


	// MUTATORS

	// Purpose: Add person
	bool addPerson(Person personInfo);
	// Purpose: Add contact info
	bool addEdge(int numDays, string location, string host, string contact);

	// Purpose: Helper function to find location of person in populationList vector
	int findPersonIndex(string targetID);

	// STEP 2:
	// Purpose: Count number of individuals contacted who tested positive
	int count_virus_positive_contacts(string person_id);
};



#endif