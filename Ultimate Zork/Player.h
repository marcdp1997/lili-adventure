#ifndef PLAYER_H
#define PLAYER_H

#define INV_CAPACITY 4

#include "Entity.h"
class Room;
class Item;
class Path;

class Player : public Entity
{
public:
	Room* curr_pos;
	Item* equip_item = nullptr;

public: 
	Player(const char* name, const char* description, Room* curr_pos);
	virtual ~Player();

	void Move(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	void LookPath(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	void Pick(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	void Drop(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	void Equip(const Vector <String>& tokens);
	void Unequip(const Vector <String>& tokens);
	void Door(const enum Status& door, const Vector<Entity*>& Entities);
	void Update(const Path* p);
	void Inventory(const Vector <String>& tokens) const;
	void Bag() const;
	void PutInto(const Vector <String>& tokens);
	void GetFrom(const Vector <String>& tokens);
	void TurnOnGPS(const Vector<Entity*>& Entities);
};

#endif