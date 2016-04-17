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

void String::Tokenize(Vector<String>& tokens)
{
	printf("> ");
	fgets(string, mem_size, stdin);

	int num_words = 1;

	for (int i = 0; string[i] != '\0'; i++)
	{
		if ((string[i] > 'A') && (string[i] < 'Z')) string[i] = string[i] + 32;
		if (string[i] == ' ') num_words++;
	}

	char aux[20];
	strcpy_s(aux, 20, string);

	for (int i = 1; i <= num_words; i++)
	{
		int word = 0;
		for (int j = 0; aux[j] != '\0'; j++)
		{
			if ((aux[j] == ' ') || (aux[j] == '\n'))
			{
				word++;

				if (word == i)
				{
					aux[j] = '\0';
					break;
				}
				else
				{
					int i2, j2;
					for (i2 = 0, j2 = j + 1; aux[j2] != '\n'; i2++, j2++) 
						aux[i2] = aux[j2];
					aux[i2] = '\0';
				}
			}
		}
		tokens.buffer[i - 1] = aux;
		strcpy_s(aux, 20, string);
	}
}

bool String::operator== (const char *other) const
{
	if (strcmp(string, other)) return 0;
	else return 1;
}

bool String::operator== (const String& other) const
{
	if (strcmp(string, other.string)) return 0;
	else return 1;
}

bool String::operator!= (const char *other) const
{
	if (strcmp(string, other)) return 1;
	else return 0;
}

bool String::operator!= (const String& other) const
{
	if (strcmp(string, other.string)) return 1;
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

