#include<iostream>
using namespace std;
class Person{
  private:
      string name;
      int age;

  public:
  
  void setPersonName(string name){
    this->name = name;
  }
  void setPersonAge(int age){
    this->age = age;
  }
  void displayPerson(){
    cout<<"Name: "<<this->name<<endl;
    cout<<"Age: "<<this->age<<endl;
  }
};
int main(){
  cout<<"Encapsulation Setter Example:"<<endl;
  Person person1;
  person1.setPersonName("John Doe");
  person1.setPersonAge(30);
  person1.displayPerson();
  return 0;
}