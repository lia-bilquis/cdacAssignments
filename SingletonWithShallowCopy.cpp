#include <iostream>
using namespace std;

//Smart Pointer with Shallow Reference
class CA
{
 CA()
 {
 cout << "CA::CA()" << endl;
 }
 ~CA()
 {
 cout << "CA::~CA()" << endl;
 }
 //To create instance
 static CA *createInstance()
 {
 return new CA();
 }
 //To release instance
 static void ReleaseInstance(CA *Captr)
 {
 delete Captr;
 }

public:
 //Public Function
 void fun()
 {
 cout << "CA::fun()" << endl;
 }
 //Smart class made as friend
 friend class Smart;
};

//Smart class; Object of a class which acts like pointer of another class and manages memory
class Smart
{
 CA *caPtr; //CA Pointer
 int *count; 

public:
 //Normal Constructor
 Smart() : caPtr(CA::createInstance()), count(new int(1))
 {
 }

 //Copy Ctor
 Smart(const Smart &par) : caPtr(par.caPtr), count(par.count)
 {
 ++(*count);
 }

 //Overloading assignment operator
 Smart &operator=(Smart par)
 {
 std::swap(this->caPtr, par.caPtr);
 std::swap(this->count, par.count);
 return *this;
 }

 //Operator ->
 CA *operator->()
 {
 return caPtr;
 }

 //Smart D-tor
 ~Smart()
 {
 --(*count); //Decrement the count
 //cout << "count ="<< count <<" (*count) =" << (*count) << endl; //Uncomment this to find the diffrence; output will be `count =0x2020050 (*count) =1`
 if (0 == (*count))
 {
 CA::ReleaseInstance(caPtr);
 delete count;
 }
 }
};
int main()
{
 Smart sm1; //Smart object
 sm1->fun();
 Smart sm2(sm1); //Copy ctor invoked
 sm2->fun();
 Smart sm3;
 sm1 = sm3; //assignment operator
 /*
 Output :-
 CA::CA()
 CA::fun()
 CA::fun()
 CA::CA()
 CA::~CA()
 CA::~CA()
 */
 return 0;
}