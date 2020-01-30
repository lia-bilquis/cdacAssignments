/////////PROGRAM FOR 
/*#include<iostream>
#include<string>
using namespace std;
int ptop = -1;
//////STACK
//template<typename T, int size>
class Stack
{
	//T arr[size];
protected:
	int arr[5];
	int top;
public:
	Stack() :top(-1)
	{
	}
	bool IsFull()
	{
		return (top == 4);
	}
	bool IsEmpty()
	{
		return (top == -1);
	}
	void Push(int val)
	{
		arr[++top] = val;
		ptop++;
	}
	int Pop()
	{
		ptop--;
		int x = 0;
		swap(x,arr[top]);
		--top;
		return x;
	}
	int Peek()
	{
		return arr[top];
	}
	void display()
	{
		for (int i = 4; i >= 0; i--)
			cout << this->arr[i] << "\t";
		cout << "\n-------------------------------------------\n";
	}
};
////////Structure NODE
struct Node
{
	// Stack<int,5> stk;
	Stack stk;
	Node* next;
};
////// LINKED LIST
class LinkedList : public Stack
{
	friend Stack;
	Node* head;
	Node* tail;
	Node* CreateNode()
	{
		Node* temp = new Node();
		temp->next = NULL;
		return temp;
	}
public:
	LinkedList() :head(NULL), tail(NULL)
	{
	}
	void Append()
	{
		Node* temp = CreateNode();
		if (head == NULL)
		{
			head = temp;
			tail = head; //////////
		}
		else
			tail->next = temp;
		tail = temp;
	}
	void DisplayinList()
	{
		cout << "\n___________________________________________________________________\n";
		for (Node* trav = head; trav != NULL; trav = trav->next)
		{
			trav->stk.display();
		}
		cout << endl;
		cout << "\n___________________________________________________________________\n";
	}
	void pushIntoStack(int val)
	{
		tail->stk.Push(val);
	}
	bool checkFull()
	{
		return(tail->stk.IsFull());
	}
	int deleteitem()
	{
		int x = tail->stk.Pop();
		if (tail->stk.IsEmpty() == true)
		 {
			cout << "deleting the stack";
			Node* temp;
			for (temp = head; temp->next != tail; temp = temp->next);
			tail = temp;
			tail->next = NULL;
			delete(temp->next);
		 } 
		return x;
	}
	~LinkedList()
	{
		/*while (head != NULL){Node*temp = head;head = head->next;cout << "Releasing " << temp->data << endl;delete temp;tail = NULL;*/
	/*}
};

int main()
{
	char ch = 'y';
	int a, choice;
	LinkedList l1;
	l1.Append();
	cout << "Welcome to SP\n";
	while ('y' == ch || 'Y' == ch)
	{
		cout << "Enter your choice\n\n";
		cout << "1.Insert Value\n";
		cout << "2.Pop Value\n";
		cout << "3.Display List\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nEnter some value to be entered\n";
			cin >> a;
			if (l1.checkFull() == true)
			{
				l1.Append();
				l1.pushIntoStack(a);
			}
			else
			{
				l1.pushIntoStack(a);
			}
			break;
		case 2:
		{
			int x = l1.deleteitem();
			cout << "Deleted " << x;
			break;
		}
		case 3:
			l1.DisplayinList();
			break;
		default:
			cout << "Enter the valid option\n";
		}
		cout << "\nDo you want to continue (y/n)\t";
		cin >> ch;
	}
	return 0;
}*/
