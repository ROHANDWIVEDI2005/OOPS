#include<iostream>
using namespace std;

class Circle{
  public:
    double radius;
    double area(){
      return 3.14*radius*radius;
    }
};

int main(){
  cout<<"This is a public access modifier example."<<endl;
  cout<<"Enter radius of circle:"<<endl;
  Circle c1;
  cin>>c1.radius;
  cout<<"Radius of circle is:"<<c1.radius<<endl;
  cout<<"Area of circle is:"<<c1.area()<<endl;
  return 0;
}