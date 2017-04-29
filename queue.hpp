
#include <cassert>
#include "SQStructure.hpp"
#include <cctype>
#include <string>

class queue
{
private:
	SQStructure *list = nullptr;
	int count = 0;
	void enqueueLoop(SQStructure *myStructure, char c);
	void recurseStringLoop(int CurrentPosition, int &maxSize, std::string currentString);
public:
	void enqueue(char c);
	char dequeue();
	void recurseString(std::string);
	void clear();
	bool isEmpty();
};