#pragma once

#define SIZE 10
#define ADDSLOTS 10

enum Order {BEGINNING, END};

class IntArray
{
public:
	IntArray();
	IntArray(int);
	IntArray(const IntArray &intArray);
	~IntArray();

	void push(int, Order);
	void pushAt(int, int);
	bool isFull();
	bool isEmpty();
	int getElement(int);
	int* operator[](int at) const;
	int getLength() const;
	void resize(int);
	void show();
	void deleteAt(int);
	bool find(int x, int &index);

private:
	int _length;
	int** _data;

	void clear();
	void moveElementsRight();
};


