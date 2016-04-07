#include <stdio.h>
#include <assert.h>
#include "String.h"

#define BUFFER 20

String::String()
{
	string = new char[BUFFER];
	string[0] = '\0';
	mem_size = BUFFER;
}

String::String(const char* other)
{
	assert(other != NULL);
	string = new char[strlen(other) + 1];
	strcpy_s(string, strlen(other) + 1, other);
	mem_size = Length() + 1;
}

String::~String()
{
	delete[] string;
}

unsigned int String::Length() const
{
	return strlen(string);
}

void String::GetString()
{
	printf("> ");
	fgets(string, mem_size, stdin);
}

bool String::operator== (const char *other) const
{
	if (strcmp(string, other)) return 0;
	else return 1;
	// If it's 1 they are defferent.
}

bool String::operator!= (const char *other) const
{
	if (strcmp(string, other)) return 1;
	else return 0;
}

const String& String::operator= (const char *other)
{
	if (mem_size < strlen(other) + 1)
	{
		delete[] string;
		string = new char[strlen(other) + 1];
		mem_size = Length() + 1;
	}
	strcpy_s(string, strlen(other) + 1, other);

	return *this;
}

