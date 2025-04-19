#include<iostream>
using namespace std;

class Base{
    private:
     int privateNum;
    protected:
      int protectedNum;
    public:
      int publicNum;
      Base(){

        privateNum =1;
        protectedNum =2;
        publicNum =3;
        cout<<"Base constructor called"<<endl;
        cout<<"Intializing privateNum = "<<privateNum<<endl;
        cout<<"Intializing protectedNum = "<<protectedNum<<endl;
        cout<<"Intializing publicNum = "<<publicNum<<endl;
      }
      ~Base(){
        cout<<"Base destructor called"<<endl;
      }
      friend class FriendClass; // Declare FriendClass as a friend of Base
};
class FriendClass{
    public:
      void display(Base& b){
        cout<<"FriendClass accessing Base members"<<endl;
        cout<<"privateNum = "<<b.privateNum<<endl; // Accessing private member
        cout<<"protectedNum = "<<b.protectedNum<<endl; // Accessing protected member
        cout<<"publicNum = "<<b.publicNum<<endl; // Accessing public member
      }
};
int main(){

  cout<<"Using FriendClass to access Base members"<<endl;
  Base b;
  cout<<"----------------------------------------"<<endl;
  FriendClass f;
  f.display(b);

  return 0;
}