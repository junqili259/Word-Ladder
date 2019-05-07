/*
Jun Qi Li
CSCI 235
hpp file for WordLadder class
*/
#ifndef WORD_LADDER_HPP
#define WORD_LADDER_HPP

#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using std::string;

class WordLadder
{
private:
std::vector<string> used_words;//vector of used words 
std::vector<string> lexicon;//contains all words read from file
    
public:
//reads and inserts words into lexicon vector
void readLexicon(string input_file);

//checks if the new word was used before
bool checkUsed(string new_word);

//returns a vector containing the word ladder from start_word to end_word if found
//returns an empty vector if no possible ladder found
std::vector<string> findShortestLadder(string start_word, string end_word);

};









#endif