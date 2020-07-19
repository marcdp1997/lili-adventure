#ifndef STRING_H
#define STRING_H

#include <string.h>
#include <conio.h>
#include "Vector.h"

class String
{
public:
	char* string;
private:
	unsigned int mem_size;
public:
	String();
	String(const char* str); 
	virtual ~String();

	unsigned int Length() const;

	bool operator== (const char *other) const; 
	bool operator== (const String& other) const;
	bool operator!= (const char *other) const;
	bool operator!= (const String& other) const;
	const String& operator= (const char* str); 
	void Tokenize(Vector<String>& tokens);
	void SlowPrint(unsigned int milis_per_char);
};

#endif