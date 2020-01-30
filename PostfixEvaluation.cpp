#include<iostream>
#include<string>
using namespace std;
namespace nm01
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

	int main1()
	{
		int x, y;
		char ch;
		Stack<int> stk;
		string postfixed = "abc/+d+";//a+b/c+d a=1 b=4 c=2 d=3 ans=6
		for (int i = 0; postfixed[i] != '\0'; i++)
		{
			ch = postfixed[i];
			if (isalpha(ch))
			{
				cout << "Enter the value for " << ch << " : "; cin >> x;
				stk.Push(x);
			}
			else
			{
				y = stk.Pop();
				x = stk.Pop();
				stk.Push(Calculate(ch, x, y));
			}
		}

		cout << "The Result is " << stk.Pop() << endl;
		return 0;
	}
}