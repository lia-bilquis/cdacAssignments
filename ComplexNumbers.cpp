#include<iostream>
using namespace std;

class Complex
{
double _real;
double _imag;
public:
Complex(double real = 0.0, double imag = 0.0) :_real(real), _imag(imag)
{
}

Complex operator+(const Complex& par)
{
return Complex(this->_real + par._real, this->_imag + par._imag);
}

operator double() //casting double operator
{
return _real + _imag;
}

friend Complex operator+(int x,const Complex & par) //casting operator
{
return Complex(par._real + x, par._imag);
}

void operator ++() //prefix ++
{
this->_real++;
}

void operator ++(int) //posfix ++
{
this->_imag++;
}

friend Complex operator+(Complex &par,int x)
{
return Complex(par._real, par._imag + x);
}

friend ostream& operator<<(ostream & os, Complex & par)
{
os << par._real << (par._imag >= 0.0 ? "+" : "") << par._imag << "i" << endl;
return os;
}

friend istream& operator>>(istream & is, Complex & par)
{
is >> par._real >> par._imag ;
return is;
}

Complex operator *(void) //casting operator
{
return *this;
}
};

int main()
{
Complex c1;
Complex c2;
cin >> c1;
cin >> c2;
cout << c1;
cout << c2;
cout << "__________________________\n";

Complex c3 = c1 + c2;
Complex c5 = c1 + 10;//10 to be added to the imaginary
Complex c4 = 10 + c1;//10 to be added to the real
c3++;//to increment Imaginary by 1.0
++c3;//to increment real by 1.0
Complex *ptr = c3;
double magnitude = c3;
cout << c3 << "Magnitude " << magnitude << "\n";
return 0;
}