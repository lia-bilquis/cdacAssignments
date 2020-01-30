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
class Smart
{
    CA *captr;
    //To prevent smart objects creation on heap
    static void *operator new(size_t size)
    {
        return NULL;
    }
    static void *operator new[](size_t size)
    {
        return NULL;
    }
    static void operator delete(void *)
    {
    }
    static void operator delete[](void *)
    {
    }

public:
    //Ctor
    Smart() : captr(CA::createInstance())
    {
    }

    //Copy Ctor with deep copy
    Smart(const Smart &par) : captr(CA::createInstance())
    {
        cout << this << " Created Deep Copied  captr=" << captr << " From " << &par << '\n';
    }

    //overload ->
    CA *operator->()
    {
        return captr;
    }

    //Overload =
    Smart &operator=(Smart par)
    {
        std::swap(this->captr, par.captr);
        return *this;
    }

    //D-tor
    ~Smart()
    {
        cout << this << " Releaseing ptr=" << captr << endl;
        CA::releaseInstance(captr);
    }
};

int main()
{
    Smart sm1;
    Smart sm2(sm1);
    sm1 = sm2;
    /*
        CA::CA() ;line 88 sm1
        CA::CA() ;line 60 sm2
        0x7ffeeeef6d50 Created Deep Copied  captr=0x1663050 From 0x7ffeeeef6d40
        CA::CA() ;line 72 par
        0x7ffeeeef6d60 Created Deep Copied  captr=0x1663070 From 0x7ffeeeef6d50
        0x7ffeeeef6d60 Releaseing ptr=0x1662c20 ; line 75
        CA::~CA() ; line 75 after release of par
        0x7ffeeeef6d50 Releaseing ptr=0x1663050 ;sm2 release
        CA::~CA()
        0x7ffeeeef6d40 Releaseing ptr=0x1663070 ; sm1 release
        CA::~CA()
*/
    return 0;
}