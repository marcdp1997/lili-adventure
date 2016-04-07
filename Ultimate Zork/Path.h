#ifndef PATH_H
#define PATH_H

#include "String.h"

class Path{
public:
	int id;
	String description;
	int door; // No door == 0, opened == 1, closed == 2;
	int source;
	int destination;

public:
	void CreatePaths(const int num);
};

#endif