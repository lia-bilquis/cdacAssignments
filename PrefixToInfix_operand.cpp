#include<iostream>
#include<string>
using namespace std;

namespace nm08
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

	int main8()
	{
		Stack<string> stk;
		//string infix = "a+b*(c+d*f-y)-p+q*g+h*k";
		string prefix = "++a*bcd";//"a+b*c+d"
		char ch;
		int l = prefix.length();
		for (int i = l-1 ; i >= 0; i--)
		{
			ch = prefix[i];
			if (isalpha(ch))
			{
				string s(1, ch);
				stk.Push(s);
			}
			else
			{
				string x = stk.Pop();
				string y = stk.Pop();
				string exp = x + ch + y;
				stk.Push(exp);
			}

		}

		cout << stk.Peek() << endl;

		return 0;
	}
}
