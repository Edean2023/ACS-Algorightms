#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable {
private:
	// number of hashgroups
	static const int hashGroups = 10;
	// create list
	list<pair<int, string>> table[hashGroups];

public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();

};

// check if the hashtable is empty
bool HashTable::isEmpty() const {
	int sum{};
	// go over each hashgroup to see if it is empty
	for (int i{}; i < hashGroups; i++) {
		sum += table[i].size();
	}
	if (!sum) {
		return true;
	}
	return false;
}
// return a value 0-9
int HashTable::hashFunction(int key) {
	return key % hashGroups; 
}

// insert item into the hashtable 
void HashTable::insertItem(int key, string value) {
	int hashValue = hashFunction(key); 
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	// If the key exists, replace the value of the key with the new input
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr->second = value;
			cout << "Key exists. Value replaced." << endl;
			break;
		}
	}

	// push the key value pair if the key doesn't exist
	if (!keyExists) {
		cell.emplace_back(key, value);
	}
	return;
}

// remove items from the hashtable
void HashTable::removeItem(int key){
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	// If the key exists, remove the key value pair
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "Item removed." << endl;
			break;
		}
	}
	if (!keyExists) {
		cout << "Item not found. Pair has not been removed." << endl;
	}

	return;
}

// print everything
void HashTable::printTable() {
	for (int i{}; i < hashGroups; i++) {
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "Key: " << bItr->first << " Value: " << bItr->second << endl;
		}
	}
	return;
}

int main() {
	HashTable HT;

	if (HT.isEmpty()) {
		// notify the user that the table started empty
		cout << "Table is empty." << endl;
	}
	else {
		// notify user that the table did not start empty and that something is wrong
		cout << "[WARNING] Table not empty." << endl;
	}

	// List of residence and their room numbers
	HT.insertItem(151, "Eliot");
	HT.insertItem(952, "Tim");
	HT.insertItem(185, "John");
	HT.insertItem(269, "Sam");
	HT.insertItem(705, "Julia");
	HT.insertItem(471, "Kate");
	// test for duplicate numbers
	HT.insertItem(471, "James");

	HT.printTable();

	// remove John
	HT.removeItem(185);
	// test removing and item that doesn't exist
	HT.removeItem(999);

	HT.printTable();
	if (HT.isEmpty()) {
		cout << "Hashtable has had more items removed added than removed." << endl;
	}
	else {
		cout << "Hashtable Complete" << endl;
	}
	return 0;
}