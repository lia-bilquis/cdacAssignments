/*#include<iostream>

#include<string>

using namespace std;

	struct Node

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

		void ActualReverse(Node* ptr1, Node* ptr2)

		{

			if (ptr2 != NULL)

			{

				ActualReverse(ptr2, ptr2->next);

				ptr2->next = ptr1;

			}

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

					temp->next = trav->next;

					trav->next = temp;

				}

			}

		}



		void Display()

		{

			for (Node *trav = head; trav != NULL; trav = trav->next)

			{

				cout << trav->data << "\t";

			}

			cout << endl;

			cout << "___________________________________________________________________\n";

		}



		void Reverse()

		{

			ActualReverse(NULL, head);

			swap(head, tail);

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

	};





	int main()

	{

		LinkedList l1;

		l1.Append(10);

		l1.Append(20);

		l1.Append(30);

		l1.Append(40);

		l1.Append(50);



		l1.Insert(4, 35);



		l1.Prepend(7);

		l1.Prepend(5);

		l1.Prepend(3);



		l1.Display();

		l1.Reverse();

		l1.Display();

		return 0;

	}
	*/



