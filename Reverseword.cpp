/*#include<iostream>
#include<string>
using namespace std;

	template<typename T>
	class Stack
	{
		T arr[100];
		int top;
	public:
		bool IsEmpty()
		{
			return top == -1;
		}

		Stack() :top(-1)
		{
		}
		void Push(T val)
		{
			arr[++top] = val;
		}
		T Pop()
		{
			return arr[top--];
		}
		T Peek()
		{
			return arr[top];
		}


	};

	int main()
	{
		char str[100];
		char target[100];
		int j = 0;
		Stack<char> stk;
		cout << "enter the sentence : ";
		cin.getline(str, sizeof(str));
		int length = strlen(str);
		for (int i = length - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				while (!stk.IsEmpty())
				{
					target[j++] = stk.Pop();
				}
				target[j++] = ' ';
			}
			else
				stk.Push(str[i]);
		}
		while (!stk.IsEmpty())
		{
			target[j++] = stk.Pop();
		}
		target[j] = '\0';
		cout << target << endl;
		return 0;
	}*/