#include "stack.hpp"
#include <ctype.h>
#include <string>

void stack::pop()
{
	if (list)
	{
		if (list->nxt)
		{
			popHelp(list);
		}
		else {
			delete list;
			top = 0;
			list = 0;
		}
		countval--;
	}
}


void stack::popHelp(SQStructure *aStruct)
{
	if (aStruct->nxt == top)
	{
		delete top;
		top = aStruct;
		aStruct->nxt = 0;
	}
	else {
		popHelp(aStruct->nxt);
	}
}

char stack::peek()
{
	if (top) 
	{
		return top->internalCharacter;
	}
	else {
		return '\0';
	}
}


int stack::getDifferenceFromStart()
{
	return max - countval;
}


void stack::recurseStringLoop(int CurrentPosition, int &maxSize, std::string currentString)
{
		if (CurrentPosition == maxSize)
		{
			return;
		}
		else if (isalnum(currentString[CurrentPosition]))
		{
			push(toupper(currentString[CurrentPosition]));
			recurseStringLoop(++CurrentPosition, maxSize, currentString);
			countval++;
		}
		else {
			recurseStringLoop(++CurrentPosition, maxSize, currentString);
		}
	
}

void stack::push(char c)
{
	assert(top || !list); //If either of these are defined while the other isn't, this is an error
	assert(!top || list);
	if (top)
	{
		top->nxt = new SQStructure(c);
		top = top->nxt;
	}
	else {
		list = new SQStructure(c);
		top = list;
	}
}

void stack::clear()
{
	if (count() != 0)
	{
		pop();
		clear();
	}
}

int stack::count()
{
	return countval;
}


void stack::recurseString(std::string cString)
{	
	int Size = cString.length();
	recurseStringLoop(0, Size, cString);
	max = countval;
}
