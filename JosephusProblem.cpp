#include <iostream>
#include <string>
using namespace std;

/*
    Josephus Circle using circular linked list

    "we find the only person left after one in every m-th node is killed 
      in a circle of n nodes" 
    1. Create a circular linked list of size n.
    2. Traverse through linked list and one by one delete every m-th node 
       until there is one node left.
    3. Return value of the only left node.

*/
//Node
struct Node
{
    string data;
    Node *next;
};

//Circular Queue
template <typename T>
class CQueue
{
protected:
    Node *head;
    Node *tail;
    int nodeCount;

    //Create a node on heap :)
    Node *CreateNode(T data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        return temp;
    }

    //Cqueue Ctor
    CQueue() : head(NULL), tail(NULL), nodeCount(0)
    {
        //cout << "Cqueue Ctor" << endl;
    }

    //Insert into Queue :)
    void EnQueue(T data)
    {
        nodeCount++; //Decrement node count
        Node *temp = CreateNode(data);
        if (head == NULL) //Noobie :D
        {
            head = temp;
        }
        else
        {
            tail->next = temp; //Connect to tail
        }
        temp->next = head; //Connect back to head
        tail = temp;       //Make our temp as new tail
    }

    //Remove From Queue :)
    T deQueue()
    {
        if (head == NULL)
            throw std::runtime_error("Queue Empty :(");
        T value;
        if (head == tail) //Only one Node :D
        {
            value = head->data;
            delete head;
            head = tail = NULL;
        }
        else //More than one node
        {
            Node *temp = head; //Our Head
            value = temp->data;
            head = tail->next = head->next; //We have to change head and tail->next with nearest node
            delete temp;
        }
        return value;
    }

    //Find Node; Lets find our needle in the haystack ;)
    Node *findNode(T needle)
    {
        Node *trav1, *trav2;
        if (head != NULL)
        {
            trav1 = trav2 = head;
            while (trav1->next != head && trav1->data != needle)
            {
                trav2 = trav1;
                trav1 = trav1->next;
            }
            if (trav1->data == needle)
            {
                //cout << "inside" << endl;
                return trav1;
            }
            //cout << "outside" << endl;
            return NULL;
        }
        return NULL;
    }

    ~CQueue()
    {
        if (nodeCount == 1)
        {
            if (head != NULL)
                delete head;
            head = NULL; // Disconnect tail from circle
        }
        else
        { //If user of this class haven't used LastManStanding() method, nodes will still be there on heap we are releasing it manually
            if (tail != NULL)
                tail->next = NULL; // Disconnect tail from circle
            while (head != NULL)
            {
                Node *temp = head;
                head = head->next;
                cout << "Releasing " << temp->data << endl;
                delete temp;
            }
        }
        tail = NULL; //Make it null for creation of many objects
    }
};

//Josephus
class Josephus : public CQueue<string>
{
    int _m; //Mth node should be deleted
    Node *startFromNode;

public:
    Josephus() : _m(0), startFromNode(NULL)
    {
    }
    Josephus(int m) : _m(m), startFromNode(NULL)
    {
    }

    //Set Start Position
    bool SetStartPosition(string name)
    {
        Node *temp = findNode(name);
        if (temp != NULL)
        {
            this->startFromNode = temp;
            return true;
        }
        else
        {
            cout << "Oops!! " << name << " Not found!!" << endl;
            return false;
        }
    }

    //Set Mth count
    void SetMCount(int m)
    {
        this->_m = m;
    }

    //Add to Circle
    void insert(string data)
    {
        EnQueue(data);
    }

    //Find last man standing :)
    string LastManStanding()
    {
        if (head == NULL)
            throw std::runtime_error("Please add participants!");
        Node *trav1, *trav2;
        trav1 = trav2 = this->startFromNode ?: head; //If startFromNode is not NULL it will be used else head by default!!
        //cout << trav1->data << endl;
        int i = 1;
        //Iterate till one node is left; ie, when trav1->next is holding the value of
        //trav1 it means that only one node is left
        while (trav1->next != trav1)
        {
            if (_m == 1) //Since _m == 1, iterating makes no sense!!
            {
                trav2 = trav1;
                trav1 = trav1->next;
            }
            else
            {
                // Find m-th node
                int count = 1;
                while (count != _m)
                {
                    trav2 = trav1;
                    trav1 = trav1->next;
                    count++;
                } //After this epilogue trav1 will be our m th node & trav2 is m-1 th node
            }
            /* Remove the m-th node */
            Node *temp = trav1;
            cout << "Round " << i << ", " << temp->data << " Killed !" << endl;
            trav2->next = trav1->next; //make the parent node point to m+1 th node address
            trav1 = trav1->next;       //Removing from the queue
            delete temp;
            i++;
            nodeCount--;     //Decrease no of nodes
        }                    //After epilogue only one node will be present the Queue
        head = tail = trav1; //We update head and tail as the node
        return trav1->data;
    }
};

int main()
{
    int memberCount, m;
    string name, startWith;
    try
    {
        cout << "Enter m: ";
        cin >> m;
        Josephus jj(m);
        cout << "Enter no of Participants: ";
        cin >> memberCount;
        for (int i = 0; i < memberCount; i++)
        {
            cout << "Enter Participant " << i + 1 << " name:";
            cin >> name;
            jj.insert(name);
            cout << '\n';
        }
        do
        {
            cout << "Enter name wish to start with:";
            cin >> startWith;
        } while (!jj.SetStartPosition(startWith));
        cout << "Winner " << jj.LastManStanding() << endl;
    }
    catch (exception &exp)
    {
        cout << exp.what() << endl;
    }
    return 0;
}