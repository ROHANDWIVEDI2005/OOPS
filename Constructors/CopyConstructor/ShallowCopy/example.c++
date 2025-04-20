#include<iostream>
using namespace std;
class A{
  int*ptr;
  public:
  A(int data){
    ptr = new int(data);
    cout<<"Constructor is called and the int value assigned : "<<* ptr<<endl;
  }
  //   - const   → promises not to modify 'other' inside this constructor

  A(const A& old_obj){
    ptr = old_obj.ptr;
    cout<<"Copy constructor is called and int value assigned is :"<<*ptr<<endl;
  }
  void set_value(int value){
     *ptr = value;
     cout<<"The set_value function is called and int value assigned is :"<<*ptr<<endl;
  }
  // const help to prevent the modification in the base value but we can read the value and access its data but can not modify it
  void display()const{
    cout<<"The display value:"<<*ptr<<endl;
  }
  ~A(){
    delete ptr;
    cout<<"Desctructor is called"<<endl;
  }
};
int main(){
     A obj1(100);
     A obj2(obj1);
     cout<<"----------------------------------------------"<<endl;
     cout<<"obj1 display function is called"<<endl;
     obj1.display();
     cout<<"obj2 display function is called"<<endl;
     obj2.display();
     cout << "----------------------------------------------" << endl;
    cout<<"Set value only for the obj1"<<endl;
     obj1.set_value(30);
     cout << "----------------------------------------------" << endl;
     cout << "obj1 display function is called" << endl;
     obj1.display();
     cout << "obj2 display function is called" << endl;
     obj2.display();
     return 0;
}