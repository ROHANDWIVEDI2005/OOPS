#include<iostream>
using namespace std;
void f1(){
  cout<<"f1 starts"<<endl;
  throw 100;
  cout<<"f1 ends"<<endl;
}
void f2(){
  cout<<"f2 starts"<<endl;
  f1();
  cout<<"f2 ends"<<endl;
}
void f3(){
  try
  {
    f2();
  }
  catch(const int i)
  {
    cout<<"caught exception :"<<i<<endl;
  }
  catch(const char *msg)
  {
    cout<<"caught exception :"<<msg<<endl;
  }
  catch(const string &s)
  {
    cout<<"caught exception :"<<s<<endl;
  }
  catch(int i)
  {
    cout<<"caught exception :"<<i<<endl;
  }
  cout<<"f3 ends"<<endl;
}
int main(){
  // This example help you to understand the stack unwinding
  f3();
  return 0;
}