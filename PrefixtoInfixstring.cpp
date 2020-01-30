/*#include<iostream>
#include<string>
using namespace std;
//pushing operands into the stack
class Stack
{
	string arr[100];
	int top;
public:
	Stack() :top(-1)
	{

	}
	void Push(string ch)
	{
		arr[++top] = ch;
	}
	string Pop()
	{
		return arr[top--];
	}
	string Peek()
	{
		return arr[top];
	}
};

void prefix_to_infix(string exp)
{
	Stack stk;
	int len = exp.length();
	char target[] = { ' ' };
	char ch;
	for (int i = (len - 1); i >= 0; i--)
	{
		ch = exp[i];
		string s(1, ch);
		if (isalpha(ch))
			stk.Push(s);
		else
		{
			string x = stk.Pop();
			string y = stk.Pop();
			string result = x + ch + y;
			stk.Push(result);
		}
	}
	cout << stk.Peek() << '\n';
}

int main()
{
	string exp;
	cout << "Enter a prefix expression: \n";
	getline(cin, exp);
	cout << "The resultant infix expression: \n";
	prefix_to_infix(exp);
	return 0;
}*/