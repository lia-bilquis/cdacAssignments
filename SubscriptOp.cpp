#include<iostream>
using namespace std;

namespace subcript
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
		
		int& operator[](int index)
		{
			return arr[index];
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
		
		objArr[2] = 999;
		cout << objArr;
		return 0;
	}
}