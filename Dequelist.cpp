/*#include<iostream>
#include<string>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node* prev;
};

class LinkedList
{
	Node *head;
	Node *tail;
	Node *ref;
	Node * CreateNode(int val)
	{
		Node *temp = new Node();
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;
		return temp;
	}
public:
	LinkedList() :head(NULL), tail(NULL),ref(NULL)
	{
	}
	void InsertFront(int data)
	{
		Node *temp = CreateNode(data);
		if (head == ref)
		{
			ref->prev=temp;
			temp->next=ref;
		}
		else
		{
			temp->next=head;
			head->prev = temp;
		}
		temp->prev=NULL;
		head=temp;
	}
	void InsertBack(int data)
	{
		Node *temp = CreateNode(data);
		if (tail == ref)
			{
				temp->prev=ref;
				ref->next=temp;
			}	
		else
		{
			temp->prev = tail;
			tail->next = temp;
		}
			temp->next = NULL;
			tail=temp;
		}
	
	void ReferenceNode(int data)
	{
		Node* temp=CreateNode(data);
		ref=temp;
		head=temp;
		tail=temp;
	}
	
	void Deque(int data)
	{
		if(ref==NULL)
		ReferenceNode(data);
		else if(data<=ref->data)
		InsertFront(data);
		else
		InsertBack(data);
	}
	void Display()
	{
		cout<<"______________________________________________________________\n";
		for (Node *trav = head; trav != NULL; trav = trav->next)
		{
			cout << trav->data << "--->";
		}	cout<<"\n______________________________________________________________\n";
	}
	void DeleteFront()
	{
		if(head!=ref)
		{
		Node* temp=head;
		head=head->next;
		head->prev=NULL;
		temp->next=NULL;
		cout<<"Delete from front : "<<temp->data<<endl;
		delete temp;
		}
		else
		cout<<"Front is empty"<<endl;
	}
	
	void DeleteBack()
	{
		if(tail!=ref)
		{
		Node* temp=tail;
		tail=temp->prev;
		temp->prev=NULL;
		tail->next=NULL;
		cout<<"Delete from back : "<<temp->data<<endl;
		delete temp;
		}
		else
		cout<<"Back is empty"<<endl;
	}
	};
	
	int main()
	{
		LinkedList l1;
		l1.Deque(50);
		l1.Deque(10);
		l1.Deque(20);
		l1.Deque(30);
		l1.Deque(40);
		l1.Deque(50);
		l1.Deque(60);
		l1.Deque(70);
		l1.Deque(80);
		l1.Deque(90);
		l1.Deque(100);
		l1.Display();
		l1.DeleteFront();
		l1.DeleteBack();
		return 0;
	}
	*/