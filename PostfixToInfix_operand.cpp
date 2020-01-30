#include<iostream>
#include<string>
using namespace std;

namespace nm05
{
	//a+b*(c+d*f-y)-p+q*g+h*k
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

	int main5()
	{
		Stack<string> stk;
		//string infix = "a+b*(c+d*f-y)-p+q*g+h*k";
		string postfix = "abc*+d+";//"a+b*c+d"
		char ch;
		int l = postfix.length();
		for (int i = 0; i <= l - 1; i++) 
		{
			ch = postfix[i];
			if (isalpha(ch))
			{
				string s(1, ch);
				stk.Push(s);
			}
			else 
			{
				string x = stk.Pop();
				string y = stk.Pop();
				string exp = y + ch + x;
				stk.Push(exp);
			}

		}

		cout << stk.Peek() << endl;

		return 0;
	}
}
