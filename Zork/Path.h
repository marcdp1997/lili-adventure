#ifndef PATH_H
#define PATH_H

class Path{
public:
	int id;
	char description[200];
	char door[10]; // Here I will use: opened, closed or no_door.
	int source;
	int destination;

public:
	void CreatePaths(int num);
};

#endif