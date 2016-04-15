#ifndef PATH_H
#define PATH_H

#include "Base.h"

enum coords {north, south, east, west};

class Path : public Base
{
public:
	int door; // No door == 0, opened == 1, closed == 2;
	int source;
	int destination;
	enum coords direction;

public:
	void CreatePaths(const int num);
};

#endif