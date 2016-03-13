#ifndef PATH_H
#define PATH_H

class Path{

public:
	int id;
	char description[200];
	bool open;
	int source;
	int destination;

public:
	void CreatePaths(int num);
};

#endif