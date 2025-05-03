#include<iostream>
using namespace std;
class Test{
  private:
  ~Test(){}
   public:
   Test(){
    cout<<"Constructor is called "<<endl;

   }
   void show(){
    cout<<"Hello World"<<endl;
   }
   friend void destructorTest(Test *ptr);
};

void destructorTest(Test *ptr){
  cout<<"Destructor is called "<<endl;
  delete ptr;
}
int main(){
  // The  program fails in the compilation.The compiler notices that the local variable ‘t’ cannot be destructed because the destructor is private.
      // Test t1;

  // The program works fine. There is no object being constructed, the program just creates a pointer of type “Test *”, so nothing is destructed.
  // When something is created using dynamic memory allocation, it is the programmer’s responsibility to delete it. So compiler doesn’t bother.
  Test *t1 = new Test();
  t1->show();
  return 0;
}