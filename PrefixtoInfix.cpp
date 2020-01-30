/*#include<iostream>
#include<string>
using namespace std;
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

	int main()
	{
		Stack<char> stk;
		string prefix = "++a*b-cd/ef";
                            //a+b*(c-d)+e/f  =   ++a*b-cd/ef

		//string infix = "a+b*c-d+e/f";
		char ch;
		int j = 0;

		char target[100];                                                                                  
		
                for (int i = 0; prefix[i] != '\0'; i++)

		 {
			ch = prefix[i];
			if (!isalpha(ch))
			{
				stk.Push(ch);
			}
			else

			{

				if(!stk.IsEmpty())

				{

				  target[j++]=ch;

				  target[j++]=stk.Pop();

				}

				else

				target[j++]=ch;

			}
		}

		if(!stk.IsEmpty())

		cout<<"Prefix eqn is invalid/n";

		else

		cout<<target<<endl;
		return 0;
	}*/