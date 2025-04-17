#include <iostream>
using namespace std;

class Complex
{
private:
  int real, img;

public:
  Complex(int r = 0, int i = 0) : real(r), img(i) {}

  //   Complex&	      : Reference to a modifiable Complex object (can be changed)
  //   const Complex	: A constant Complex value (copied, can't be changed)
  //   Complex const&	: A reference to a constant Complex (efficient & safe)

  // You 're declaring a non-member function that can access the private/protected members of the Complex class, and you' re overloading the + operator for objects of that class.
  // A non-member function is a function that is not part of a class's scope — it’s defined outside the class. However, it can still interact with class objects (and even access private members if declared as a friend).

  friend Complex operator+(Complex const &obj1, Complex const &obj2);

  void print()
  {
    cout << "This is the example of operator overloading" << endl;
    cout << "Sum of Complex Numbers :" << real << " + i" << img << endl;
  }
};

// this is the friend function for the overloaded operator+
// It takes two Complex objects as arguments and returns a new Complex object that represents the sum of the two input objects.
Complex operator+(Complex const &obj1, Complex const &obj2)
{
  return Complex(obj2.real + obj1.real, obj1.img + obj2.img);
}

class Fraction
{
private:
  int num, deno;

public:
  Fraction(int n = 0, int d = 1) : num(n), deno(d) {}

  // C++ gets confused, because operator float already means "return a float".
  // So writing float again is redundant and invalid.
  operator float() const
  {
    return float(num) / float(deno);
  }
};

class Point
{
private:
  int x, y;

public:
  Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
  void Print()
  {
    cout << "Point is : (" << x << "," << y << ")" << endl;
  }
};
int main()
{
  Complex c1(10, 5), c2(2, 4);
  Complex c3;
  c3 = c1 + c2; // Calls the operator+ function
  c3.print();
  cout << "----------------------------------------" << endl;
  cout << "This is the example of Conversion Operato overloading" << endl;
  Fraction f1(3, 4);
  float result = f1;
  cout << "Fraction as float for f1 is :" << result << endl;

  cout << "----------------------------------------" << endl;
  cout << "This is the example of Conversion Constructor which only take one argument "<<endl;
  Point p1(3, 2);
  p1 = 30;
  p1.Print();
  return 0;
}