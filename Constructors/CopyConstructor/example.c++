#include<iostream>
using namespace std;

class A{
  public:
  int x;
  A(){
    cout<<"Object of class A is formed"<<endl;
  }
};
int main(){
  cout<<"In this we are calling the implicit copy constructor .This creates shallow copy"<<endl;
  cout<<"but in this case it creates the deep copy because here we only copy the int x into the other object no"<<endl;
  cout<<" sharing of pointer "<<endl;
  cout<<"------------------------------------------------------------------------------------"<<endl;
  A a;
  a.x = 10;
  A a1(a);
  cout<<a1.x<<endl;
  a.x  = 13;
  cout<<a1.x;
  return 0;
}