#include<iostream>
#include<string>
using namespace std;
namespace nm02
{

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

	int Calculate(char opr, int x, int y)
	{
		switch (opr)
		{
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return x / y;
		}
		return 0;
	}

	int main2()
	{
		int x, y;
		char ch;
		Stack<int> stk;
		string postfixed = "++a/bcd";//a+b/c+d a=1 b=4 c=2 d=3 ans=6 a+b/c+d
		for (int i = postfixed.length() - 1 ; i >= 0 ; i--)
		{
			ch = postfixed[i];
			if (isalpha(ch))
			{
				cout << "Enter the value for " << ch << " : "; cin >> x;
				stk.Push(x);
			}
			else
			{
				x = stk.Pop();
				y = stk.Pop();
				stk.Push(Calculate(ch, x, y));
			}
		}

		cout << "The Result is " << stk.Pop() << endl;
		return 0;
	}
}