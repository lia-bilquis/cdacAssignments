/*#include <iostream>
using namespace std;

class StackBase
{

protected:
int top;
static int count;
StackBase() : top(-1)
{
++count;
}
~StackBase()
{
--count;
}

public:
//Is Empty
bool IsEmpty()
{
return top == -1;
}
//Stack data count
int dataCount()
{
return top + 1;
}
//Get Number of stack count
static int getCount()
{
return count;
}
};
int StackBase::count = 0;
//Generic Stack
template <typename T, int size>
class Stack : public StackBase
{
T arr[size];

public:
Stack() : StackBase()
{
}

//Is Full
bool IsFull()
{
cout << "top " << top << " size " << size << endl;
return top == size;
}

void Push(T var)
{
arr[++top] = var;
}
T Pop()
{
return arr[top--];
}
T Peek()
{
if (IsEmpty())
throw std::runtime_error("Stack underflow");
return arr[top];
}
friend ostream &operator<<(ostream &os, Stack &stk)
{

if (stk.IsEmpty())
{
os << "Stack is Empty\n";
}
else
{
for (int i = stk.top; i >= 0; i--)
{
os << stk.arr[i] << endl;
}
}
return os;
}
};

//Node
struct Node
{
Stack<int, 3> stk;
Node *next; //Address of next node
};

//Linked List
class Linkedlist
{
Node *head;
Node *tail;

//Create Node
Node *CreateNode()
{
Node *temp = new Node();
temp->next = NULL;
return temp;
}

//Append to list
void Append()
{
Node *temp = CreateNode();
if (head == NULL)
{
head = temp;
}
else
{
tail->next = temp;
}
tail = temp;
}

//Delete Last
void DeleteLast()
{
if (tail == NULL)
{
throw std::runtime_error("No Node found!");
}
Node *trav = head;
if (trav->next == NULL)
{
delete trav;
head = tail = NULL;
}
else
{
for (; trav->next->next != NULL; trav = trav->next)
;
delete trav->next;
tail = trav;
trav->next = NULL;
}
}

public:
//ctor
Linkedlist() : head(NULL), tail(NULL)
{
}

//Push into current active stack
void Push(int data)
{
//cout << "data = " << data << " " << tail->stk<< endl;
if (tail == NULL || tail->stk.dataCount() == 3)
{
Append();
}
cout << " Pushed " << data << " to stack" << endl;
tail->stk.Push(data);
}

//Pop from current active stack
int Pop()
{
while (tail->stk.IsEmpty())
{
DeleteLast();
}
if (tail == NULL)
{
throw std::runtime_error("Stack underflow!");
}
return tail->stk.Pop();
}

//Peek from current active stack
int Peek()
{
if (tail == NULL)
throw std::runtime_error("Stack underflow");
return tail->stk.Peek();
}

//Over load operator<<
friend ostream &operator<<(ostream &os, Linkedlist &list)
{
int i = 1;
os << "\n No of stacks :" << StackBase::getCount() << " \n";
for (Node *trav = list.head; trav != NULL; trav = trav->next, i++)
{
os << "_____________Stack(" << i << ")____________________\n";
os << trav->stk;
os << "_________________________________\n";
}

return os;
}

//Dtor
~Linkedlist()
{
while (head != NULL) // Lets release all nodes
{
Node *temp = head; // Node Address in the head is copied to *temp
head = head->next; // Next node address is copied to head
delete temp;
}            //So after this loop; head = NULL;
tail = NULL; // Flushing Tail pointer
}
};
int main()
{
try
{
Linkedlist ll;
ll.Push(10);
ll.Push(20);
ll.Push(30);
//  cout << ll;
ll.Push(40);
ll.Push(50);
ll.Push(60);
cout << ll;
cout << " Poped out =" << ll.Pop() << endl;
cout << " Poped out =" << ll.Pop() << endl;
cout << " Poped out =" << ll.Pop() << endl;
cout << " Poped out =" << ll.Pop() << endl;
cout << " Poped out =" << ll.Pop() << endl;
cout << " Poped out =" << ll.Pop() << endl;
cout << ll;
// cout << " Peek " << ll.Peek() << endl;
ll.Push(100);
ll.Push(200);
cout << ll;
}
catch (exception &exc)
{
cout << exc.what() << endl;
}

return 0;
}*/