#include<iostream>
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


int main()
{

	char str[100],target[100];

	int j=0;

	Stack<char> stk;

	cout<<"Enter a sentence you want to reverse:";

	cin.getline(str,sizeof(str));

	int l=strlen(str);

	char ch;

	for(int i=l-1;i>=0;i--)

	{

		ch=str[i];

		if(ch==' ')

		{

			while(!stk.IsEmpty())

			{
                         cout<<stk.Pop();
                        }

			cout<<" ";

		}

		else

			stk.Push(ch);

	}

	while(!stk.IsEmpty())

	{cout<<stk.Pop();}

  return 0;
}