#include<iostream>
#include<string>
using namespace std;

class StackMenu
{
public:
	static char Menu()
	{
		char choice;
		cout << "p/P for Push\n";
		cout << "o/O for Pop\n";
		cout << "l/L for List\n";
		cout << "e/E for exit\n";
		cout << "Enter your choice : ";
		cin >> choice;
		return choice;
	}
};
class Stack
{
	static Stack *head;
	Stack *next;
	int data;
public:
	Stack():next(NULL)
	{
	}
	Stack(int data):data(data)
	{
		next = head;
		head = this;
	}
	void Display()
	{
		cout << "______________________ Stack Contents___________\n";
		for (Stack* trav = head; trav != NULL; trav = trav->next)
		{
			cout << trav->data << '\n';
		}
		cout << "________________________________________________\n";
	}
	void Push(int data)
	{
		new Stack(data);
	}
	void Release()
	{
		delete head;
		head = NULL;
	}
	bool IsEmpty()
	{
		return head == NULL;
	}
	int Pop()
	{
		if (IsEmpty())
			throw exception("Stack is empty");
		int data = head->data;
		cout << "The poped element is : " << data << "\n";
		Stack *temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
		return data;
	}
	~Stack()
	{
	if(!IsEmpty())
	{
		cout << "Releasing Data : " << data << endl;
		if (next != NULL)
			delete next;
	}
	}
};
Stack* Stack::head=NULL;

int main()
{
	 int val;
	char ch;
	Stack stk;
	while (!(ch = StackMenu::Menu(), IsExit(ch)))
	{
		try
		{
			switch (ch)
			{
			case 'p':
			case 'P':
			{
				cout << " Enter the element to be Pushed : ";
				cin >> val;
				stk.Push(val);
			}
			break;
			case 'o':
			case 'O':
			{
				val = stk.Pop();
				cout << "The Poped element is " << val << endl;
			}
			break;
			case 'l':
			case 'L':
				cout << stk;
				break;
			default:
				cout << "Enter Proper choice \n";
			}
		}
		catch (exception & exp)
		{
			cout << "__________________________________\n";
			cout << exp.what() << endl;
			cout << "__________________________________\n";
		}
	}
	return 0;
}