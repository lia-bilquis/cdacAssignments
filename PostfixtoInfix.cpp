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
int main() {
	string postfix = "abc*+d+";
	char target[10],ch;
	int l = postfix.length();
	Stack<char> stk;
	int j = l;
	target[j--] = '\0';
	for (int i = l-1; i >= 0; i--)
	{
		ch = postfix[i];
		if (isalpha(ch))
		{
			target[j--] = ch;
			if (!stk.IsEmpty())
				target[j--] = stk.Pop();
		}
		else
			stk.Push(ch);
	}
	cout << "\n" << target;
}*/