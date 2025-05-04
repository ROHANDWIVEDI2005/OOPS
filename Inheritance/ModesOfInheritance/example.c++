#include<iostream>
using namespace std;
class Base{
  private:
  int pvt = 1;
  protected:
  int prot = 2;
  public:
  int pub = 3;

  int getPvt(){
    return pvt;
  }
};

class DerivedPuvlic: public Base{
  public:
   int getProt(){return prot;}

};

class DerivedProtected: protected Base{
   public:
   int getPublic(){return pub;}
   int getPrort(){return prot;}
   int get_Pvt(){return getPvt();}
   //  another way to access private member of base class
   //  int try_getPVT() { return Base::getPvt(); }

   // getPVT() itself was inherited as protected, so we can call it here
};

class DerivedPrivate: private Base{
   public:
     // OK: pub inherited as private
     int getPublic() { return pub; }
     // OK: prot inherited as private, but visible inside class
     int getProt() { return prot; }
     int get_Pvt() { return getPvt(); }

};
int main(){
  cout<<"This is Derived Public Class"<<endl;
  DerivedPuvlic d1;
  cout<<"Public variable of base class : "<<d1.pub<<endl;
  cout<<"Protected variable of base class :"<<d1.getProt()<<endl;
  cout<<"Private variable of base class :"<<d1.getPvt()<<endl;


  cout<<"______________________________________"<<endl<<endl;
  cout<<"This is Derived Protected class"<<endl;
  DerivedProtected d2;
  cout<<"Public variable of base class :"<<d2.getPublic()<<endl;
  cout<<"Protected variable of base class :"<<d2.getPrort()<<endl;
  cout<<"Private variable of base class :"<<d2.get_Pvt()<<endl;
  cout<<"______________________________________"<<endl<<endl;
  cout<<"This is Derived Private class"<<endl;
  DerivedPrivate d3;
  cout<<"Public variable of base class :"<<d3.getPublic()<<endl;
  cout<<"Protected variable of base class :"<<d3.getProt()<<endl;
  cout<<"Private variable of base class :"<<d3.get_Pvt()<<endl;
  return 0;
}