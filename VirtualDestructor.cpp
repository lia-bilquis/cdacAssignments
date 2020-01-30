#include<iostream>
using namespace std;
namespace v_dtor
{
	class CA
	{
	public:
		CA()
		{
			cout << "CA Ctor\n";
		}
		~CA()
		{
			cout << "CA D-tor\n";
		}
	};

	class CB :public CA
	{
	public:
		CB()
		{
			cout << "CB Ctor\n";
		}
		~CB()
		{
			cout << "CB D-tor\n";
		}
	};

	int main1()
	{
		CB obj;
		return 0;
	}


	int main2()
	{
		CB *obj = new CB();

		delete obj;
		return 0;
	}


	int main3()
	{
		CA *obj = new CB();
		cout << "_____________________________\n";
		delete obj;
		return 0;
	}


	class CA1
	{
	public:
		CA1()
		{
			cout << "CA1 Ctor\n";
		}
		virtual ~CA1()
		{
			cout << "CA1 D-tor\n";
		}
	};

	class CB1 :public CA1
	{
	public:
		CB1()
		{
			cout << "CB1 Ctor\n";
		}
		~CB1()
		{
			cout << "CB1 D-tor\n";
		}
	};


	int main()
	{
		CA1 *obj = new CB1();
		cout << "_____________________________\n";
		delete obj;
		return 0;
	}

}