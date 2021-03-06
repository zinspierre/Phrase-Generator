#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <time.h>
#include <stdlib.h>

//class representing a Word in a Text
class Word
{

struct Probability
{
	int counts;
	float proba;
	int start;
	int end;
};

public:
	Word() : word(""){}
	Word(std::string& str) : word(str){}

	//add sucessor word
	void addSuccessor(const std::string& _str);

	void print();
	int size();

	//computer probabilty for all successors
	void computeProba();

	//return the most probable word
	const std::string getBestSucc();

	std::map<std::string,  Probability> getSuccessors();

private:
	std::string word;
	//map possible successors // associated probability
	std::map<std::string, Probability> successors;

};


//Text object representing a real text
class Text
{
public:

	//add a word to the text
	void addWords(std::string& _word, const std::string& _succ);

	//return the map
	std::map<std::string, Word>& getMap();

	//computer proba for all words in the text
	void computeProba();

	//get best successor for word _str
	std::string getBestSucc(const std::string& _str);

	void print();
private:
	//map the text word // the object word
	std::map<std::string, Word> words;

};