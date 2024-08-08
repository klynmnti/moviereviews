#include "WordEntry.h"

/* WordEntry contructor */
// private data members are set to parameter values
WordEntry::WordEntry(const string&text, int score)
 : word(text), numAppearances(1), totalScore(score) {}
/* addNewAppearance */
// increases total score by parameter s
// increments number of appearances by 1
void WordEntry::addNewAppearance(int s) {
	totalScore += s;
	++numAppearances;
}
/* getWord */
// returns the word entry object's word
const string& WordEntry::getWord() { return word; }
/* getAverage */
// computes average of word entry object
double WordEntry::getAverage() { return static_cast<double>(totalScore) / numAppearances; }