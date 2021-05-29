//Построить иерархию объектов игры GTA

#include<iostream>
using namespace std;

class Weapon         //Абстрактный класс
{
public:
	virtual void function() = 0;	//Чисто виртуальный метод 
};
class Firearms :public Weapon         //Тоже абстрактный класс
{
public:
	virtual void function() = 0;
};
class Pistol :public Firearms
{
public:
	void function()
	{
		cout << "Одиночные выстрелы" << endl;
	}
};

class Automat :public Firearms
{
public:
	void function()
	{
		cout << "Выстрелы очередью" << endl;
	}
};

class Grenade :public Firearms
{
public:
	void function()
	{
		cout << "Взрыв" << endl;
	}
};

class cold :public Weapon
{
public:
	virtual void function() = 0;
};
class Dagger :public cold
{
public:
	void function()
	{
		cout << "Режет" << endl;
	}
};
class Bit :public cold
{
public:
	void function()
	{
		cout << "Сильно бьет" << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");

	Weapon* W[] =
	{
		new Pistol(),
		new Automat(),
		new Grenade(),
		new Dagger(),
		new Bit(),
	};
	for (int i = 0; i < sizeof(W) / sizeof(Weapon*); i++)
	{
		W[i]->function();
	}
} 