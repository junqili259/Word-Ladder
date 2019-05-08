#include"WordLadder.hpp"
#include<queue>
#include<vector>
#include<string>
#include<fstream>
#include<iostream>

int main(){
	WordLadder object;
	object.readLexicon("4LetterWordsReduced.dat");
	object.findShortestLadder("this", "that");
	std::cout << std::endl;

	object.findShortestLadder("ford", "lost");

	return 0;
}