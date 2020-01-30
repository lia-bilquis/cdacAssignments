#include<iostream>
#include<string>
using namespace std;

namespace nm04
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

int precedence(char opr)
{
	switch (opr)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	}
	return -1;
}

int main4()
{
	Stack<char> stk;
	string infix = "a+b*(c+d*f-y)-p+q*g+h*k";
	//string infix = "a+b*c+d";
	char target[100], ch;
	int j = 0;
	for (int i = infix.length()-1 ; i >= 0 ; i--) {
		ch = infix[i];
		if (isalpha(ch))
		{
			target[j++] = ch;
		}
		else if (ch == '(')
		{
			while (stk.Peek() != ')')
			{
				target[j++] = stk.Pop();
			}
			stk.Pop();//to pop ')'
		}
		else
		{
			if (!(stk.IsEmpty() || ch == ')' || stk.Peek() == ')'))
			{
				while (!stk.IsEmpty() && stk.Peek() != ')' && precedence(ch) < precedence(stk.Peek()))
				{
					target[j++] = stk.Pop();
				}
			}
			stk.Push(ch);
		}
	}
	while (!stk.IsEmpty())
	{
		target[j++] = stk.Pop();
	}
	target[j] = '\0';

	for (int i = j-1; i >= 0; i--)
	{
		cout << target[i];
	}
	cout << '\n';
	
	return 0;
}
}
