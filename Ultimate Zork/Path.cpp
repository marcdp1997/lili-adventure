#include "Path.h"

Path::Path(const char* name, const char* description, Room* source, Room* destination, const char* direction, Status door) : 
Entity(name, description, PATH), 
source(source), destination(destination), door(door), direction(direction)
{}

Path::~Path()
{}

