#include<iostream>
using namespace std;

namespace lazy
{
	class CArray
	{
		int arr[3];
	public:
		CArray() //:arr{11,22,33}
		{
			arr[0] = 11;
			arr[1] = 22;
			arr[2] = 33;
		}
		//Inner class
		class Helper
		{
			CArray *outerPtr;
			int index;
		public:
			Helper(CArray *outerPtr, int index) :outerPtr(outerPtr), index(index)
			{
			}
			operator int()//alisha
			{
				cout << "Reading Logic \n";
				return outerPtr->arr[index];
			}
			Helper& operator=(int val)
			{
				cout << "Writing Logic \n";
				outerPtr->arr[index] = val;
				return *this;
			}
			Helper & operator=(Helper par)
			{
				cout << "Reading/Writing Logic \n";
				outerPtr->arr[index] = par.outerPtr->arr[par.index];
				return *this;
			}
		};
		Helper operator[](int index)
		{
			return Helper(this, index);
		}
		friend ostream & operator<<(ostream& os, CArray& par)
		{
			for (int i = 0; i < 3; i++)
			{
				os << "arr[" << i << "]=" << par.arr[i] << endl;
			}
			return os;
		}
	};


	int main()
	{
		CArray objArr;
		int k = objArr[1];//reading from the array
		objArr[2] = 999;//writing to the array
		objArr[0] = objArr[1];//reading and writing on an array
		cout << objArr << "k=" << k << endl;
		return 0;
	}
}