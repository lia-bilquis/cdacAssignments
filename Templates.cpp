#include<iostream>
using namespace std;
namespace special
{
	template<typename T1, typename T2>
	class CA
	{
	public:
		CA()
		{
			cout << "T1=" << typeid(T1).name() << " T2=" << typeid(T2).name() << endl;
		}
		~CA()
		{

		}
	};
	template<typename T>
	class CB :public CA<T, int>
	{

	};

	template<typename T>
	class CB<T*> :public CA<T*, int>
	{
	public:
		CB()
		{
			cout << "Speclialized for Pointers " << endl;
		}
	};

	template<typename T1, typename T2>
	class CA<T1*, T2*>
	{
		T1 * x;
	public:
		CA()
		{
			cout << "Special for Pointers of  T1=" << typeid(T1).name() << " T2=" << typeid(T2).name() << endl;
		}
		~CA()
		{

		}
	};

	int main()
	{
		CB<double> obj;
		cout << "____________________________________\n";
		CB<int*> obj1;
		cout << "____________________________________\n";
		CA<double*, int*> obj3;
		cout << "____________________________________\n";
		CA<double, int> obj4;
		return 0;
	}
}