#include <iostream>
using namespace std;

//Shallow copy with ownership transfer
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
    //Create Instance
    static CA *createInstance()
    {
        return new CA;
    }
    //Release Instance
    static void releaseInstance(CA *ptr)
    {
        delete ptr;
    }

public:
    void fun()
    {
        cout << "CA::fun()" << endl;
    }
    //Smart Made friend
    friend class Smart;
};
//Smart class; Object of a class which acts like pointer of another class and manages memory
class Smart
{
    //Our CA pointer
    CA *CaPtr;
    //prevent Smart pointer to be created on heap segment
    static void *operator new(size_t size)
    {
        return 0;
    }
    static void *operator new[](size_t size)
    {
        return 0;
    }
    static void operator delete(void *)
    {
    }
    static void operator delete[](void *)
    {
    }

public:
    //Ctor
    Smart() : CaPtr(CA::createInstance())
    {
    }
    //Ownership transfer
    Smart(const Smart &par) : CaPtr(par.CaPtr)
    {
        cout << &par << " transfered Captr=" << CaPtr << " Ownership to " << this << endl;
        Smart &smart = const_cast<Smart &>(par);
        smart.CaPtr = NULL;
    }
    //Lets overload -> operator
    CA *operator->()
    {
        return CaPtr;
    }
    //Lets overload = operator now :D
    Smart &operator=(Smart par)
    {
        std::swap(this->CaPtr, par.CaPtr);
        return *this;
    }
    //D-tor
    ~Smart()
    {
        cout << this << " Releasing CaPtr=" << CaPtr << '\n';
        delete CaPtr;
    }
};
int main()
{
    Smart sm1;      //Smart object
    sm1->fun();     // function
    Smart sm2(sm1); //sm1 loses ownership(Captr = NULL) and sm2 will be the new owner of CaPtr
    sm1 = sm2;      //copy swap happens here; sm2 is copied to par in overloaded function using ownership transfer; par is the owner of CA now(CA ptr in sm2 is null after transfer);swapping occur between sm1(previously had Captr NULL) and par; making sm1 the owner of Captr;par released in return statement.So to sum up sm1 is the owner of captr, sm2 has captr = null :'(

    /*
        Output:-
        CA::CA() ;line87
        CA::fun() ;line88
        0x7fff2cb3d0d0 transfered Captr=0x6adc20 Ownership to 0x7fff2cb3d0e0 ;line89
        0x7fff2cb3d0e0 transfered Captr=0x6adc20 Ownership to 0x7fff2cb3d0f0  ;line90 copied to par in line 73
        0x7fff2cb3d0f0 Releasing CaPtr=0 ;line66 our hero par dies out :(
        0x7fff2cb3d0e0 Releasing CaPtr=0 ;line 104 sm2 relased first
        0x7fff2cb3d0d0 Releasing CaPtr=0x6adc20; line 104 sm1 is released !!
        CA::~CA()
 
    */
    return 0;
}