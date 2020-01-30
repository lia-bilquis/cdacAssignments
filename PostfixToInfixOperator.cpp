#include<iostream>
#include<string>
using namespace std;

namespace nm06
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

	int main6()
	{
		Stack<char> stk;
		//string infix = "a+b*(c+d*f-y)-p+q*g+h*k";
		string postfix = "ab*c-d+";//"a*b-c+d"
		char target[100], ch;
		int j = 0;
		int l = postfix.length();
		for (int i = l-1; i >= 0; i--)
		{
			ch = postfix[i];
			if (isalpha(ch))
			{
				target[j++] = ch;
				target[j++] = stk.Pop();
			}
			else
			{
				stk.Push(ch); //precedence dosen't matter here
			}
		}

		for (int i = l - 1; i >= 0; i--) 
		{
			cout << target[i];
		}
		cout << '\n';

		return 0;
	}
}
