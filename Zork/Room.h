class Room{

public:
	int id;
	char name[20];
	char description[200];
	int north;
	int south;
	int west;
	int east;

public:
	void CreateRooms(int num);
};
