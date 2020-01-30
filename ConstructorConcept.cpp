#include<iostream>
using std::cout;
namespace ctor_dtor
{

	class x
	{
	public:
		x()
		{
			cout << "x::C-tor\n";
		}
		~x()
		{
			cout << "x::D-tor\n";
		}
	};
	class y
	{
	public:
		y()
		{
			cout << "y::C-tor\n";
		}
		~y()
		{
			cout << "y::D-tor\n";
		}
	};
	class z
	{
	public:
		z()
		{
			cout << "z::C-tor\n";
		}
		~z()
		{
			cout << "z::D-tor\n";
		}
	};
	class a
	{
	public:
		a()
		{
			cout << "a::C-tor\n";
		}
		~a()
		{
			cout << "a::D-tor\n";
		}
	};
	class b
	{
	public:
		b()
		{
			cout << "b::C-tor\n";
		}
		~b()
		{
			cout << "b::D-tor\n";
		}
	};
	class c
	{
	public:
		c()
		{
			cout << "c::C-tor\n";
		}
		~c()
		{
			cout << "c::D-tor\n";
		}
	};

	class CA :public x, public y, public z
	{
	public:
		CA()
		{
			cout << "CA::C-tor\n";
		}
		~CA()
		{
			cout << "CA::D-tor\n";
		}
	};

	int main()
	{	
		CA obj;
		a ob1;
		b ob2;
		c ob3;

		cout << "______________________________\n";
		return 0;
		
	}
	}


	
	/*
	class x,y,z
	class a,b,c

	class CA:public x,public y,public z
	{
	CA()
	{
	}
	~CA()
	{
	}

	a ob1;
	b ob2;
	c ob3;

	}

	*/
