#include<iostream>
using namespace std;


	struct Node {
		int data;
		Node* next;
	};

	class Merge {
		Node *head;
		Node *tail;
		Node* CreateNode(int val) {
			Node *temp = new Node();
			temp->data = val;
			temp->next = NULL;
			return temp;
		}
	public:
		Merge() :head(NULL), tail(NULL) {

		}
		void Append(int val) {
			Node *temp = CreateNode(val);
			if (head == NULL) {
				head = temp;
			}
			else {
				tail->next = temp;
			}
			tail = temp;
			cout << "Value Append " << temp->data << endl;
		}
		void Prepend(int val) {
			Node *temp = CreateNode(val);
			if (head == NULL) {
				tail = temp;
			}
			else {
				temp->next = head;
			}
			head = temp;
			cout << "Value Prepend " << temp->data << endl;
		}

		void mergeList(Merge &l1) {
			Node *trav = this->head;
			Node *prev = NULL;
			Node *temp = NULL;
			while (trav != NULL && l1.head != NULL) {
				if (trav->data < l1.head->data) {
					prev = trav;
					trav = trav->next;
				}
				else {
					temp = l1.head;
					l1.head = l1.head->next;
					if (prev != NULL) {
						temp->next = prev->next;
						prev->next = temp;
						prev = prev->next;
					}
					else {
						temp->next = trav;
						prev = this->head = temp;
					}
				}
			}
			while (l1.head != NULL) {
				temp = l1.head;
				l1.head = l1.head->next;
				temp->next = NULL;
				tail->next = temp;
				tail = tail->next;
			}
		}
		void display() {
			for (Node *trav = head; trav != NULL; trav = trav->next)
				cout << "Value is " << trav->data << endl;
		}
	};

	int main() {

		Merge l1;
		l1.Append(5);
		l1.Append(6);
		l1.Append(9);
		l1.Append(10);
		l1.display();
		cout << "______________________________________\n";
		Merge l2;
		l2.Append(7);
		l2.Append(8);
		l2.Append(11);
		l2.Append(12);
		l2.display();
		cout << "________________________________\n";
		l1.mergeList(l2);
		l1.display();
		return 0;
	}