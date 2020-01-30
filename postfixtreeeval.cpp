/*#include<iostream>
#include<stack>
#include<string>
using namespace std;

	struct Node
	{
		char data;
		Node *left;
		Node *right;
	};

	class PostfixToTree
	{
		Node *root;
		string postFixed;
		Node * createNode(char data)
		{
			Node *temp = new Node();
			temp->data = data;
			temp->left = temp->right = NULL;
			return temp;
		}
		void PostOrder(Node *nd)
		{
			if (nd != NULL)
			{
				PostOrder(nd->left);
				PostOrder(nd->right);
				cout << nd->data << " ";
			}
		}
		void PreOrder(Node *nd)
		{
			if (nd != NULL)
			{
				cout << nd->data << " ";
				PreOrder(nd->left);
				PreOrder(nd->right);
			}
		}
		void InOrder(Node *nd)
		{
			if (nd != NULL)
			{
				InOrder(nd->left);
				cout << nd->data << " ";
				InOrder(nd->right);
			}
		}
		Node* CreateNode(int data)
		{
			Node *temp = new Node();
			temp->left = temp->right = NULL;
			temp->data = data;
			return temp;
		}

		int Evaluate(Node *rt)
		{
			if (rt != NULL)
			{
				switch (rt->data)
				{
				case '+':return Evaluate(rt->left) + Evaluate(rt->right);
				case '-':return Evaluate(rt->left) - Evaluate(rt->right);
				case '*':return Evaluate(rt->left) * Evaluate(rt->right);
				case '/':return Evaluate(rt->left) / Evaluate(rt->right);
				default:
					int num;
					cout << "Enter a number for " << rt->data << " : ";
					cin >> num;
					return num;
				}

			}
			return -1;
		}
	public:
		PostfixToTree(string postFixed) :postFixed(postFixed)
		{
		}
		void FormTree()
		{
			stack<Node*> stk;
			for (int i = 0; i < postFixed.length(); i++)
			{
				Node* temp = createNode(postFixed[i]);
				if (!isalpha(postFixed[i]))
				{
					Node*tem = stk.top();
					temp->right = tem;
					stk.pop();
					tem = stk.top();
					temp->left = tem;
					stk.pop();
				}
				stk.push(temp);
			}
			root = stk.top();
			stk.pop();
		}
		void PostFix()
		{
			cout << "PostFix ------ : ";
			PostOrder(root);
			cout << endl;
		}
		void PreFix()
		{
			cout << "PreFix  ------ : ";
			PreOrder(root);
			cout << endl;
		}
		void InFix()
		{
			cout << "InFix   ------ : ";
			InOrder(root);
			cout << endl;
		}

		int Eval()
		{
			return Evaluate(root);
		}

	};



	int main()
	{
		PostfixToTree pft("abc*+d+");
		pft.FormTree();
		pft.PostFix();
		pft.PreFix();
		pft.InFix();
		cout << "Result=" << pft.Eval() << endl;
		return 0;
	}
	*/