#include<iostream>
using namespace std;

class Base; // forward definition needed
// another class in which function is declared
class anotherClass
{
public:
  void show(Base &b);
};

class Base{
  private:
     int privateNum;
  protected:
      int protectedNum;
  public:
    int publicNum;
    Base(){
      privateNum = 1;
      protectedNum = 2;
      publicNum = 3;
      cout<<"Base constructor called"<<endl;
      cout << "Intializing privateNum = " << privateNum << endl;
      cout<<"Intializing protectedNum = " << protectedNum << endl;
      cout<<"Intializing publicNum = " << publicNum << endl;
    }
    friend void show(Base &b);
    friend void anotherClass::show(Base &b);
};

  void anotherClass::show(Base &b)
  {
    cout << "Friend function called in the friend function of other class" << endl;
    cout << "Base privateNum = " << b.privateNum << endl;
    cout << "Base protectedNum = " << b.protectedNum << endl;
    cout << "Base publicNum = " << b.publicNum << endl;
  }

 void show(Base &b){
      cout<<"Friend function called"<<endl;
      cout<<"Base privateNum = " << b.privateNum << endl;
      cout<<"Base protectedNum = " << b.protectedNum << endl;
      cout<<"Base publicNum = " << b.publicNum << endl;
 }
int main(){
  cout<<"Friend Function of another class and global function"<<endl;
  Base b;
  cout<<"---------------------------------------------------"<<endl;
  anotherClass a;
  a.show(b); // calling friend function of another class
  cout << "---------------------------------------------------" << endl;

  show(b); // calling friend function of global scope
  return 0;
}