/*#include<iostream>
#include<string>
using namespace std;
//pushing operand
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

void postfix_to_infix(string exp)
{
	Stack<string> stk;
	char target[100], ch;
	int l = exp.length();
	int j = 0;

	for (int i = 0; i < l; i++) {
		ch = exp[i];
		if (isalpha(ch))
		{
			string s(1, ch);
			stk.Push(s);
		}
		else
		{
			string ch1 = stk.Pop();
			string ch2 = stk.Pop();
			string exp = ch2 + ch + ch1;
			stk.Push(exp);
		}
	}
	cout << stk.Peek() << endl;
}

int main()
{
	
	string postfix;
	cout << "Enter a postfix expression: \n";
	getline(cin, postfix);
	cout << "The resultant infix expression: \n";
	postfix_to_infix(postfix);
	return 0;
}
*/