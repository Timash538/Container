#include "IntArray.h"
#include <exception>
#include <iostream>
#include <stdint.h>

#define MAX_SIZE INT32_MAX/4



IntArray::IntArray()
{
	_length = SIZE;
	_data = new int*[_length];
	for (int i = 0; i < _length; i++) _data[i] = nullptr;
}

IntArray::IntArray(int length)
{
	if (length < 1 || length > MAX_SIZE) throw std::bad_array_new_length();
	_length = length;
	_data = new int*[_length];
	for (int i = 0; i < _length; i++) _data[i] = nullptr;
}

IntArray::IntArray(const IntArray& intArray)
{
	_length = intArray.getLength();
	_data = new int*[_length];
	for (int i = 0; i < _length; i++)
	{
		if (intArray[i])
			_data[i] = new int(*intArray[i]);
		else
			_data[i] = nullptr;
	}
}

IntArray::~IntArray()
{
	for (int i = 0; i < _length; i++) delete _data[i];
	delete[] _data;
}

void IntArray::push(int x, Order ord)
{
	if (ord == Order::BEGINNING) // вставл€ем элемент в начало
	{
		if (!_data[0])
		{
			pushAt(0, x);
		}
		else if (_data[_length - 1]) 
		{
			resize(1);
			
		}

		moveElementsRight();
		pushAt(0, x);

	}
	else                        // вставл€ем элемент в конец
	{

		if (_data[_length - 1])
		{
			resize(1);
		}

		pushAt(_length - 1, x);
	}
}

void IntArray::pushAt(int i, int x)
{
	if (i <0 || i >= _length) throw std::bad_variant_access();
	if (_data[i]) delete _data[i];
	_data[i] = new int(x);

}

bool IntArray::isFull()
{
	for (int i = 0; i < _length; i++) if (_data[i] == nullptr) return false;
	return true;
}

bool IntArray::isEmpty()
{
	for (int i = 0; i < _length; i++) if (_data[i]) return false;
	return true;
}

int IntArray::getElement(int i)
{
	if (_data[i] == nullptr)  throw std::bad_variant_access();
	return *_data[i];
}

int* IntArray::operator[](int i) const 
{
	if (i < 0 || i > _length) throw std::bad_variant_access();
	return _data[i];
}

void IntArray::clear()
{
	for (int i = 0; i < _length; i++) delete _data[i];
	delete[] _data;
}

void IntArray::moveElementsRight() //сдвинуть элементы вправо
{
	for (int i = _length; i > 0; i--)
	{
		if (_data[i - 1])
		{
			if (_data[i]) delete _data[i];
			_data[i] = new int(*_data[i - 1]);
			_data[i - 1] = nullptr;
		}
	}
}

int IntArray::getLength() const
{
	return _length;
}

void IntArray::resize(int slotsToAdd = ADDSLOTS)
{
	if (_length + slotsToAdd > MAX_SIZE || slotsToAdd < 1) throw std::bad_array_new_length();

	int **arr = new int*[_length];

	for (int i = 0; i < _length; i++)
	{
		if (_data[i])
			arr[i] = new int(*_data[i]);
		else arr[i] = nullptr;
	}

	clear();

	_length += slotsToAdd;
	_data = new int* [_length];

	for (int i = 0; i < _length; i++)
	{
		if (i < _length - slotsToAdd)
		{
			_data[i] = arr[i];
		}
		else
			_data[i] = nullptr;
	}
}

void IntArray::show()
{
	if (isEmpty())
	{
		std::cout << "ѕустой массив" << std::endl;
		return;
	}
	for (int i = 0; i < _length; i++)
	{
		if (_data[i]) std::cout << "Ёлемент " << i << " : " << *_data[i] << std::endl;
		else std::cout << "Ёлемент " << i << " : " << "ѕусто" << std::endl;
	}
}

void IntArray::deleteAt(int i)
{
	if (i < 0 || i >= _length) throw std::bad_variant_access();
	if (!_data[i]) std::cout << "ѕустой элемент!" << std::endl;
	else
	{
		delete _data[i];
		_data[i] = nullptr;
	}
}

bool IntArray::find(int x, int &index)
{
	for (int i = 0; i < _length; i++)
		if (_data[i])
			if (*_data[i] == x)
			{
				index = i;
				return true;
			}
	return false;
}

