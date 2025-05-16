#include<iostream>
using namespace std;
class demo{
  int x;
 public:
   demo(int a){
    try{
      if(a==0)
      throw "zero is not allowed";

      x=a;
     show();
    }

// In this  we catching the pointer to the string which is refering to the first character of the string
// here if we use *msg in cout then it only print the first character of the string
// if we use msg in cout that means we are passing the pointer in the iostream and overloading the cout operator which then take it as argument
    catch(const char *msg){
      cout<<"Exception caught:" <<endl;
      cout<<msg<<endl;
    }

   }
   //   Exception Specifications (noexcept)
  //  noexcept
  //  — this function guarantees it will not throw.
  //  noexcept(false) — it may throw(this is the default)
      void show() noexcept
   {
     cout << "The number is: " << x << endl;
   }
};

class MyExeption:public runtime_error{
  public:
  MyExeption(const string &msg):runtime_error(msg)
  {
    cout<<"MyExeption constructor called"<<endl;
  }
};
int main(){
demo d(0);

// using the custom exception which is being derived from the runtime_error
try
{
  throw MyExeption("This is a custom exception");
}
catch(const MyExeption& e)
{
  std::cerr << e.what() << '\n';
}

return 0;

}
