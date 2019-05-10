/*
Jun Qi Li
CSCI 235
Project 5
Finding the shortest word ladder
*/
#include"WordLadder.hpp"
#include<queue>
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<algorithm>
using std::string;


//reads and inserts words into lexicon vector
void WordLadder::readLexicon(string input_file){
	std::ifstream lexicon_file;
	string word;

	lexicon_file.open(input_file);

	if (lexicon_file.fail())//if file doesn't open
	{
		exit(1);
	}
	else
		while(!lexicon_file.eof()){
			std::getline(lexicon_file, word);
			lexicon.push_back(word);//insert word into lexicon 
		}
		lexicon_file.close();//close input_file after finished reading
}

//return true if not used, false otherwise
//checks if the word was used before or not
bool WordLadder::checkUsed(string new_word)
{
	if (used_words.empty())
	{
		return true;
	}
	else
		//checking new_word and words in used_words character by character
		for (int i = 0; i < used_words.size(); i++)
		{
			if (new_word != used_words[i])//if different words, then new_world is not used yet and return true
			{
				return true;
			}
		}
		return false;
}

//return a vector containing shortest path from start_word to end_word
std::vector<string> WordLadder::findShortestLadder(string start_word, string end_word){
    
	std::queue<std::vector<string> > ladders;//queue to store ladders
	
	std::vector<string> partial_ladder;
	partial_ladder.push_back(start_word);//ladder containing only the start_word
	
	ladders.push(partial_ladder);//push ladder containing only start_word into queue
	while (!ladders.empty())
	{
		std::vector<string> first_ladder = ladders.front();//current ladder, oldest in queue
		string last_word = first_ladder.back();//last element in current ladder and assign to last_word
		ladders.pop();//dequeue the ladder

		//if end_word is found at end of current ladder
		if (last_word == end_word)
		{
			return first_ladder;
		}
		for (int i = 0; i < last_word.size(); i++)
		{
			//generates all words 1 letter away for last_word
			for (char j = 'a'; j <= 'z'; j++)
			{
				string word_copy = last_word;
				word_copy[i] = j;
				
				//if new generated word is found in lexicon and not in used words
				if(binary_search(lexicon.begin(), lexicon.end(), word_copy) && checkUsed(word_copy))
				{
					//add the word to the vector of used words
					used_words.push_back(word_copy);
					std::vector<string> ladder_copy = first_ladder;//copy of vector
					ladder_copy.push_back(word_copy); //add word into ladder
					ladders.push(ladder_copy);//insert new ladder into queue
				}
			}
		}
	}
	//if no ladder exist
	std::vector<string> v;
	return v;
}