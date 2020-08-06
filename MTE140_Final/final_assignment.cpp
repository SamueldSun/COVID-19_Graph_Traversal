#include "final_assignment.hpp"
#include <iostream>
#include <string>
#include <queue>

Graph::Graph() : numPeople(0), populationList() {
}

Graph::~Graph() {
}

// Purpose: Add person
bool Graph::addPerson(Person personInfo) {
	Person* newPerson = new Person(personInfo);
	populationList.push_back(newPerson);
	numPeople++;
	return true;
}

// Purpose: Add contact info
bool Graph::addEdge(int numDays, string location, string host, string contact) {
	Edge person1;															// Contact info for host
	Edge person2;															// Contact info for contact
	
	// Add edge to host
	int hostLocation = findPersonIndex(host);
	int contactLocation = findPersonIndex(contact); 
	if (hostLocation == -1 || contactLocation == -1)						// Check if host and contact exist in list
		return false;														// If not then exit
	else {
		Person* hostAddress = populationList.at(hostLocation);				// Else, find host's info and
		Person* contactAddress = populationList.at(contactLocation);		//	contact's info addresses

		// Host edge info
		person1.numDays = numDays;
		person1.location = location;
		person1.contact = contactAddress;
		// Contact edge info
		person2.numDays = numDays;
		person2.location = location;
		person2.contact = hostAddress;

		// Add edges to contacts
		hostAddress->contactList.push_back(person1);
		contactAddress->contactList.push_back(person2);
	}
	return true;
}

// Purpose: Helper function to find location of person in populationList vector
int Graph::findPersonIndex(string targetID) {
	for (int index = 0; index < populationList.size(); index++) {
		if (populationList.at(index)->ID == targetID) {				// Look for a person that matches the requested ID
			return index;											// If found, then return its index
		}
	}
	return -1;														// If it doesn't exist, then return -1
}

// Purpose: Helper function to see if person address exists in contactList vector
bool Graph::wasSeen(bool seen, Person* target) {
	// TODO: scan through the array and see if the target was found, I'll probably delete this later
	return false;
}

int Graph::count_virus_positive_contacts(string person_id) {

	/*
	NOTE:
	Below is my attempt to get the graph traversal working
	Basically just choosing some starting point, moving to a different node and keeping track of the unused paths, and if the person
		in the node is positive, increment some total virus counter. Once everything's scanned, return the total positive tests.
	I'm too tired rn to get it working, I'll have another crack in the morning with a fresh mind and some coffee :)
	Try it out and see if you can get something together, if not dw I'll handle it
	Other than this there's still the "find_largest_cluster_with_two_positive" function and we need to get some test cases together,
		maybe have a stab at those as well
	
	Lol imma head off to sleep for now

	-Sam
	*/


	Person* personAddress = populationList.at(findPersonIndex(person_id));	// Get root person's address via their ID
	// Do breadth-first graph traversal
	bool seen = new bool[populationList.size()];					// Initialize list of people that have been scanned for positive cases
	seen = { false };												// Currently none have been scanned, so everything's false
	queue<Person*> toVisit;											// Queue of people who haven't been scanned yet

	toVisit.push(personAddress);									// Add the first person to to-visit queue

	while (!toVisit.empty()) {													// While there are still people to visit
	Person* curPerson = toVisit.front();										// Copy front of queue to temp address
	toVisit.pop();																// And remove from queue

		for (int index; index < curPerson->contactList.size(); index++) {		// Going through this person's contact list
			Person* personAtIndex = curPerson->contactList.at(index).contact;
			if (!wasSeen(seen, personAtIndex)) {								// TODO: <-
				toVisit.push(personAtIndex);									//       <- gotta fix these lines later lol
				seen[index] = true;												//       <-
			}
		}
	}
}
