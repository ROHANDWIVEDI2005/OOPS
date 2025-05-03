#include <iostream> 
#include <utility>  

using namespace std; 

class MyClass
{
private:
  int *data; 

public:
  MyClass(int value)
  {
    data = new int(value); 
    cout << "Constructor: value = " << *data << endl;
  }

  // Move Constructor: takes a temporary (r-value) object and "steals" its data
  MyClass(MyClass &&other)
  {
    data = other.data;    // take the pointer from the temporary object
    other.data = nullptr; // remove data from the old object (now empty)
    cout << "Move Constructor: ownership transferred" << endl;
  }

  // Destructor: called when object is deleted or goes out of scope
  ~MyClass()
  {
    if (data != nullptr)
    {
      cout << "Destructor: deleting data = " << *data << endl;
    }
    else
    {
      cout << "Destructor: data is already moved (nullptr)" << endl;
    }
    delete data; // free memory (even if it's nullptr, delete is safe)
  }

  // Print function
  void print()
  {
    if (data != nullptr)
      cout << "Data = " << *data << endl;
    else
      cout << "Data is null (moved from)" << endl;
  }
};

int main()
{
  // Create a normal object
  MyClass a(10);
  a.print();

  // Move 'a' into 'b' using move constructor
  MyClass b = move(a); 
  b.print();           // now 'b' owns the data
  a.print();           // 'a' has been emptied (data is nullptr)

  return 0;
}
