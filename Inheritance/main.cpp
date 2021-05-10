#include<iostream>
using namespace std;

class Box
{
	double height;
	double width;
	double depth;
	bool is_open = false;
public:
	double get_height()const
	{
		return height;
	}
	double get_width()const
	{
		return width;
	}
	double get_depth()const
	{
		return depth;
	}
	Box& operator()(double height, double width, double depth)
	{
		this->height = height;
		this->width = width;
		this->depth = depth;
		return *this;
	}

	Box(double height, double width, double depth)
	{
		this->height = height;
		this->width = width;
		this->depth = depth;
	}

	void open()
	{
		is_open = true;
	}
	void close()
	{
		is_open = false;
	}
	void info()const
	{
		cout << height << "x" << width << "x" << depth << endl;
		cout << (is_open ? "Open" : "Closed") << endl;
	}
};

class GiftBox :public Box
{
	string cover;
	string bantik;
public:
	const string& get_conver()const
	{
		return cover;
	}
	const string& get_bantik()const
	{
		return bantik;
	}
	GiftBox
	(
		double height, double width, double depth,
		const string& cover, const string& bantik
	) :Box(height, width, depth)
	{
		this->cover = cover;
		this->bantik = bantik;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*Box box;
	box(2, 3, 4);
	box.open();
	box.close();
	box.info();*/
	GiftBox box(2, 3, 4, "С котами и мышами", "Зеленый бантик");
}