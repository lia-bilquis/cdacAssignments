/*#include <iostream>
using namespace std;

//Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{
    Node *root;

    //Creating Node
    Node *CreateNode(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    //PostOrder
    void PostOrder(Node *n1)
    {
        if (n1 != NULL)
        {
            PostOrder(n1->left);
            PostOrder(n1->right);
            cout << n1->data << '\t';
        }
    }

    //PreOrder
    void PreOrder(Node *n1)
    {
        if (n1 != NULL)
        {
            cout << n1->data << '\t';
            PreOrder(n1->left);
            PreOrder(n1->right);
        }
    }

    //InOrder
    void InOrder(Node *n1)
    {
        if (n1 != NULL)
        {
            InOrder(n1->left);
            cout << n1->data << '\t';
            InOrder(n1->right);
        }
    }

    //This function transverse in post order deleting every node in tree
    void DeleteTree(Node *n1)
    {
        if (n1 != NULL)
        {
            //Whole subtree is deleted
            DeleteTree(n1->left);
            DeleteTree(n1->right);
            /* then delete the node */
        /*    cout << "Releasing " << n1->data << endl;
            delete n1;
        }
    }

public:
    BST() : root(NULL)
    {
    }

    //Insert
    void Insert(int data)
    {
        Node *temp = CreateNode(data);
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            Node *trav1, *trav2;
            trav1 = trav2 = root;
            while (trav1 != NULL)
            {
                trav2 = trav1;
                trav1 = data <= trav1->data ? trav1->left : trav2->right; //finding correct Null position for data in tree
            }
            if (data <= trav2->data)
                trav2->left = temp;
            else
            {
                trav2->right = temp;
            }
        }
    }

    //Print Post Order
    void PrintPost()
    {
        cout << " Post Order" << endl;
        PostOrder(root);
        cout << endl;
    }

    //Print Pre Order
    void PrintPre()
    {
        cout << " Pre Order" << endl;
        PreOrder(root);
        cout << endl;
    }

    //Print In Order
    void PrintIn()
    {
        cout << " In Order" << endl;
        InOrder(root);
        cout << endl;
    }

    //Delete Least value
    void DeleteLeast()
    {
        Node *trav1, *trav2;
        trav1 = trav2 = root;
        while (trav1->left)
        {
            trav2 = trav1;
            trav1 = trav1->left;
        }
        trav2->left = NULL;
        cout << "Deleting Least " << trav1->data << endl;
        delete trav1;
    }

    //Delete Maximum value
    void DeleteMax()
    {
        Node *trav1, *trav2;
        trav1 = trav2 = root;
        while (trav1->right)
        {
            trav2 = trav1;
            trav1 = trav1->right;
        }
        trav2->right = NULL;
        cout << "Deleting Maximum " << trav1->data << endl;
        delete trav1;
    }

    ~BST()
    {
        //Delete all node in  heap
        DeleteTree(root);
    }
};

int main()
{
    int arr[] = {10, 5, 7, 3, 25, 15, 30};
    BST bst;
    for (int i=0;i<sizeof(arr);i++) //c++11 range loops
    {
        bst.Insert(arr[i]);
    }
    bst.PrintIn();
    bst.PrintPost();
    bst.PrintPre();
    bst.DeleteLeast();
    bst.PrintIn();
    bst.DeleteMax();
    bst.PrintIn();
    return 0;
}*/