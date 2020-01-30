/*#include<iostream>
#include<string>
using namespace std;*/


	/*Guys also Ensure, you perform delete operations like
	delete first
	delete last
	delete by position
	*/
	/*struct Node
	{
		int data;
		Node *next;
		Node* prev;
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
			temp->prev = tail;
			return temp;
		}
	public:
		LinkedList() :head(NULL), tail(NULL)
		{
		}
		void Append(int data)
		{
			Node *temp = CreateNode(data);
			if (head == NULL)
				head = temp;
			else
				tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		void Prepend(int data)
		{
			Node *temp = CreateNode(data);
			if (head == NULL)
				tail = temp;
			else
				head->prev = temp;
			temp->next = head;
			head = temp;

		}

		void Insert(int position, int data)
		{
			if (head == NULL)
			{
				Append(data);
			}
			else if (position == 1)
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
					Node * s = trav->next;
					temp->next = trav->next;
					temp->prev = trav;
					trav->next = temp;
					s->prev = temp->next;

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

		/*void Check()
		{


			tail = tail->prev;
			cout << tail->data;


		}*/

		/*~LinkedList()
		{
			while (head != NULL)
			{
				Node*temp = head;
				head = head->next;
				cout << "Releasing " << temp->data << endl;
				delete temp;
			}
			tail = NULL;
		}*/
/*		void Delete(int position)
	{
		if (position == 1)
		{
			Node *ptr;
			ptr = head;
			head = head->next;
			delete ptr;
		}
		else
		{
			Node *trav;
			int i;
			for (i = 1, trav = head; trav != NULL && i < position - 1; trav = trav->next, i++);//for loop ends

			Node *ptr;
			ptr = trav;
			ptr = trav->next;
			trav->next = ptr->next;
			ptr->next->prev = trav;
			delete ptr;
		}
		}

	};


	int main()
	{
		LinkedList l1;
		l1.Append(10);
		l1.Append(20);
		l1.Append(30);
		l1.Append(40);
		l1.Append(50);
		l1.Delete(3);

		l1.Insert(3, 25);

		//l1.Prepend(7);
		//l1.Prepend(5);
		//l1.Prepend(3);
		l1.Display();
		//l1.Check();

		return 0;
	}*/


