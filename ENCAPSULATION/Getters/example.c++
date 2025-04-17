#include<iostream>
using namespace std;

class Person{
  private:
     string name;
     int age;
  public:
  Person(){
    name = "John Doe";
    age = 30;
  }

  int getPersonAge(){
    return  this->age;
  }
  string getPersonName(){
    return this->name;
  }
};
int main(){
  cout<<"Encapsulation Getter Example"<<endl;
  Person person1;
  cout<<"Name: "<<person1.getPersonName()<<endl;
  cout<<"Age: "<<person1.getPersonAge()<<endl;
  return 0;

}