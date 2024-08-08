#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include <iterator>
using namespace std;
#pragma once

class WordEntry {
	friend class HashTable;
	private:
		string word;
		int numAppearances;
		int totalScore;
	public:
		WordEntry(const string&, int);
		void addNewAppearance(int);
		const string& getWord();
		double getAverage();
};

#endif