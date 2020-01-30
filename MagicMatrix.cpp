#include<iostream>
using namespace std;
namespace mgcmtrx
{
	class magic
	{
		int cur_col, cur_row, next_col, next_row, magic_metrix[100][100];
	public:
		// magic():cur_row(0)
		//  {
		//}

		void calc(int size, int first)
		{
			
			int num;
			int max = (size*size) + first - 1;
			cur_col = size / 2;
			cur_row = 0;
			int  num1 = first + 1;
			magic_metrix[cur_row][cur_col] = first;
			for (num = num1; num <= max; num++)
			{
				if ((cur_col + 1) > (size - 1))
				{
					next_col = 0;
				}
				else
				{
					next_col = cur_col + 1;
				}
				if ((cur_row - 1)<0)
				{
					next_row = size - 1;
				}
				else
				{
					next_row = cur_row - 1;
				}
				if (magic_metrix[next_row][next_col]>0)
				{
					if ((cur_row + 1) > (size - 1))
					{
						next_row = 0;
					}
					else
					{
						next_row = cur_row + 1;
						next_col = cur_col;
					}
				}
				cur_row = next_row;
				cur_col = next_col;
				magic_metrix[cur_row][cur_col] = num;
			}
		}
		void display(int size)
		{
			int i, j;
			for (i = 0; i < size; i++)
			{
				for (j = 0; j < size; j++)
				{
					cout << magic_metrix[i][j] << "\t";
				}
				cout << "\n";
			}
		}
	};
	int main()
	{
		int n, f;
		cout << "enter size";
		cin >> n;
		cout << "\nenter first";
		cin >> f;
		magic m;
		m.calc(n, f);
		m.display(n);
		return 0;
	}
}