#ifndef WORD_LADDER_HPP
#define WORD_LADDER_HPP

#include<queue>
#include<vector>
#include<string>

class WordLadder
{
private:
std::queue<string> ladders;
std::vector<string> used_words;
std::vector<string> lexicon;
    
public:
void readLexicon(string input_file);
std::vector<string> findShortestLadder(string start_word, string end_word);
};









#endif