/*#include<iostream>
#include<string>
using namespace std;

/*Guys also Ensure, you perform delete operations like
delete first
delete last
delete by position
*/
/*struct Node
{
	int data;
	Node *next;
};

class LinkedList
{
	Node *head;
	Node *tail;
	Node * CreateNode(int val)
	{
		Node *temp = new Node();
		temp->data = val;
		temp->next = NULL;
		return temp;
	}
public:
	LinkedList():head(NULL),tail(NULL)
	{
	}
	void Append(int data)
	{
		Node *temp = CreateNode(data);
		if (head == NULL)
			head = temp;
		else
			tail->next = temp;
		tail = temp;
	}
	void Prepend(int data)
	{
		Node *temp = CreateNode(data);
		if (head == NULL)
			 tail = temp;
		else
			temp->next = head;
		head = temp;
	}

	void Insert(int position, int data)
	{
		if (head == NULL)
		{
			Append(data);
		}
		else if(position==1)
		{
			Prepend(data);
		}
		else
		{
			Node *trav;
			int i;
			for (i = 1, trav = head; trav != NULL && i < position - 1; trav = trav->next, i++);//for loop ends
	
			if (trav == NULL)
			{
				Append(data);
			}
			else
			{
				Node *temp = CreateNode(data);
				temp->next = trav->next;
				trav->next = temp;
			}
		}
	}

	void Display()
	{
		for (Node *trav = head; trav != NULL; trav = trav->next)
		{
			cout << trav->data << endl;
		}
	}


	~LinkedList()
	{
		while (head != NULL)
		{
			Node*temp = head;
			head = head->next;
			cout << "Releasing " << temp->data << endl;
			delete temp;
		}
		tail = NULL;
	}
   void delfirst()
   {
    Node *temp;
    head=temp->next;
    temp->next=NULL;
    delete temp;
   }
   void dellast()
  {
   Node *ptr;
   Node *prev;
   if(head==NULL)
   {
    cout<<"empty";
   }
   else if(head->next==NULL)
   { 
    ptr=head;
    head=NULL;
    delete ptr;
   }
   else
   {
    ptr=head;
    while(ptr->next!=NULL)
    {
     prev=ptr;
     ptr=ptr->next;
    }
    prev->next=NULL;
    delete ptr;
}
       
}
 void delpos(int n)
{
 Node* temp1=head;
 Node* temp2;
 for(int i=1;i<n-1;i++)
 {
  temp1=temp1->next;
}
  temp2=temp1->next;
  temp1->next=temp2->next;
  delete temp2;
}


};


int main()
{
	LinkedList l1;
	l1.Append(10);
	l1.Append(20);
	l1.Append(30);
	//l1.Append(40);
//	l1.Append(50);

//	l1.Insert(4, 35);

	l1.Prepend(7);
    //l1.delfirst();
  //  l1.dellast();
    l1.delpos(2);
	//l1.Prepend(5);
	//l1.Prepend(3);
	l1.Display();
	return 0;
}*/

/*#include<iostream>
using namespace std;
//namespace nm16 {
	struct Node
	{
		int data;
		Node* next;
	};

	class LinkedList
	{
		Node* head;
		Node* tail;
		Node* CreateNode(int val)
		{
			Node* temp = new Node();
			temp->data = val;
			temp->next = NULL;
			return temp;
		}
	public:
		LinkedList() :head(NULL), tail(NULL)
		{
		}
		void Append(int data)
		{
			Node* temp = CreateNode(data);
			if (head == NULL)
				head = temp;
			else
				tail->next = temp;
			tail = temp;
		}
		void Prepend(int data)
		{
			Node* temp = CreateNode(data);
			if (head == NULL)
				tail = temp;
			else
				temp->next = head;
			head = temp;
		}

		void Insert(int data)
		{
			if (head == NULL)
			{
				Append(data);
			}
			else if (data < head->data)
			{
				Prepend(data);
			}
			else
			{
				Node* trav;
				for (trav = head; trav->next != NULL && trav->next->data < data; trav = trav->next);//for loop ends

				if (trav == NULL)
				{
					Append(data);
				}
				else
				{
					Node* temp = CreateNode(data);
					temp->next = trav->next;
					trav->next = temp;
				}
			}
		}

		void Display()
		{
			for (Node* trav = head; trav != NULL; trav = trav->next)
			{
				cout << trav->data << "->";
			}
		}

		void Reverse()
		{
			Node* temp, * prev = NULL, * next = NULL;
			temp = head;
			while (temp != NULL) {
				next = temp->next;
				temp->next = prev;
				prev = temp;
				temp = next;
			}
			head = prev;
		}

		~LinkedList()
		{
			while (head != NULL)
			{
				Node* temp = head;
				head = head->next;
				cout << "Releasing " << temp->data << endl;
				delete temp;
			}
			tail = NULL;
		}
	};


	int main() {

		LinkedList l1;
		int data;
		do
		{
			cout << "\nInsert Data (Insert '0' to exit):\n"; cin >> data;
			if (data != 0)
				l1.Insert(data);
		} while (data!=0);
		cout << "Displaying data.......\n";
		l1.Display();
		return 0;
	}*/
//}



/*#include<iostream>
using namespace std;

//problem in insertion sort
struct Node {
	int data;
	Node* next;
	
};

class Insertion {
	Node *head;
	Node *tail;
	Node *CreateNode(int val){
		Node *temp = new Node();
		temp->data = val;
		temp->next   = NULL;
		return temp;
	}
public:
	Insertion() :head(NULL), tail(NULL) {

	}
	void append(int val) {
		Node *temp = CreateNode(val);
		if (head == NULL)
			head = temp;
		else {
			tail->next = temp;
		}
		tail = temp;
	}
	void prepend(int val) {
		Node *temp = CreateNode(val);
		if (head == NULL)
			tail = temp;
		else {
			temp->next = head;
		}
		head = temp;
	}
	void Insert(int val ) {
		Node *temp = CreateNode(val);
		Node *curr = head;
		Node *prev = NULL;
		if (head == NULL)
			append(val);
		else if ( head->data > val)
			prepend(val);
		else
		{
			while (curr!=NULL && curr->data <= val) {
				prev = curr;
				curr = curr->next;
			}
			prev->next = temp;
			temp->next = curr;
		}
	}
	void display() {
		for (Node *trav = head; trav != NULL; trav = trav->next)
			cout << "Value after display " << trav->data << endl;
	}
};

int main() {
	Insertion isrt;
	isrt.Insert(5);
	isrt.Insert(3);
	isrt.Insert(7);
	isrt.Insert(30);
	isrt.Insert(13);
	isrt.Insert(55);
	isrt.Insert(1); /// yaha pe null ke next pe daalne ki koshish thi .... isiliye exception throw kar raha tha
	isrt.Insert(2);
	isrt.display();


	return 0;
}*/