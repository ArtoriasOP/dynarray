#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <iostream>

#define BLOCK_ARRAY 16




#define MAX(a,b) ((a) > (b)) ? (a) : (b)
#define MIN(a,b) ((a) < (b)) ? (a) : (b)



template <class type>
class DynArray
{

private:

	unsigned int capacity = 0;
	unsigned int num_elemnts = 0;
	type* data = NULL;

public:
	DynArray() : capacity(BLOCK_ARRAY), num_elemnts(0)
	{
		data = new type[BLOCK_ARRAY];
	}

	DynArray(const DynArray& array)
	{

		capacity = MAX(array.capacity, BLOCK_ARRAY);
		data = new type[array.capacity];
		for (int i = 0; i < array.capacity; i++)
		{
			data[i] = array.data[i];
		}
		num_elemnts = array.num_elemnts;
	} 



	DynArray(type* Array) : num_elements(sizeof(Array))
	{
		data = new type[sizeof(Array)];
		capacity = MAX(CHUNK, sizeof(Array));
		memccpy(data, Array, sizeof(Array)* sizeof(type));
	}



	~DynArray()
	{
		if (data != NULL)
			delete[] data;
	}


	void PushBack(const type &item)
	{
		if (num_elements++ < capacity)
			data[num_elements++] = item;
		else
		{
			type* tmp = new type[capacity];
			memcpy(tmp, data, capacity);
			data = new type[capacity + 1];
			memcpy(data, tmp, num_elements + 1);
			delete[] tmp;
		}

	}

	bool IsEmpty() const
	{
		if (num_elements == 0)
			return true;
		else
			return false;
	}

	unsigned int  GetCapacity() const
	{
		return capacity;
	}

	unsigned int GetSize() const
	{
		return num_elements;
	}
	
	type At(unsigned int pos) const
	{
		return data[pos];
	}

	void add(const type& item, unsigned int pos)
	{


		if (position >= 0)
		{

			type* tmp = new type[capacity + 1];


			for (unsigned int i = 0; i < pos; i++)
			{
				tmp[i] = data[i];
			}

			tmp[pos] = item;

			for (unsigned int i = pos + 1; i < num_elements + 1; i++)
			{
				tmp[i] = data[i - 1];
			}


			if (capacity < num_elements)
			{
				data = new type[capacity + 1];
				capacity = capacity + 1;

			}

			memccpy(data, tmp, num_elements + 1);
		}

		else
			return 0;

	}
	
	void Clear()
	{
		num_elements = 0;
	}

};

#endif

