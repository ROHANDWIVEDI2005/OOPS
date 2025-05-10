#include<iostream>
using namespace std;
class Base{
  public:
    virtual void show() = 0; // pure virtual function
    virtual void display(){
      cout << "Base class display function" << endl;
    }
};
class Derived: public Base{
 public:
  //  Because your member function has the same name, parameter‑list and const‑qualification as the base’s pure virtual display(), the compiler will still treat it as an override and your program behaves exactly the same at run‑time : 
   
   void show() override
   {
     cout << "Derived class show function" << endl;
   }
    // void display(){
    //   cout << "Derived class display function" << endl;
    // }
};
int main(){
  Base *b; // base class pointer
  Derived d; // derived class object
  b = &d; // base class pointer pointing to derived class object
  b->show(); // calling derived class show function
  b->display(); // calling derived class display function
  return 0;
}

//    Because Derived publicly inherits from Base, every Derived object is a Base object.

//     C++ lets you implicitly convert a Derived *to a Base *so you can treat derived objects through base pointers.

//     Declaring
//     display() as virtual in Base means calling it via a Base *runs the Derived version at runtime.

//     This design makes it easy and safe to use polymorphism.