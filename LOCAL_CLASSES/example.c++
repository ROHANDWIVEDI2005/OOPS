#include<iostream>
using namespace std;

void function(){
  cout<<"Enter into function"<<endl;
  static int x = 10; // Static variable
  enum Color {Red, Green, Blue}; // Enum
  int y = 20; // Local variable
  class LocalClass{
    public:
      // This will throw error becauseA Local class cannot contain static data members. It may contain static functions though.
      // static int x = 10; // Static variable
      LocalClass(){
        cout<<"Inside first LocalClass constructor an instance of first LocalClass is created in the enclosing function"<<endl;
      }
      void display1();
      static void display2(){
        cout<<"Inside the static function display2 of LocalClass"<<endl;
      }
      static void display3();
      void display4(){
        cout<<"Inside the LocalClass display4 function and accessing static and enum values of its enclosing function"<<endl;
        cout<<"The value of x is: "<<x<<endl; // Accessing static variable
        // This will throw error because Local class cannot access local variables of the function in which it is defined.
        // cout<<"The value of y is: "<<y<<endl; // Accessing local variable
        cout<<"Color: "<<Red<<endl; // Accessing enum
      }

  };
 
  class LocalClass2{
    LocalClass obj;
    public:
      LocalClass2(){
        cout<<"Inside second LocalClass constructor an instance of second LocalClass is created in the enclosing function"<<endl;
        // Local classes can access other local classes of the same function
        cout << "And before this you will   first local class constructor is called" << endl;
      }
      void display(){
        cout<<"Inside the display function of LocalClass2"<<endl;
      }
  };
  LocalClass LocalObj;
  LocalObj.display2();
  LocalObj.display4(); // Accessing the display4 function of LocalClass
  // This will because all the methods of Local classes must be defined inside the class only.
  // void LocalClass::display1(){
  //   cout<<"Function declared outside the class but defined inside the function"<<endl;
  // }
  // void LocalClass::display3(){
  //   cout<<"Function declared outside the class but defined inside the function"<<endl;
  // }
 cout<<"--------------------------"<<endl;
  LocalClass2 LocalObj1;
  LocalObj1.display();
  cout<<"Exiting function"<<endl;
}
int main(){
  cout<<"Local class example"<<endl;
  cout<<"-------------------------"<<endl;
  function();
  // LocalClass mainObj; // This will cause an error because LocalClass is not visible here

  return 0;
}
