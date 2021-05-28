#include<iostream>
#include<string>
#include<regex>
using namespace std;

#define delimiter "\n-------------------------------------------------------\n"

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
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
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
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//			Methods:
	virtual void info()
	{
		cout << last_name << " " << first_name << " " << age << " лет" << endl;
	}
	//virtual void duty() = 0;	//Обязанности
};
ostream& operator<<(ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << ", " << obj.get_age() << " лет";
}

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
	void duty()
	{
		cout << "Основная обязанность: учиться" << endl;
	}
};
ostream& operator<<(ostream& os, const Student& obj)
{
	return os << (Human)obj << ", " << obj.get_speciality() << " " << obj.get_group() << " " << obj.get_rating();
}
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
	void duty()
	{
		cout << "Основная обязанность: обучать студентов" << endl;
	}
};
ostream& operator<<(ostream& os, const Teacher& obj)
{
	os << (Human)obj << ", ";
	return os << obj.get_speciality() << ", опыт работы преподавателем: " << obj.get_experience_worke() << " лет";
}

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
ostream& operator<<(ostream& os, const Graduate& obj)
{
	return os << (Student)obj << obj.get_diploma_theme();
}

//#define INHERITANCE
//#define REGEX
#ifdef REGEX
//#define RGX_NAME_CHECK
#define RGX_EMAIL_CHECK  
#endif // REGEX
#define POLYMORPHISM


void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Тупенко", "Василий", 18);
	human.info();

	Student ivan("Остроумный", "Иван", 19, "Китайская философия", "OST_01", 4.9);
	ivan.info();

	Teacher teacher("Абрамов", "Антон", 45, "Matematics", 20);
	teacher.info();

	Graduate jesse("Pinkman", "Jesse", 25, "Methamphitamine manufacturing", "WithWalter", 4.5, "Methamphitamine distribution");
	jesse.info();
#endif // INHERITANCE



#ifdef REGEX
	/*
	https://www.cplusplus.com/reference/regex/
	https://www.cplusplus.com/reference/regex/ECMAScript/
	https://www.cplusplus.com/reference/regex/regex_match/
	*/

#ifdef RGX_NAME_CHECK
	regex name_template("[A-Z][a-z]{1,30}");
	string name;
	cout << "Введите имя: "; cin >> name;
	//regex_match(строка для проверки (наша строка), регулярное выражение, шаблон проверки);
	cout << regex_match(name.c_str(), name_template, std::regex_constants::match_any) << endl;
#endif // RGX_NAME_CHECK

#ifdef RGX_EMAIL_CHECK
	regex rgx("([A-Za-z0-9].){3,20}@[A-Za-z]{1,10}.[A-Za-z]{2,3}");
	string email = "vasya....tupenko@mail.ru";
	cout << regex_match(email, rgx, std::regex_constants::match_any) << endl;
#endif // RGX_EMAIL_CHECK

#endif // REGEX

	//1. Обобщение - Generalization:
	// При заполнении массива выполняется преобразование дочернего объекта в базовый тип - upcast 
	Teacher teacher("Einstein", "Albert", 140, "Astronomy", 80);
	Student student("Ломоносов", "Михаил", 100, "Phisics", "SPD_011", 99);

	Human* p_teacher = &teacher;
	Human* p_student = &student;

	p_teacher->info();
	p_student->info();
	cout << delimiter << endl;
	int arr[] = { 3, 5, 8, 13, 21 };
	//Human h("Дурко", "Виталий", 20);
	Human* group[] =
	{
		new Teacher("Einstein", "Albert", 140, "Astronomy", 80),
		new Student("Шведенко", "Евгений", 35, "Провизор", "SPD_011", 99),
		new Teacher("Ломоносов", "Михаил", 100, "Phisics", 75),
		new Student("Перьмяков", "Роман", 36, "инженер", "SPD_011",98),
		new Graduate("Кудратов", "Шахзод", 18, "РПО", "SPD_011", 98, "Разработка искуственного интелекта")
	};
	cout << sizeof(group) << endl;
	//2. Specialization:
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << typeid(*group[i]).name() << endl;
		//group[i]->duty();
		//cout << *group[i] << ", ";
		//Преобразование базового объекта в дочерний класс - downcast.
		//downcast выполняет dynamic_cast.
		//dynamic_cast преобразует указатель на базовый класс (Human) в указатель на дочерний класс
		/*if(typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]);
		if(typeid(*group[i]) == typeid(Teacher))cout << *dynamic_cast<Teacher*>(group[i]);
		if(typeid(*group[i]) == typeid(Graduate))cout << *dynamic_cast<Graduate*>(group[i]);*/
		cout << *group[i] << endl;
		//group[i]->info();
		cout << delimiter << endl;
	}

	/*Student* group[] =
	{
		new Student("Перьмяков", "Роман", 36, "инженер", "SPD_011",98),
		new Graduate("Кудратов", "Шахзод", 18, "РПО", "SPD_011", 98, "Разработка искуственного интелекта"),
		new Student("Шведенко", "Евгений", 35, "Провизор", "SPD_012", 99)
	};*/
	/*for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		if(group[i]->get_group() == "SPD_011")group[i]->info();
		cout << delimiter << endl;
	}*/
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}

}