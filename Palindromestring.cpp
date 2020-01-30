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


int main()

{

	Stack<char> stk;

	char pal[15],target[15];

	cout<<"Enter a word:";

	cin.getline(pal,sizeof(pal));

	char ch;

	int j=0;

	for(int i=0;pal[i]!='\0';i++)

	{

		ch=pal[i];

		stk.Push(ch);

	}

	while(!stk.IsEmpty())

	{

		target[j++]=stk.Pop();

	}

	target[j]='\0';

	if(strcmp(pal,target)==0)

	cout<<"Entered word is a palindrome";
	else
	cout<<"Entered word is not a palindrome";

	return 0;

}*/