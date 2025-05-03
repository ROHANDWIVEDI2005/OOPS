#include<iostream>
using namespace std;
class A{
   private:
   int *ptr;
   public:
   A(int data){
    ptr = new int(data);
    cout<<"Constructor is called and the value assigned is :"<<*ptr<<endl;
   }
   //   - const   → promises not to modify 'other' inside this constructor

   A(const A&obj){
     ptr = new int(*obj.ptr); // In this we dont assign the pointer but the value associated with it only
     cout<<"Deep copy constructor is called and the value assigned is:"<<*ptr<<endl;
   }

   void dispaly(){
    cout<<"The value is :"<<*ptr<<endl;
   }
   // const help to prevent the modification in the base value but we can read the value and access its data but can not modify it
   void set_value(int data)const
   {
    *ptr = data;
    cout<<"the set_vlaue function is called and value set is :"   <<*ptr<<endl;
   }
   ~A(){
    delete ptr;
    cout<<"distructor is called"<<endl;
   }
};
int main(){
  A obj1(12);
  A obj2(obj1);
  cout<<"----------------------------------------------------"<<endl;
  cout<<"Display function called for the obj1"<<endl;
  obj1.dispaly();
  cout<<"Dispaly function called for the obj2"<<endl;
  obj2.dispaly();
  cout<<"----------------------------------------------------"<<endl;
  cout<<"Value of the obj1 is changed "<<endl;
  obj1.set_value(34);
  cout<<"----------------------------------------------------"<<endl;

  cout << "Display function called for the obj1" << endl;
  obj1.dispaly();
  cout << "Dispaly function called for the obj2" << endl;
  obj2.dispaly();

  return 0;
}