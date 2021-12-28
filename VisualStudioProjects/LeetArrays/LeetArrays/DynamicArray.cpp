#include <cassert>
class DynamicArray
{
private:
	int _size;
	int _maxSize;
	int* _arrayHolder;

public:
	DynamicArray()
	{
		this->_size = 0;
		this->_maxSize = 5;
		this->_arrayHolder = new int[];
	}

	~DynamicArray()
	{
		delete[] this->_arrayHolder;
	}

	int size() {
		return this->_size;
	}

	int& operator[](int i)
	{
		assert(i < this->_size);
		return this->_arrayHolder[i];
	}

	int add(int x)
	{
		if (this->_maxSize > this->_size)
		{
			this->_arrayHolder[this->_size] = x;
			this->_size++;
		}
		else
		{
			this->_maxSize *= 2;
			int* _temp = new int[_maxSize];

			for (int i = 0; i < this->_size; i++)
				_temp[i] = this->_arrayHolder[i];

			delete[] this->_arrayHolder;
			this->_arrayHolder = _temp;
			
			this->_arrayHolder[this->_size] = x;
			this->_size++;
		}
	}

};