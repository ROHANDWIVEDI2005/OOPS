#include <iostream>
#include <string>
using namespace std;
  // ctor = constructor
    // dtor = destructor
    //------------------------------------------------------------------------------
    // Employee class demonstrates all parameterized‑constructor concepts
    //------------------------------------------------------------------------------
    class Employee
{
  int id;
  string name;
  double salary;

public:
  // 1) Default constructor
  //    - If you omit this, and only define the parameterized one,
  //      `Employee e;` will fail to compile.
  Employee()
      : id(0), name("Unknown"), salary(0.0) // default values via initializer list
  {
    cout << "[Default ctor] Employee() called:\n"
         << "               id=" << id
         << ", name=\"" << name
         << "\", salary=" << salary
         << "\n\n";
  }

  // 2) Parameterized constructor with one default argument
  //    - Demonstrates both a plain parameterized ctor (when all args given)
  //      and a default‑argument ctor (when salary is omitted).
  Employee(int empId, const string &empName, double empSalary = 30000.0)
      : id(empId),        // member‑initializer list sets id first
        name(empName),    // then name
        salary(empSalary) // then salary
  {
    cout << "[Param ctor]  Employee(int, string, double=30000) called:\n"
         << "               id=" << id
         << ", name=\"" << name
         << "\", salary=" << salary
         << "\n\n";
  }

  // 3) Display helper
  void display() const
  {
    cout << "[Display]     Employee Info -> "
         << "id=" << id
         << ", name=\"" << name
         << "\", salary=" << salary
         << "\n\n";
  }
};

int main()
{
  cout<<"-------------------------------------------------------"<<endl;
  cout << "=== 1) Implicit call to parameterized constructor ===\n";
  // This means the compiler automatically calls a constructor when you create an object using direct initialization syntax.
  Employee e1(101, "Alice", 75000.0); // all three arguments supplied
  e1.display();
  // This is when you manually invoke the constructor using the class name.
  cout<<"-------------------------------------------------------"<<endl;
  cout<< "=== 2) Explicit call to parameterized constructor ===\n";
  Employee e2 = Employee(102, "Bob"); // salary uses default 30000.0
  e2.display();
  
  cout<<"-------------------------------------------------------"<<endl;
  cout << "=== 3) Default constructor invocation ===\n";
  Employee e3; // calls Employee()
  e3.display();

  // Uncommenting the block below will show that, if we had no Employee(),
  // the line `Employee e4;` would be a compile‑time error.
  // cout << "=== 4) What happens without a default ctor? ===\n";
  // // Suppose we commented out Employee() above:
  // Employee e4; 
  //  // ERROR: no matching function for call to ‘Employee::Employee()’
  // e4.display();
  

  return 0;
}
