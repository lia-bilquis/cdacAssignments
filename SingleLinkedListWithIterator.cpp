#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next; //Address of next node
};

template <typename T>
class IIterate
{
    virtual T operator*() = 0;
    virtual void operator++() = 0;
    virtual void operator++(int) = 0;
};

template <typename T>
class Linkedlist
{
    Node *head; //Head of list; First one
    Node *tail; //End of list; Last One

    Node *CreateNode(T val)
    {
        Node *temp = new Node();
        temp->data = val;
        temp->next = NULL;
        return temp;
    }

    void ActualReverse(Node *n1, Node *n2)
    {
        if (n2 != NULL)
        {
            ActualReverse(n2, n2->next);
            n2->next = n1;
        }
    }

public:
    //Ctor
    Linkedlist() : head(NULL), tail(NULL)
    {
    }

    //Append to list
    void Append(T val)
    {
        Node *temp = CreateNode(val); //Our new node created in heap and address stored in *temp
        if (head == NULL)
        {                //this implies that so far no nodes in list
            head = temp; //Make our newly made node as head
        }
        else
        { //Implies there is a list so we just need to find the tail guy now!!!
            tail->next = temp;
        }
        //copy temp value to tail
        tail = temp; // New tail
    }

    //Prepend to list; Opposite to Append
    void Prepend(T val)
    {
        Node *temp = CreateNode(val);
        if (head == NULL)
        {
            tail = temp; // New list :)
        }
        else
        {
            temp->next = head; // Already present list's head ptr saved to temp
        }
        head = temp; // new head
    }

    //void reverse
    void Reverse()
    {
        ActualReverse(NULL, head);
        swap(head, tail);
    }

    //Over load operator<<
    friend ostream &operator<<(ostream &os, Linkedlist &list)
    {
        for (Node *trav = list.head; trav != NULL; trav = trav->next)
        {
            os << trav->data << endl;
        }
        return os;
    }

    //Handle
    class Handle
    {
    public:
        Linkedlist *ptr;
        Node *curr;

        Handle(Linkedlist *ptr, Node *nod) : ptr(ptr), curr(nod)
        {
        }
        bool operator==(Handle &par)
        {
            return curr == par.curr;
        }
        bool operator!=(Handle &par)
        {
            return curr != par.curr;
        }
    };

    //iterator begin
    Handle begin()
    {
        return Handle(this, head);
    }

    //iterator  end
    Handle end()
    {
        return Handle(this, NULL);
    }

    //Iterator
    class Iterator : public IIterate<T>
    {
        Handle hndl;

    public:
        Iterator(Handle hndl) : hndl(hndl)
        {
        }

        //
        virtual T operator*()
        {
            return hndl.curr->data;
        }

        //next node
        virtual void operator++()
        {
            hndl.curr = hndl.curr->next;
        }

        //next node
        virtual void operator++(int)
        {
            hndl.curr = hndl.curr->next;
        }

        bool operator==(Iterator &par)
        {
            return hndl == par.hndl;
        }
        bool operator!=(Iterator &par)
        {
            return hndl != par.hndl;
        }
    };

    //Iterator
    //Dtor
    ~Linkedlist()
    {
        while (head != NULL) // release all nodes
        {
            Node *temp = head; // Node Address in the head is copied to *temp
            head = head->next; // Next node address is copied to head
            cout << "Releasing " << temp->data << endl;
            delete temp;
        }            //So after this loop; head = NULL;
        tail = NULL; // Flushing Tail pointer
    }
};

int main()
{
    Linkedlist<int> ll;
    for (auto i : {20, 30, 40, 50, 60, 70, 80, 90})
    {
        ll.Append(i);
    }

    Linkedlist<int>::Iterator it1 = ll.begin();
    Linkedlist<int>::Iterator it2 = ll.end();

    while (it1 != it2)
    {
        cout << *it1 << endl;
        it1++;
    }
    return 0;
}