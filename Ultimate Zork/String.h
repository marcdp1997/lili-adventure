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
	String(const char* str); // For C strings
	~String();

	unsigned int Length() const;
	void GetString();

	bool String::operator== (const char *other) const; // For C strings
	bool String::operator!= (const char *other) const; // For C strings
	const String& String::operator= (const char* str); // For C strings
};

#endif