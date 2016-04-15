#include "Entity.h"

Entity::Entity(const char* name, const char* description, Entity_type type) : name(name), description(description), type(type)
{}

Entity::~Entity()
{}