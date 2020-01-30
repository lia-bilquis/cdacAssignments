/*#include <iostream>
#include<string>
using namespace std;

class PositionException {
protected:
    string message;
public:
    PositionException(const string &m) {
        message = m;
    }
    void print() {
        cout << message << endl;
    }
};

template <typename T>

class NodeList {

protected:

    struct Node {
        Node *prev;
        Node *next;
        T item;
        Node(T i = T(), Node *p = NULL, Node *n = NULL) : item(i), prev(p), next(n) {}

    };


    typedef Node * NodePtr;

public:
    class Position {
    protected:
        NodePtr node;
    public:
        bool isNull() {
            return node == NULL;
        }
        Position(NodePtr n = NULL) : node(n)
	{
	}
        T& element() {
            return node->item;
        }

        friend class NodeList;
    };


    class ObjectIterator {
    protected:
        NodePtr node;
    public:
        ObjectIterator(NodePtr n = NULL) : node(n) {}

        bool hasNext() {

            if (node->next == NULL) {
                return false;
            }

            if (node->next->next == NULL) {
                return false;
            }
            return true;
        }
        ObjectIterator next() {
        node = node->next;
        return *this;
    }
        T& element() {
            return node->item;
        }
        friend class NodeList;


    };

protected:
    int sz;
    NodePtr header;
    NodePtr trailer;

public:
    NodeList() {
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
        sz = 0;
    }

    bool isEmpty() const {
        return size() == 0;
    }
    int size() const {
        return sz;
    }

    bool isFirst(const Position& p) const {
        return p.node->prev == header;
    }
    bool isLast(const Position& p) const {
        return p.node->next = trailer;
    }


    Position first() const {
        if (isEmpty()) {
            throw PositionException("no first for empty list");
        }
        return Position(header->next);
    }

    Position last() const {
        if (isEmpty()) {
            throw PositionException("no last for emtpy list");
        }
        return Position(trailer->prev);
    }

    void remove(const Position& p) {
        p.node->prev->next = p.node->next;
        p.node->next->prev = p.node->prev;

        sz--;
        delete p.node;
    }

    void removeFirst() {
        remove(first());
    }

    void removeLast() {
        remove(last());
    }

    Position insertFirst(const T& o) {
        NodePtr node = new Node(o, header, header->next);
        header->next->prev = node;
        header->next = node;
        sz++;
        return Position(node);
    }

    Position insertLast(const T& o) {
        NodePtr node = new Node(o, trailer->prev, trailer);
        trailer->prev->next = node;
        trailer->prev = node;
        sz++;
        return Position(node);
    }

    void copyFrom(const NodeList<T>& nl) {
        sz = nl.sz;

        if (nl.sz > 0) {
            Position p0 = nl.first();
            Position p = insertFirst(p0.node->item);

            while (!nl.isLast(p0)) {
                p0 = nl.after(p0);
                insertAfter(p, p0.node->item);
            }
        }
    }

    void emptyList() {
        while (!isEmpty()) {
            removeFirst();
        }
    }

    ~NodeList() {
        emptyList();
        delete header;
        delete trailer;
    }

    NodeList<T>& operator=(const NodeList<T>& nl) {
        emptyList();
        copyFrom(nl);
    }

    NodeList(const NodeList<T>& nl) {
        emptyList();
        copyFrom(nl);
    }


void print() {
    if (size() > 0) {

        NodePtr n = header->next;
        while (n != trailer) {
            cout << n->item << "\t";
            n = n->next;
        }

        cout << endl;
    }

}


    void print1() {
    cout << "size is: " << size() << endl;

    ObjectIterator i = elements();

    while (i.hasNext()) {
        cout << i.next().element() << "\t";
    }
    cout << endl;
}


    ObjectIterator elements() {
    return ObjectIterator(header);
}

    void swapItems(const Position& p1, const Position& p2) {
        T temp = p1.node->item;
        p1.node->item = p2.node->item;
        p2.node->item = temp;

    }

};


int main()
{

	NodeList<int> obj;
	obj.insertFirst(10);
	obj.insertLast(20);
	obj.insertLast(30);
	obj.insertLast(40);
	obj.print();//normal
	obj.print1();//Iterator
	obj.removeFirst();
	obj.print();
	obj.print1();
return 0;

}
*/