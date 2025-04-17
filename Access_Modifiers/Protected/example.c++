#include<iostream>
using namespace std;

class Base{
  private:
    int a;
  protected:
    int b;
  public:
   int c ;
   void set(int x, int y, int z){
    cout<<"Base class set function"<<endl;
      this->a = x;
      this->b = y;
     this->c = z;  
   }
   void show(){
    cout<<"a: "<<this->a<<endl;
    cout<<"b: "<<this->b<<endl;
    cout<<"c: "<<this->c<<endl;
   }
};
class Derived: public Base{
  public:
    void set(int x, int y, int z){
      cout<<"Derived class set function"<<endl;
      // this->a = x; // Error: 'a' is private in 'Base'
      this->b = y; // OK: 'b' is protected in 'Base'
      this->c = z; // OK: 'c' is public in 'Base'
    }
};
int main(){
cout<<"Protected access modifier"<<endl;
Base b;
cout<<"This is base class"<<endl;
b.set(1, 2, 3); // OK: 'set' is public in 'Base'
b.show(); // OK: 'show' is public in 'Base'
Derived d;
cout<<"This is derived class"<<endl;
d.set(4, 5, 6); // OK: 'set' is public in 'Derived'
d.show(); // OK: 'show' is public in 'Base'
}