#include<iostream>
using namespace std;

namespace heap_loc{
	class CA
	{
		bool Is_On_Heap;
		static bool flag;
		static int count;
	public:
		CA() :Is_On_Heap(flag)
		{
			cout << "Ctor\n";
			count--;
			if (count <= 0)
				flag = false;
		}
		void* operator new(size_t size)
		{
			cout << "***************** normal new called *************** " << size << endl;
			CA*temp = (CA*)malloc(size);
			flag = true;
			count = 1;
			return temp;
		}
		void* operator new[](size_t size)
		{
			cout << "***************** new[] called *************** " << size << endl;
			CA*temp = (CA*)malloc(size);
			flag = true;
			count = size / sizeof(CA);
			return temp;
		}
		void Location()
		{
			if (Is_On_Heap == true)
			{
				cout << this << " is on heap " << endl;
			}
			else if (Is_On_Heap == false)
			{
				cout << this << " is (NOT) on heap " << endl;
			}
		}
	};
	bool CA::flag = false;
	int CA::count = 0;
	int main()
	{

		CA obj1;
		CA *ptr1 = new CA();
		CA obj2;
		CA *ptr3 = new CA[5];
		CA *ptr2 = new CA();
		cout << "___________________________________\n";
		ptr1->Location();
		ptr2->Location();
		cout << "___________________________________\n";
		obj1.Location();
		obj2.Location();
		cout << "___________________________________\n";
		for (int i = 0; i < 5; i++)
		{
			(ptr3 + i)->Location();
		}
		return 0;
	}
}