#ifndef VECTOR_H
#define VECTOR_H

#include <assert.h>
#include "String.h"

template <class TYPE>
#define uint unsigned int
#define BLOCK 50

class Vector
{
public:
	TYPE* buffer;
	uint capacity;
	uint num_elements = 0;

public:
	Vector()
	{
		capacity = BLOCK;
		buffer = new TYPE[capacity];
	}

	Vector(const Vector& v)
	{
		capacity = v.capacity;
		buffer = new TYPE[v.capacity];
		num_elements = v.num_elements;
		for (uint i = 0; i < num_elements; i++) buffer[i] = v.buffer[i];
	}

	Vector(uint size) : capacity(size)
	{
		buffer = new TYPE[capacity];
	}

	virtual ~Vector()	
	{
		delete[] buffer;
	}

	void pushback(const TYPE& data)
	{
		TYPE* aux;
		if (num_elements == capacity)
		{
			capacity += 10;
			TYPE* aux = new TYPE[capacity];
			for (int i = 0; i < num_elements; i++) aux[i] = buffer[i];
			delete[] buffer;
			buffer = aux;
		}

		buffer[num_elements] = data;
		num_elements++;
	}

	void pushfront(const TYPE& data)
	{
		if (num_elements == capacity)
		{
			capacity += 10;
			TYPE* aux = new TYPE[capacity];
			for (int i = 0; i < num_elements; i++) aux[i] = buffer[i];
			delete[] buffer;
			buffer = aux;
		}

		for (int i = num_elements; i > 0; i--) buffer[i] = buffer[i - 1];
		buffer[0] = data;
		num_elements++;
	}

	bool popback(TYPE& data)
	{
		if (num_elements > 0)
		{
			data = buffer[--num_elements];
			return true;
		}
		else return false;
	}

	bool popfront(TYPE& data)
	{
		if (num_elements > 0)
		{
			data = buffer[0];
			for (int i = 0; i < num_elements; i++) buffer[i] = buffer[i + 1];
			num_elements--;
			return true;
		}
		else return false;
	}

	void pop(const uint num)
	{
		if (num_elements > 0)
		{
			for (int i = num; i < num_elements; i++) buffer[i] = buffer[i + 1];
			num_elements--;
		}
	}

	TYPE& operator[] (uint index)
	{
		assert(index < num_elements);
		return buffer[index];
	}

	const TYPE& operator[] (uint index) const
	{
		assert(index < num_elements);
		return buffer[index];
	}

	void Clean() const
	{
		for (int i = num_elements - 1; i >= 0; --i)
			delete buffer[i];
	}

	// Empty, size, capacity, at(), shrink_to_fit();
};

#endif //VECTOR_H