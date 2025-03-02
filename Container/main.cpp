#include <iostream>
#include "IntArray.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	try
	{
		//Создаем массив с - или слишком большого размера:
		//IntArray wrongArr = IntArray(-2);
		//IntArray wrongArr2 = IntArray(999999999999);
		
		//Создаем и заполняем:
		IntArray a = IntArray(2); 
		a.pushAt(0, 4);
		a.pushAt(1, 5);
		a.push(8, Order::END);
		a.push(3,Order::BEGINNING);
		a.push(10,Order::END);

		//Пробуем выйти за пределы массива/изменить размер на некорректный:
		//a.pushAt(100, 5);
		//a.pushAt(-100, 5);
		//a.deleteAt(-100);
		//a.deleteAt(100);
		//a.resize(0);
		//a.resize(999999999999999);
		//a.resize(-1);
		//a.getElement(1);

		//Работа поиска:
		int index = 0;
		int x = 5;
		if (a.find(x, index)) cout << "Индекс элемента содержащего " << x << " : " << index << endl << endl;
		else cout << "Элемент не найден" << endl << endl;

		cout << a.getElement(1) << endl << endl;

		a.show();
		cout << endl;

		a.deleteAt(3);

		IntArray b(a);
		b.show();
		cout << endl;

		a.deleteAt(2);
		a.resize(3);

		a.show();
		cout << endl;
		
		
	}
	catch (exception& e)
	{
		cout << "Exception Caught: " << e.what();
	}
	return 0;
}