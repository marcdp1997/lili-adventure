#ifndef STRING_H
#define STRING_H

#include <string.h>

class String
{
public:
	char* string;
private:
	unsigned int mem_size;
public:
	String();
	String(const char* str); 
	~String();

	unsigned int Length() const;
	void GetString();
	void GetWord(const int from);  // This fcn cuts a string

	bool String::operator== (const char *other) const; 
	bool String::operator== (const String& other) const;
	bool String::operator!= (const char *other) const;
	const String& String::operator= (const char* str); 
};

#endif