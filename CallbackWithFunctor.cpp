#include<iostream>
using namespace std;

namespace functor{
	template<typename T>
	void DoVendorJob(T fn)
	{
		cout << "Vendor Job started\n";
		fn();//client job here
		cout << "Vendor Job completed\n";
	}
	//omkar 
	void ClientFun(int x, int y)
	{
		cout << "I had Okra " << "x=" << x << " y=" << y << "\n";
	}
	typedef void(*FPTR)(int, int);
	class FUNC
	{
		//capture
		FPTR fp;
		int &x;
		int y;
	public:
		FUNC(FPTR fp, int &x, int y) :fp(fp), x(x), y(y)
		{
		}
		void operator()()
			//void operator()() const
		{
			x += 100;
			y += 200;
			fp(x, y);
		}
	};
	int main1()
	{
		int x = 100;
		int y = 200;
		FPTR fp = &ClientFun;

		FUNC fnc(fp, x, y);

		DoVendorJob(fnc);


		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		return 0;
	}

	int main2()//left for home work
	{
		int x = 100;
		int y = 200;
		int z = 300;

		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		return 0;
	}


	int main3()
	{
		//type inference
		auto x = 100;
		auto y = 4.5;
		auto z = x + y;
		decltype(z) a = 45;
		decltype(z + 2 * 1.2*4.5*x) b = 45;

		cout << typeid(x).name() << " x=" << x << endl;
		cout << typeid(y).name() << " y=" << y << endl;
		cout << typeid(z).name() << " z=" << z << endl;
		cout << typeid(a).name() << " a=" << a << endl;
		cout << typeid(b).name() << " b=" << b << endl;
		return 0;
	}



	int main()
	{
		int x = 100;
		int y = 200;
		int z = 300;
		FPTR fp = &ClientFun;
		auto fnc = [&]() {  fp(x, y); };
		DoVendorJob(fnc);

		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
		return 0;
	}
}