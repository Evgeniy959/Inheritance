#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void sound() = 0;	//Чисто виртуальный метод - Pure Virtual Function (Method)
	//Этот метод НЕ имеет определения (реализации), но он обязательно должен быть определен в дочернем классе,
	//иначе дочерний класс тоже будет абстрактным.
};

class Cat :public Animal
{
public:
	void sound()
	{
		cout << "Мяу" << endl;
	}
};

class Human :public Animal
{
public:
	void sound()
	{
		cout << "Ну тут все сложно" << endl;
	}
};

class Dog :public Animal
{
public:
	void sound()
	{
		cout << "Гав" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	//Animal a;
	//Cat cat;

	Animal* zoo[] =
	{
		new Cat(),
		new Dog(),
		new Cat(),
		new Human,
		new Cat(),
		new Dog()
	};
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}
}