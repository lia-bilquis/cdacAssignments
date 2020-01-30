#include<iostream>
using namespace std;
namespace nm
{
	//----- vendor 1 Socket
	namespace Sachin
	{
		void SetSocket()
		{

		}
		void Connect()
		{

		}
	}

	//-----vendor 2 DbLibrary
	namespace Saurav
	{
		void InitDB()
		{

		}
		void Connect()
		{

		}
	}

	int main1()
	{
		Sachin::SetSocket();
		Saurav::InitDB();
		Sachin::Connect();
		Saurav::Connect();
		return 0;
	}


	int main2()
	{
		using Sachin::SetSocket;
		using Saurav::InitDB;
		SetSocket();
		InitDB();
		Sachin::Connect();
		Saurav::Connect();
		return 0;
	}

	int main3()
	{
		using namespace Sachin;
		using Saurav::InitDB;
		SetSocket();
		InitDB();
		Connect();
		Saurav::Connect();
		return 0;
	}


	namespace Sunil
	{
		int i = 100;
		int j = 200;
	}
	namespace Kapil
	{
		using namespace Sunil;
		int a = 888;
		int b = 999;
	}

	int main4()
	{
		using namespace Kapil;
		cout << "i=" << i << endl;
		cout << "j=" << j << endl;
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		return 0;
	}


	namespace Rahul
	{
		int i = 100;
		int j = 200;
	}
	namespace Rahul
	{
		int a = 888;
		int b = 999;
	}

	int main5()
	{
		using namespace Rahul;
		cout << "i=" << i << endl;
		cout << "j=" << j << endl;
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		return 0;
	}


	namespace Viru
	{
		int i = 100;
		int j = 200;
		namespace Sewag
		{


			int a = 888;
			int b = 999;
		}
	}

	int main6()
	{
		using namespace Viru;
		using namespace Viru::Sewag;
		cout << "i=" << i << endl;
		cout << "j=" << j << endl;
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		return 0;
	}


	namespace VVS
	{
		namespace Laxman
		{
			int i = 100;
			int j = 200;
			int a = 888;
			int b = 999;
		}
	}


	int main()
	{
		using namespace VVS::Laxman;
		cout << "i=" << i << endl;
		cout << "j=" << j << endl;
		cout << "a=" << a << endl;
		cout << "b=" << b << endl;
		return 0;
	}

}
