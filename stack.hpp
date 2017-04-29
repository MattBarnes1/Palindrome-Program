#include <cassert>
#include "SQStructure.hpp"
#include <string>

class stack
{
private:
	SQStructure *list = nullptr;
	SQStructure *top = nullptr;
	int countval = 0;
	void recurseStringLoop(int CurrentPosition, int &maxSize, std::string String);
	void popHelp(SQStructure *aStruct);
	int max = 0;
public:
	void push(char c);
	void pop();
	char peek();
	void recurseString(std::string);
	int count();
	int getDifferenceFromStart();
	void clear();
};