#ifndef VECTOR_H
#define VECTOR_H

template <class TYPE>
#define uint unsigned int
#define BLOCK 10 //num of capacity

class Vector
{
public:
	TYPE* buffer;
	uint capacity;
	uint num_elements;

public:
	Vector()
	{
		capacity = BLOCK;
		buffer = new TYPE[capacity];
		num_elements = 0;
	}

	Vector(const Vector& v)
	{
		capacity = v.capacity;
		buffer = new TYPE[v.capacity];
		num_elements = v.num_elements;
		for (uint i = 0; i < num_elements; i++) buffer[i] = v.buffer[i];
	}

	~Vector()
	{
		delete[] buffer;
	}

	void pushback(const TYPE num)
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

		buffer[num_elements] = num;
		num_elements++;
	}

	void pushfront(const TYPE num)
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
		buffer[0] = num;
		num_elements++;
	}
};

#endif //VECTOR_H