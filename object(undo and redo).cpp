/*#include<iostream>
#include<string>
#include<stack>
using namespace std;

	class Data
	{
		int Pid, Cid;
		string PName, CName;
		double PPrice, CPurchase;
	public:
		Data()
		{}

		void setCustomer(int id, string name, double Price)
		{
			CName = name;
			Cid = id;
			CPurchase = Price;
		}

		void setProduct(int id, string name, double Price)
		{
			PName = name;
			Pid = id;
			PPrice = Price;
		}

		void displayCustomer()
		{
			cout << "Customer Name  " << CName << endl;
			cout << "Customer ID  " << Cid << endl;
			cout << "Customer Purchase  " << CPurchase << endl;
		}
		void displayProduct()
		{
			cout << "Product Name  " << PName << endl;
			cout << "Product ID  " << Pid << endl;
			cout << "Product Price  " << PPrice << endl;
		}

	};

	class Command
	{

	public:
		virtual void Execute(Data& d) = 0;


	};

	class ProdectCommand :public Command
	{
	protected:
		int Pid;
		string PName;
		double PPrice;
	public:
		ProdectCommand(int Pid, string PName, double PPrice) :Pid(Pid), PName(PName), PPrice(PPrice)
		{

		}

		void Execute(Data& d)
		{
			d.setProduct(Pid, PName, PPrice);

		}

	};


	class CustomerCommand :public Command
	{
	protected:
		int  Cid;
		string CName;
		double CPurchase;
	public:
		CustomerCommand(int Cid, string CName, double CPurchase) :Cid(Cid), CName(CName), CPurchase(CPurchase)
		{

		}
		void Execute(Data& d)
		{
			d.setCustomer(Cid, CName, CPurchase);

		}

	};


	class Handler
	{
		Data &d;
		stack<Command*> stateC;
		stack<Command*> stateP;
	public:
		Handler(Data& d) :d(d)
		{}

		void setC(int Cid, string CName, double CPurchase)
		{
			Command *cc = new CustomerCommand(Cid, CName, CPurchase);
			cc->Execute(d);
			stateC.push(cc);
		}

		void displayC()
		{
			d.displayCustomer();
		}
		void displayP()
		{
			d.displayProduct();
		}
		void setP(int Pid, string PName, double PPrice)
		{
			Command *cc = new CustomerCommand(Pid, PName, PPrice);
			cc->Execute(d);
			stateP.push(cc);
		}
		void UndoC()
		{
			Command *cu = stateC.top();
			stateC.pop();
			cu->Execute(d);
		}
		void UndoP()
		{
			Command *pu = stateP.top();
			stateP.pop();
			pu->Execute(d);
		}
	};

	int main()
	{

		Data d;
		Handler h(d);
		h.setC(101, "Kaushal", 5000.5);
		h.setP(1, "Mango", 50.0);

		h.setC(105, "Akash", 8000);
		h.setC(107, "Amit", 10000);
		//h.displayC();
		h.setP(2, "Apple", 100.0);
		h.setP(3, "Orange", 70.0);
		h.UndoC();
		h.UndoC();
		h.UndoP();
		h.UndoP();
		h.UndoC();
		h.displayC();
		return 0;
	}
	*/