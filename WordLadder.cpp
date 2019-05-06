#include"WordLadder.hpp"
#include<queue>
#include<vector>
#include<string>
#include<fstream>
#include<iostream>
using std::string;



void WordLadder::readLexicon(string input_file){
	std::ifstream lexicon_file;
	string word;

	lexicon_file.open(input_file);

	if (lexicon_file.fail())
	{
		std::cerr << "Cannot read from file" << std::endl;
	}
	else
		while(!lexicon_file.eof()){
			std::getline(lexicon_file, word, '\n');
			lexicon.push_back(word);
		}
		/*
		for (int i = 0; i < lexicon.size(); i++)
		{
			std::cout << lexicon[i];
		}
		*/
}

std::vector<string> WordLadder::findShortestLadder(string start_word, string end_word){
    
}