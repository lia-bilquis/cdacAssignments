#include<iostream>
using namespace std;
namespace unary
{
	class CA
	{
		int x;
		int y;
	public:
		CA() :x(10), y(20)
		{
			cout << "Ctor &x=" << &x << endl;
			cout << "Ctor &y=" << &y << endl;
			cout << "__________________________________\n";
		}
		CA(int x, int y) :x(x), y(y)
		{
		}
		int operator*()
		{
			return x + y;
		}
		void* operator&()
		{
			return &y;
		}
		CA operator-()
		{
			return CA(-x, -y);
		}
		CA& operator++(int)
		{
			++y;
			return *this;
		}
		CA& operator++()
		{
			++x;
			return *this;
		}
		void Display()
		{
			cout << "x=" << x << endl;
			cout << "y=" << y << endl;
			cout << "__________________________________\n";
		}
	};
	int main()
	{
		CA obj1;
		cout << "&obj1=" << &obj1 << endl;
		cout << "&obj1=" << addressof(obj1) << endl;
		obj1.Display();
		CA obj2 = -obj1;
		obj2.Display();
		obj2++;
		obj2.Display();
		++obj2;
		obj2.Display();
		cout << *obj1 << endl;
		return 0;
	}
}