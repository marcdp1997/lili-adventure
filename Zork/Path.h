#include "Room.h"

class Path{

public:
	int id;
	char name[20];
	char description[200];
	bool open;
	int source;
	int destination;

public:
	void CreatePaths(int num);
};