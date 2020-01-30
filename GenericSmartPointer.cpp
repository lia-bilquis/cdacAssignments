#include<iostream>
using namespace std;
namespace generic_temp
{	// creating object type of template i.e. ca class type object
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor\n";
		}
		void fun()
		{
			cout << "CA fun called \n";
		}
		~CA()
		{
			cout << "CA D-tor\n";
		}

	};

	template<typename T>
	class Smart
	{
		T *ptr;
		int *count;
	public:
		Smart(T* ptr = NULL) :ptr(ptr), count(new int(1))
		{
		}
		Smart(const Smart& par) :ptr(par.ptr), count(par.count) //by reference 
		{
			++(*count);
		}
		T* operator->()	//operator overloading '->'
		{
			return ptr;
		}
		Smart& operator=(Smart par) //operator overloading '='	
		{
			swap(count, par.count);
			swap(ptr, par.ptr);
			return *this;
		}
		~Smart()
		{
			--(*count);
			if ((*count) == 0)
			{
				delete ptr;
				delete count;
			}
		}
	};

	template<typename T>
	T* CreateT()
	{
		return new T();
	}

	int main()
	{
		Smart<CA> sm = CreateT<CA>();
		sm->fun();
		Smart<CA> sm1(sm);
		Smart<CA> sm2 = CreateT<CA>();
		sm2 = sm1;
		cout << "______________________________________________________\n";
		return 0;
	}
}