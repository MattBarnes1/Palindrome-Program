//FIFO
#include "queue.hpp"
#include <cassert>
#include <cctype>
#include <string>

void queue::enqueueLoop(SQStructure * myStructure, char c)
{
		if (myStructure->nxt)
		{
			enqueueLoop(myStructure->nxt, c);
		}
		else
		{
			count++;
			myStructure->nxt = new SQStructure(c);
		}
}

void queue::recurseStringLoop(int CurrentPosition, int &maxSize, std::string currentString)
{
	if (CurrentPosition == maxSize)
	{
		return;
	}
	else if (isalnum(currentString[CurrentPosition]))
	{
		enqueue(toupper(currentString[CurrentPosition]));
		recurseStringLoop(++CurrentPosition, maxSize, currentString);
		count++;
	}
	else {
		recurseStringLoop(++CurrentPosition, maxSize, currentString);
	}
}


void queue::enqueue(char c)
{
	if (list)
	{
		enqueueLoop(list, c);
	}
	else {
		list = new SQStructure(c);
	}
}



void queue::clear()
{
	if (!isEmpty())
	{
		dequeue();
		clear();
	}
}

bool queue::isEmpty()
{
	return (!list);
}



char queue::dequeue()
{
	if (list)
	{
		char mylistItem = list->internalCharacter;
		SQStructure *nxtPtr = list->nxt;
		list->nxt = 0;
		delete list;
		list = nxtPtr;
		count--;
		return mylistItem;
	}
		
	return '\0';
}


void queue::recurseString(std::string cString)
{
	int Size = cString.length();
	recurseStringLoop(0, Size, cString);
}