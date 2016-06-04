#ifndef PLAYER_H
#define PLAYER_H

#define INV_CAPACITY 5

#include "Creature.h"

class Room;
class Item;

class Player : public Creature
{
public:
	// Items that can be equipped 
	Item* clothes = nullptr; 
	Item* shield = nullptr; 
	Item* weapon = nullptr; 

public: 
	Player(const char* name, const char* description, Room* creature_pos);
	virtual ~Player();

	bool Move(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	bool Look(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	bool Pick(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	bool Drop(const Vector <String>& tokens, const Vector<Entity*>& Entities);
	bool Equip(const Vector <String>& tokens);
	bool Unequip(const Vector <String>& tokens);
	bool CheckDoor(const Vector<Entity*>& Entities) const;
	void Door(const enum Status& door, const Vector<Entity*>& Entities);
	void Inventory(const Vector <String>& tokens) const;
	bool Bag() const;
	bool PutInto(const Vector <String>& tokens);
	bool GetFrom(const Vector <String>& tokens);
	bool TurnOnGPS(const Vector<Entity*>& Entities) const;
	void Update(const Vector<Entity*>& Entities);
};

#endif