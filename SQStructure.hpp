#ifndef SQSTRUCT
#define SQSTRUCT
struct SQStructure
{
	SQStructure *nxt = 0;
	char internalCharacter;
	SQStructure(char c) : internalCharacter(c)
	{
	}
};

#endif // !SQSTRUCT

