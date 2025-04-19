#include<iostream>
using namespace std;

class friend_class;
class Circle{
  private :
    double radius;
    public:
    int getRadius(){
      return radius;
    }
    void setRadius(double r){
       this->radius = r;
    }

    double getCircleArea(){
      return 3.14 * radius * radius;
    }
    friend double getCircleRadius(Circle c);
    friend class friend_class;
};

double getCircleRadius(Circle c){
  return c.radius;
}
 class friend_class{
  public:
  void getRadius(Circle& c){
    cout<<"The radius of circle is : "<<c.radius<<endl;
  }
 };
int main(){

    cout<<"This is the example  of private access modifier(in this friend class and function methods are aslo implemented)"<<endl;
    Circle c1;
    c1.setRadius(5.0);
    cout<<"This radius is fetched using the getter function"<<endl;
    cout<<"The radius of circle is : "<<c1.getRadius()<<endl;
    cout<<"The area of circle is : "<<c1.getCircleArea()<<endl;
    cout<<"This radius is fetched using the friend function"<<endl;
    cout<<"The radius of circle is:"<<getCircleRadius(c1)<<endl;
    cout<<"This radius is fetched using the friend class"<<endl;
    friend_class f1;
    f1.getRadius(c1);
  return 0;
}