#include<iostream>
using namespace std;

namespace lsp_inherit
{
	class CA
	{
	public:
		void Display()
		{
			cout << "______________CA::Disp()_________________________\n";
		}
		virtual void fun()
		{
			cout << "______________CA::fun()_________________________\n";
		}
	};
	class CB :public CA
	{
	public:
		void Display()
		{
			cout << "______________CB::Disp()_________________________\n";
		}
		void fun()
		{
			cout << "______________CB::fun()_________________________\n";
		}
	};

	int main()
	{
		CA obj1;
		CB obj2;
		CA & objCaRef = obj2;//LSP
		CA*objCaPtr = &obj2;

		obj1.Display();
		obj2.Display();
		objCaRef.Display();
		objCaPtr->Display();
		cout << "____________________________\n";
		obj1.fun();
		obj2.fun();
		objCaRef.fun();
		objCaPtr->fun();
				
		return 0;
	}
}