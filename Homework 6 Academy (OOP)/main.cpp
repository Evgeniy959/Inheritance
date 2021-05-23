#include<iostream>
#include<string>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
		if (last_name[0] >= 'a' && last_name[0] <= 'z' || last_name[0] >= 'а' && last_name[0] <= 'я') this->last_name[0] -= 32;
		else if (last_name[0] == 'ё') this->last_name[0] -= 16;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
		if (first_name[0] >= 'a' && first_name[0] <= 'z' || first_name[0] >= 'а' && first_name[0] <= 'я') this->first_name[0] -= 32;
		else if (first_name[0] == 'ё') this->first_name[0] -= 16;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	//			Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{

		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//			Methods:
	void info()
	{
		cout << last_name << " " << first_name << " " << age << " лет" << endl;
	}
};

class Student :public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}

	//		Constructors:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,	//Human parameters
		const string& speciality, const string& group, double rating			//Student parameters
	) :Human(last_name, first_name, age)
	{
		this->speciality = speciality;
		this->group = group;
		this->rating = rating;
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//			Methods:
	void info()
	{
		Human::info();
		cout << "Специальность:\t" << speciality << ",\tгруппа:\t" << group << ",\tуспеваемость:" << rating << ";\n";
	}
};
class Teacher :public Human
{
	string speciality;
	unsigned int experience_worke; // опыт работы преподавателем
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience_worke()const
	{
		return experience_worke;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
		for (int i = 1; speciality[i]; i++)
		{
			if (!(speciality[i] >= 'a' && speciality[i] <= 'z' || speciality[i] >= 'а' && speciality[i] <= 'я' || speciality[i] == 'ё')) 
			 throw exception("speciality");
		}
	}
	void set_experience_worke(unsigned int experience_worke)
	{
		this->experience_worke = experience_worke;
	}
	//                       Constructurs
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience_worke
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience_worke(experience_worke);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void info()
	{
		Human::info();
		cout << "Специальность:\t" << speciality << ", опыт работы преподавателем: " << experience_worke << " лет." << endl;
	}
};

class Graduate :public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme()const
	{
		return diploma_theme;
	}
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,	//Human parameters
		const string& speciality, const string& group, double rating,			//Student parameters
		const string& diploma_theme
	) :
		Student
		(
			last_name, first_name, age,
			speciality, group, rating
		)
	{
		this->diploma_theme = diploma_theme;
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	//			Methos:
	void info()
	{
		Student::info();
		cout << "Тема дипломного проекта: " << diploma_theme << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("тупенко", "василий", 18);
	human.info();

	Student ivan("остроумный", "иван", 19, "Китайская философия", "OST_01", 4.9);
	ivan.info();

	//Teacher teacher("абрамов", "антон", 45, "Mate@##$matics", 20);
	//teacher.info();

	Graduate jesse("pinkman", "jesse", 25, "Methamphitamine manufacturing", "WithWalter", 4.5, "Methamphitamine distribution");
	jesse.info();

	Teacher test("Тупенко123", "Вася45", 18, "Хорошая", 3);
	test.info();
}