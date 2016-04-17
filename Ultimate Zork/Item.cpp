#include "Item.h"

Item::Item(const char* name, const char* description, Room* location, int num) : 
Entity(name, description, ITEM),
location(location), equip(num)
{}

Item::~Item()
{}