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

int Graph::count_virus_positive_contacts(string person_id) {
	Person* personAddress = populationList.at(findPersonIndex(person_id));	// Get root person's address via their ID
	// Do breadth-first graph traversal
	int numPositive = 0;
	const int listLength = populationList.size();
	vector<bool> seen(listLength, false);							// Keep track of who's been scanned
	queue<Person*> toVisit;											// Queue of people who haven't been scanned yet

	toVisit.push(personAddress);									// Add the first person to to-visit queue

	while (!toVisit.empty()) {													// While there are still people to visit
	Person* curPerson = toVisit.front();										// Copy front of queue to temp address
	toVisit.pop();																// And remove from queue

		for (int index = 0; index < curPerson->contactList.size(); index++) {		// Going through this person's contact list
			Person* personAtIndex = curPerson->contactList.at(index).contact;
			int personIndex = findPersonIndex(personAtIndex->ID);
			if (seen.at(personIndex) == false) {								// If the person hasn't been scanned yet, then
				toVisit.push(personAtIndex);									// Add them to the toVisit list
				seen.at(personIndex) = true;

				if (personAtIndex->testResult == true)							// If person tested positive,
					numPositive++;												//	increase positive case count
			}
		}
	}
	return numPositive;
}
