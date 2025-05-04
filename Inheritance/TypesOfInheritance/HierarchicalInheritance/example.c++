#include<iostream>
using namespace std;

class A{
  public:
    A(){
      cout<<"Constructor of class A"<<endl;
    }
};
class B : public A{
  public:
    B(){
      cout<<"Constructor of class B"<<endl;
    }
};
class C : public A{
  public:
    C(){
      cout<<"Constructor of class C"<<endl;
    }
};

class shape{
  
  public:
    string name;
    string sides;
     shape(string name, string sides){
      this->name = name;
      this->sides = sides;
      cout<<"Constructor of class shape"<<endl;
     }
};
class triangle : public shape{
  public:
  int base;
  int height;
  triangle(int height, int base): shape("Triangle", "3"){
    this->base = base;
    this->height = height;
    cout<<"Constructor of class triangle"<<endl;
  }
  void area(){
    cout<<"Area of triangle is :"<<(base*height)/2<<endl;
  }
  void show(){
    cout<<"Name of shape is : "<<name<<endl;
    cout<<"Number of sides are : "<<sides<<endl;
    cout<<"Base of triangle is : "<<base<<endl;
    cout<<"Height of triangle is : "<<height<<endl;
    area();
  }
};

class square : public shape{
  public:
  int length;
  square(int length): shape("Square", "4"){
    this->length = length;
    cout<<"Constructor of class square"<<endl;
  }
  void area(){
    cout<<"Area of square is :"<<length*length<<endl;
  }
  void show(){
    cout<<"Name of shape is : "<<name<<endl;
    cout<<"Number of sies are : "<<sides<<endl;
    cout<<"length of square is : "<<length<<endl;
    area();
  }
};

int main(){
  cout<<"This is the simple example of Hierarchical Inheritance."<<endl;
  cout<<"calling from class B"<<endl;
  B b;
  cout<<"calling from class C"<<endl;
  C c;
  cout<<"___________________________________________________"<<endl;

  cout<<"This exaple give brief understanding of Hierarchical Inheritance."<<endl;
  triangle t(5, 10);
  t.show();
  cout<<"___________________________________________________"<<endl;
  square s(5);
  s.show();


  return 0;
}