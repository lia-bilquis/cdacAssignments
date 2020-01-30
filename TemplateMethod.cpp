#include<iostream>
using namespace std;
//generic (template)
namespace temp_meth_impl
{
	int AddFun(int x, int y)
	{
		cout << "RTTI x=" << typeid(x).name() << endl;
		return x + y;
	}
	double AddFun(double x, double y)
	{
		cout << "RTTI x=" << typeid(x).name() << endl;
		return x + y;
	}
	int main1()
	{
		int res1 = AddFun(10, 20);
		cout << "res1=" << res1 << endl;
		double res2 = AddFun(10.12, 20.12);
		cout << "res2=" << res2 << endl;
		return 0;
	}

	template<typename T>
	T SubFun(T x, T y)
	{
		cout << "Subfun RTTI x=" << typeid(x).name() << endl;
		return x - y;
	}

	template<typename T>
	T SubFun(T x, T y, T z)
	{
		cout << "Subfun(p1,p2,p3) RTTI x=" << typeid(x).name() << endl;
		return x - y - z;
	}

	int main2()
	{
		int res1 = SubFun(10, 20);
		cout << "res1=" << res1 << endl;
		double res2 = SubFun(10.12, 20.12);
		cout << "res2=" << res2 << endl;
		char res3 = SubFun('a', 'b');
		cout << "res3=" << res3 << endl;
		int res4 = SubFun<int>('a', 'b');
		cout << "res4=" << res4 << endl;
		int res5 = SubFun(10, 20, 30);
		cout << "res5=" << res5 << endl;
		return 0;
	}


	template<typename T>
	T MulFun(T x, T y)
	{
		cout << "MulFun RTTI x=" << typeid(x).name() << endl;
		return x * y;
	}
	template<>//specialization template (full specialization / partial specialization)
	//int MulFun<int>(int x, int y)
	int MulFun(int x, int y)
	{
		cout << "MulFun (Special for int) RTTI x=" << typeid(x).name() << endl;
		return x * y * 2;
	}
	template<typename T>
	T MulFun(T x, T y, T z)
	{
		cout << "MulFun(p1,p2,p3) RTTI x=" << typeid(x).name() << endl;
		return x * y * z;
	}

	int main()
	{
		int res1 = MulFun(10, 20);
		cout << "res1=" << res1 << endl;
		double res2 = MulFun(10.12, 20.12);
		cout << "res2=" << res2 << endl;
		char res3 = MulFun('a', 'b');
		cout << "res3=" << res3 << endl;
		int res4 = MulFun<int>('a', 'b');
		cout << "res4=" << res4 << endl;
		int res5 = MulFun(10, 20, 30);
		cout << "res5=" << res5 << endl;
		return 0;
	}
}