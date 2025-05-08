#include<iostream>
using namespace std;
class A{
  public:
    int a;
    void get_value_of_a(){
      cout<<"Enter the value of a: "<<endl;
      cin>>a;
    }
};
class B: public A{
  public:
    int b;
    void get_value_of_b(){
      cout<<"Enter the value of b: "<<endl;
      cin>>b;
    }
};
class C:public B{
  public:
    int c;
    void get_value_of_c(){
      cout<<"Enter the value of c: "<<endl;
      cin>>c;
    }
    void get_sum(){
      cout<<"Sum of a,b and c is: "<<a+b+c<<endl;
    }
};

// const after the () tells the compiler “this method will not modify any member variables (unless they’re marked mutable) and can be called on const instances of the class.”
class Animal{
  public:
    string name;
    Animal(const string &n):name(n){}
   void   info()  const {
      cout<<"Animal name is: "<<name<<endl;
   }
};
class Mammal : public Animal
{
public:
   bool has_fur;
  Mammal(const string &n,bool fur):Animal(n),has_fur(fur){}
  void mammal_info() const {
    cout<<(has_fur?"Has fur":"Does not have fur")<<endl;
  }
} ;

class Dog:public Mammal
{

  public:
  string breed;
  Dog(const string &n,bool fur,const string &b):Mammal(n,fur),breed(b){}
  void dog_info() const{
    cout<<"Dog Breed is: "<<breed<<endl;
  }
  void bark() const{
    cout<<"Woof! Woof!"<<endl;
  }
};
int main()
{
  cout << "This is the simple example of multilevel inheritance." << endl;
  cout << "In this example class A is base class, class B is derived from class A and class C is derived from class B." << endl;
  C obj;
  obj.get_value_of_a();
  obj.get_value_of_b();
  obj.get_value_of_c();
  obj.get_sum();
  cout << "_________________________________________________________" << endl;
  cout<<"This is little complex example of multilevel inheritance."<<endl;
  cout<<"In this example class Animal is base class, class Mammal is derived from class Animal and class Dog is derived from class Mammal."<<endl;
  Dog dog("Buddy",true,"Golden Retriever");
  dog.info();
  dog.mammal_info();
  dog.dog_info();
  dog.bark();
  return 0;
}