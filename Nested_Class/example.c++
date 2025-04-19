#include<iostream>
using namespace std;

class outer{
  private:
  int x = 10;
  public:
  outer (){
    cout<<"object of outer class if formed : this is the default constructor"<<endl;
  }
  class inner{
    private:
    int y = 23;
  public:
  inner(){
    cout<<"object of the inner class (This is declared inside the inner class)is formed  : this is the default constructor of inner class"<<endl;
  }

  void display(outer&e){
    cout<<"This is the display method of the inner class and  Access the private value of outer class variable x :"<<e.x<<endl;
  }
 

  };
  // This will through an error becasue we can not access the private methods and variables of the inner class but the inner class can do of outer class.
  // void display_outer(inner&e){
  //   cout<<"This is the display method of the outer class and accessing the private value of inner class variable y:"<<e.y<<endl;
  // }
  class inner1;
};
class outer:: inner1{
 public:
 inner1(){
   cout << "object of the inner1 class (Declared outside the class) : This is the default constructor" << endl;
 }

};
int main(){
  cout<<"Nested classes Explained"<<endl;
  cout<<"--------------------------------------"<<endl;
  outer obj;
  cout << "--------------------------------------" << endl;
  outer::inner obj1;
  cout << "--------------------------------------" << endl;
  outer::inner1 obje2;
  cout<<"--------------------------------------"<<endl;
  obj1.display(obj);
  return 0;
}