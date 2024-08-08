#include "HashTable.h"

/* HashTable constructor */
// sets size to parameter s
// allocates memory for hash table
HashTable::HashTable (int s) {
    size = s;
    hashTable = new list<WordEntry>[size];
}
/* computeHash */
// returns the array index of list where s belongs
// converts each value of s into an integer and adds
// modulo total integer value by hash table size
int HashTable::computeHash(const string& s) {
    int value = 0;
    for (unsigned i = 0; i < s.length(); i++) {
        value += static_cast<int>(s[i]);
    }
    return value % size; 
}
/* put */
// first sees if s already exists in hash table
// then finds array index of list where s belongs
// uses iterator to go through each element in list
// finds the matching word in element and add new appearance
// otherwise if s does not exist, create WordEntry object and push back
void HashTable::put(const string& s, int score) {
    int ind = computeHash(s);
    list<WordEntry>::iterator i; 
    for (i = hashTable[ind].begin(); i != hashTable[ind].end(); i++) { 
        if (i->getWord() == s) { break; }
    }
    while (i != hashTable[ind].end()) { 
        if (i->getWord() == s) {
            i->addNewAppearance(score);
            return;
        }
        i++;
    }
    WordEntry we(s, score);
    hashTable[ind].push_back(we);
}
/* getAverage */
// first find if element exists
// find array index where s belongs & iterate through list
// then return the average of i (WordEntry object)
// otherwise return 2.0 (neutral value)
double HashTable::getAverage(const string& s) {
    int ind = computeHash(s);
    list<WordEntry>::iterator i; 
    for (i = hashTable[ind].begin(); i != hashTable[ind].end(); i++) { 
        if (i->getWord() == s) { break; }
    }
    if (i != hashTable[ind].end()) { 
        if (i->getWord() == s) { return i->getAverage(); }
        i++;
    }
    return 2.0;
}
/* contains */
// finds array index of list where s belongs
// then use iterator to find list element with s
// if s is found, return true
// otherwise return false
bool HashTable::contains(const string& s) {
    int ind = computeHash(s);
    list<WordEntry>::iterator i; 
    for (i = hashTable[ind].begin(); i != hashTable[ind].end(); i++) { 
        if (i->getWord() == s) { break; }
    } 
    if (i != hashTable[ind].end()) { 
        if (i->getWord() == s) { return true; }
        i++;
    } 
    return false;
}
