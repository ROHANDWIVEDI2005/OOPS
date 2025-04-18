#include<iostream>
using namespace std;

class A{
  public:
    // This gives us error we can we can only declare static data members inside the class but have to define and assign value outside the class due to class rules this is because static data members values can not be assigned using constructor
    // static int x = 2;
    static int x; // Declaration of static data member
    A(){
      cout<<"Constructor is  called"<<endl;
    }
};
int A::x=2;

class setNumber{
   public:
     int a;
      setNumber(int x = 10):a(x){
        cout<<"Constructor is called of class setNumber"<<endl;
      }
};

class b{
  public:
    static setNumber x;
    b(){
      cout<<"Constructor is called of class b"<<endl;
    }
};
// 🔹 Step-by-Step Explanation:
// 1. setNumber
// This is the type of the static member s. Think of it like a class or structure.
// 2. b::x
// This is how we refer to the static variable x that belongs to class b.The b::part means "this variable is a member of class b".
// 3. = setNumber(11);
// This is creating a new object of type setNumber with the value 30 passed to its constructor.
// Now x is a static member of class b, and it is initialized with a new object of type setNumber. This means that x will hold an object of type setNumber, and you can access its members using the dot operator.
setNumber b::x = setNumber(30); // Definition and initialization of static data member
int main(){
  cout<<"Accessing the static data members without creating the object of class A"<<endl;
  cout<<A::x<<endl; // Accessing static data member using class name
  cout<<"---------------------------------------------------------"<<endl;
  cout<<"Accessing the static data members using object of class A"<<endl;
  A a; // Creating object of class A
  cout<<a.x<<endl;
  cout << "---------------------------------------------------------" << endl;
  cout<<"Accessing the static data members of class b without initializing the object of class b"<<endl;
  cout<<b::x.a<<endl; // Accessing static data member using class name
  cout<<"---------------------------------------------------------" << endl;
  cout<<"Accessing the static data members of class b using object of class b"<<endl;
  b b1; // Creating object of class b
  cout<<b1.x.a<<endl; // Accessing static data member using object of class b
  return 0;
}