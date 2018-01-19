#include <bits/stdc++.h>

using namespace std;

class HashTable {

private: 
	string* hashValues;
	string* hashKeys;
	int hashFunction(string key);
	int size;
	int prime;
	hash<string> hasher;
	int getNextPrime(int val);
	bool isPrime(int val);

public:
	bool add(string key, string value);
	string get(string key);
	bool remove(string key);
	int getSize();

	HashTable(int _size, int _prime = -1);
	// ~HashTable();
};

int HashTable::getNextPrime(int val) {
	int nextPrime = val;
    bool found = false;

    while (!found) {
        nextPrime++;
        if (isPrime(nextPrime))
            found = true;
    }

    return nextPrime;
}

bool HashTable::isPrime(int val) {
    for (int i = 2; i <= val/2; i++) {
        if (val % i == 0) 
            return false;
    }

    return true;
}

HashTable::HashTable(int _size, int _prime) {
	size = _size;

	prime = (_prime == -1 ? getNextPrime(size) : _prime);

	hashValues = new string[size];
	hashKeys   = new string[size];

	for(int i = 0; i < size; i++)
		hashValues[i] = "";
}

// HashTable::~HashTable() {
// 	delete hashValues;
// }

int HashTable::hashFunction(string key) {
	unsigned h = 37;
	unsigned A = 76963;
	unsigned B = 54059;

	for(char c : key) {
		h = (h * A) ^ (c * B);
	}

    return h % prime;
}

bool HashTable::add(string key, string value) {
	int id = hashFunction(key);
	int copyId = id;


	while(hashKeys[id] != "") {
		id = (id + 1) % size;

		if(id == copyId) return false;
	}

	hashKeys[id] = key;
	hashValues[id] = value;

	return true;
}

string HashTable::get(string key) {
	int id = hashFunction(key);
	int copyId = id;

	while(hashKeys[id] != key) {
		id = (id + 1) % size;

		if(id == copyId) return "";
	}

	return hashValues[id];
}

bool HashTable::remove(string key) {
	int id = hashFunction(key);
	int copyId = id;

	while(hashKeys[id] != key) {
		id = (id + 1) % size;

		if(id == copyId) return false;
	}

	hashKeys[id] = "";
	hashValues[id] = "";

	return true;
}

int HashTable::getSize() {
	return size;
}

int main() {



	HashTable hash = HashTable(100000);

	cout << "Size of hash is: " << hash.getSize() << endl;


	hash.add("A", "primeira letra do alfabeto");
	cout << hash.get("A") << endl;

	cout << hash.remove("A") << endl;
	cout << hash.get("A") << endl;

	return 0;
}

