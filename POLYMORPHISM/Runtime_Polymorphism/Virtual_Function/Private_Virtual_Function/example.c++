#include<iostream>
using namespace std;
// The access specifier decide the visibility of the member functions and data variables at the compile time .
// They dont affect the run time behaviour of the program.
// Thats why the private virtual function of the derived class is called by the pointer.
class Base{
public:
  Base(){
    cout<<"Base class constructor is called"<<endl ;
  }
  void show(){
    cout<<"Base class print function is called"<<endl ;
  }
  virtual void print(){
    cout<<"Base class virtual print function is called"<<endl ;
  }
};
class Derived:public Base{
public:
  Derived(){
    cout<<"Derived class constructor is called"<<endl ;
  }
  void show(){
    cout<<"Derived class print function is called"<<endl ;
  }
  private:
  void print(){
    cout<<"Derived class virtual print function is called"<<endl ;
  }

};
int main(){
  // You declare Base* b; but never point it at a valid object before calling b->show(). Dereferencing an uninitialized pointer is undefined behavior. You must initialize b (for example, to point at a real Base or Derived object) before you call any member on it.

  Base *b;
  b->show(); // calling base class print function
  // b->print(); // calling base class virtual print function
  Derived d;
  b = &d;
  b->show();  // calling derived class show function
  b->print(); // calling base class print function
  d.show();   // calling derived class show function
  delete b;
  return 0;
}