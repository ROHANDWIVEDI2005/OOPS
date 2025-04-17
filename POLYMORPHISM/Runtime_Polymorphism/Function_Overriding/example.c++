#include <iostream>
using namespace std;

class Base
{
public:
  virtual void show()
  {
    cout << "Base class show function called." << endl;
  }
};

class Derived : public Base
{
public:
  void show() override
  {
    cout << "Derived class show function called." << endl;
  }
};

class Payment
{
public:
  virtual void pay()
  {
    cout << "Pay function called from base class Payment." << endl;
  }
};
class creditCard : public Payment
{
public:
  void pay() override
  {
    cout << "Pay function called from derived class creditCard." << endl;
  }
};

class debitCard : public Payment
{
public:
  void pay() override
  {
    cout << "Pay function called from the derived class debitCard." << endl;
  }

  void show(){
    cout<<"Show function called from derived class debitCard."<<endl;
  }
};
int main()
{

  Base *ptr;
  Derived d;

  // ❌ Undefined behavior (ptr not pointing to any object yet)
  // ptr->show();

  cout << "Calling show function using Derived class object." << endl;
  ptr = &d;
  ptr->show();

  cout << "----------------------------------------" << endl;
  cout << "Payment class function overriding." << endl;
  Payment *p;
  creditCard c;
  debitCard d1;
  p = &c;
  p->pay();
  p = &d1;
  p->pay();
  // ❌ ERROR: p->show() is invalid
  // 'show' is not a member of Payment class.
  // So base class pointer 'p' cannot access it.
  // To access 'show', you need to either:
  // - add a virtual show() function in Payment class, OR
  // - use a cast: static_cast<debitCard*>(p)->show();
  // p->show(); // This will call the base class pay function, not the derived class pay function.
  return 0;
}