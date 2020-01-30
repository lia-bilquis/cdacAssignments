/*#include<iostream>

#include<string>

using namespace std;

class Queue

{

	static Queue *front;

	static Queue *rear;

	Queue *next;

	int data;

     bool IsEmpty()

	{

		return front==NULL;

	}

	
	
        public:

	Queue():next(NULL)

	{

	}

	Queue(int data):data(data)

	{

		if(IsEmpty())

		{

			front=this;

			rear=this;

			next=NULL;

		}

		else

		{
			rear->next=this;

			next=NULL;

			rear=this;

		}

	}

	void Display()

	{

		cout<<"___________________Queue Contents_____________________\n";

		for(Queue *trav=front;trav!=NULL;trav=trav->next)

		cout<<trav->data<<'\n';

		cout<<"________________________________________________________\n";

	}

	void Push(int data)

    {

	     new Queue(data);

    }

    int Pop()

    {

    	int data=front->data;

    	cout<<"The poped element is : "<<data<<"\n";

    	Queue *temp=front;

    	front=front->next;

    	temp->next=NULL;

    	return data;

    }

    void Release()

    {

        delete front;

    	front=NULL;

    	rear=NULL;

    }

    ~Queue()

    {

    	if(!IsEmpty())

    	{

    	cout<<"Releasing Data : "<<data<<endl;

    	if(next!=NULL)

    		delete next;

    	}

    }
 
};
Queue* Queue::front=NULL;

Queue* Queue::rear=NULL;



int main()

{

	Queue que;

	que.Push(10);

	que.Push(20);

	que.Push(30);

	que.Push(40);

	que.Push(50);

	que.Display();

	que.Pop();

	que.Pop();

	cout<<"_________________________________________________\n";

	que.Release();

	cout<<"_________________________________________________\n";

	return 0;

}*/