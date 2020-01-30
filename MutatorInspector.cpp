#include<iostream>
#include<string>
using namespace std;
namespace mut_insp{
	class Employee
	{
		const int _eId;
		mutable int _salary;
		int _dept;
	public:
		static int EmpCount;
		static const int CompanyId;
		Employee(int eId) :_eId(eId), _salary(0), _dept(0)
		{
			EmpCount++;
		}
		Employee(int eId, int salary) :_eId(eId), _salary(salary), _dept(0)
		{
			EmpCount++;
		}
		Employee(int eId, int salary, int dept) :_eId(eId), _salary(salary), _dept(dept)
		{
			EmpCount++;
		}
		void DisplayEmployee() const //instance method
		{
			cout << "________________________________\n";
			cout << "EID     =" << _eId << endl;
			cout << "Salary  =" << _salary << endl;
			cout << "EmpCount=" << EmpCount << endl;
			cout << "CompanyId=" << CompanyId << endl;
			cout << "________________________________\n";
		}
		static void DisplayShared() //shared method
		{
			cout << "________________________________\n";
			cout << "EmpCount=" << EmpCount << endl;
			cout << "CompanyId=" << CompanyId << endl;
			cout << "________________________________\n";
		}
	};
	int Employee::EmpCount = 0;
	const int Employee::CompanyId = 12345;


	int main()
	{
		Employee *emp1 = new Employee(100, 2000, 10);
		emp1->DisplayEmployee();

		delete emp1;
		return 0;
	}

	}

