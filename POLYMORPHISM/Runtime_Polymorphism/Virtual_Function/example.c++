#include <iostream>
using namespace std;

class Base
{
public:
  virtual void show1()
  {
    cout << "[Late Binding] Base class show1() called (will be overridden if defined in Derived)\n";
  }

  void show2()
  {
    cout << "[Early Binding] Base class show2() called (non-virtual, so always resolved at compile time)\n";
  }

  virtual void show3()
  {
    cout << "[Late Binding] Base class show3() called (not overridden in Derived)\n";
  }

  virtual void show4()
  {
    cout << "[Late Binding] Base class show4() called (Derived defines an overload, not an override)\n";
  }
};

class Derived : public Base
{
public:
  void show1() override
  {
    cout << "Derived class show1() called  [Overrides Base::show1()] => Runtime Polymorphism (Late Binding)\n";
  }

  void show2()
  {
    cout << "Derived class show2() called — [Hides Base::show2()] => Early Binding (Compile-time)\n";
  }

  void show4(int i)
  {
    cout << "Derived class show4(int) called with i = " << i << "  [Overloading, not overriding Base::show4()]\n";
  }
};

int main()
{
  cout << "Program: Demonstrating Virtual Functions in C++\n\n";

  Base *ptr;
  Derived d;
  ptr = &d;

  cout << " Calling ptr->show1():\n";
  ptr->show1(); // Late binding → Derived::show1()

  cout << "\n Calling ptr->show2():\n";
  ptr->show2(); // Early binding → Base::show2()

  cout << "\n Calling ptr->show3():\n";
  ptr->show3(); // Late binding → Base::show3() (not overridden)

  cout << "\n  Calling ptr->show4():\n";
  ptr->show4(); // Late binding → Base::show4() (Derived only overloads with show4(int))

  // Illegal:
  // ptr->show4(5); // ERROR: Base* doesn't know about show4(int)

  return 0;
}
