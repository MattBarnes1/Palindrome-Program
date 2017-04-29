// ADT - Project2.cpp : Defines the entry point for the console application.
//

#include "queue.hpp"
#include "stack.hpp"
#include <string>
#include <iostream>

stack anInternalStack;
queue anInternalQueue;

std::string doPrompt()
{
	std::string aString = "";
	//std::cout << "Please Enter a String:";
	getline(std::cin, aString);
	return aString;
}

int checkDifferences()
{
	if (anInternalQueue.isEmpty() || anInternalStack.count() == 0)
	{
		return -1;
	}
	char a = anInternalQueue.dequeue();
	char b = anInternalStack.peek();
	if (a != b)
	{
		return anInternalStack.getDifferenceFromStart();
	}
	else
	{
		anInternalStack.pop();
		checkDifferences();
	}
}



int main(int argc, char* argv[])
{
	std::string aStringToSplit = "";
	while (true)
	{
		aStringToSplit = doPrompt();
		if (aStringToSplit == "q") break;
		anInternalStack.recurseString(aStringToSplit);
		anInternalQueue.recurseString(aStringToSplit);
		int Difference = checkDifferences();
		std::cout << Difference << std::endl;
		anInternalQueue.clear();
		anInternalStack.clear();
		assert(anInternalQueue.isEmpty());
		assert(anInternalStack.count() == 0);
		aStringToSplit = "";
	};

	return 0;
}



