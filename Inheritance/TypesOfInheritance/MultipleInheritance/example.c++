#include<iostream>
using namespace std;

class A{
  public:
    A(){{
    cout<<"Constructor of class A"<<endl;
    }}
};
class B{
  public:
    B(){{
    cout<<"Constructor of class B"<<endl;
    }}
  };
class C: public A, public B{

  public:
    C(){{
    cout<<"Constructor of class C"<<endl;
    }}
};


// In this example the constructor of class Person is called two times if we don't use virtual inheritance.
class Person{
   public:
      Person(){
          cout<<"Constructor of class Person"<<endl;
      }
      Person(int x){
          cout<<"Constructor of class Person with parameter: "<<x<<endl;
      }
};  

class Student: virtual public Person{
    public:
        Student(){
            cout<<"Constructor of class Student"<<endl;
        }
        // >>>Base() runs (the default constructor)
        // >>> Derived() body runs
        //     If Base had no default constructor(only Base(int)),
        //     the compiler would error—because it wouldn’t know what arguments to pass.
        Student(int x): Person(x){
            cout<<"Constructor of class Student with parameter: "<<x<<endl;
        }
    };

    class Teacher:virtual public Person{
        public:
            Teacher(){
                cout<<"Constructor of class Teacher"<<endl;
            }
            // >>>Base() runs (the default constructor)
            // >>> Derived() body runs
            //     If Base had no default constructor(only Base(int)),
            //     the compiler would error—because it wouldn’t know what arguments to pass.
                Teacher(int x) : Person(x)
            {
              cout << "Constructor of class Teacher with parameter: " << x << endl;
            }
        };
    class TA: public Student, public Teacher{
        public:
            TA(){
                cout<<"Constructor of class TA"<<endl;
            }

            TA(int x): Student(x), Teacher(x), Person(x){
                cout<<"Constructor of class TA with parameter: "<<x<<endl;
            }
        };

int main(){
  cout<<"This is the basic example of multiple inheritance in C++."<<endl;
  C obj; // Creating an object of class C

  cout<<"______________________________________________________"<<endl;
  cout<<"This is the classical example of multiple inheritance without diamond problem."<<endl;
  TA s1(10); // Creating an object of class Student
  return 0;
}