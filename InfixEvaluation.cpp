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

	void prefix()
	{
		//string infix = "a+b*(c+d*f-y)-p+q*g+h*k";
		string infix = "a+b*c+d";
		char target[100], ch;
		char target1[100];
		int j = 0;
		char ch1;
		int x, y;
		int count = 0;

		int i =0;
		for (; infix[i] != '\0'; i++); 
		for(i = infix.length(); i >=0; i--)
		{

			ch = infix[i];

			if (isalpha(ch))

			{

				target[j++] = ch;

			}

			else if (ch == '(')

			{

				while (Peek() != ')')

				{

					target[j++] = Pop();

				}

				Pop();//to pop '('

			}

			else

			{

				if (!(IsEmpty() || ch == ')' || Peek() == ')'))

				{

					while (!IsEmpty() && Peek() != ')' && precedence(ch) < precedence(Peek()))

					{

						target[j++] = Pop();

					}

				}

				Push(ch);

			}

		}

		while (!IsEmpty())

		{

			target[j++] = Pop();

		}

		target[j] = '\0';

		cout << target << endl;
		for (int i = 0; target[i] != '\0'; i++)
		{
			count++;
		}
		
		for (int i = 0; target[i] != '\0'; i++, count--)
		{
			target1[i] = target[count-1];
		}
		cout << target1 << endl;
		
		for (int i = 0; target[i] != '\0'; i++)
		{
			ch1 = target[i];
			if (isalpha(ch1))
			{
				cout << "Enter the value for " << ch1 << " : "; cin >> x;
				Push(x);
			}
			else
			{
				y = Pop();
				x = Pop();
				Push(Calculate(ch1,  x,y));
			}
		}
	
		cout << "The Result is " << Pop() << endl;

	}



};
int main()
{
	

	Stack<int> stk;
	stk.prefix();	
	return 0;
}
*/