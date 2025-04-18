#include<iostream>
using namespace std;

class Demo{
  public:
    static int x;
    static void show(){
      cout<<"Static member function show() called inside the class Demo"<<endl;
    }
    static void show1();
};

void Demo::show1(){
  cout<<"static member function show1() called outside the class Demo"<<endl;
}
// This cause error : You’re not allowed to define the same function body twice.

// void Demo::show(){
//   cout<<"Static member function show() called outside the class Demo"<<endl;
// }
int main(){
  cout<<"accessing static members functions without declaring the class object"<<endl;
  Demo::show(); // calling static member function inside the class
  Demo::show1(); // calling static member function outside the class
  cout<<"------------------------------------------------------"<<endl;
  cout<<"accessing static members functions using class object"<<endl;
  Demo d1; // creating object of class Demo
  d1.show(); // calling static member function using object of class Demo
  d1.show1(); // calling static member function using object of class Demo
  return 0;
}