#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class GeeksForGeeks
{
public:
  void add(int a, int b)
  {
    cout << "The sum of two integers is :" << a + b << endl;
  }
  void add(double a, double b)
  {
    cout << "the sum of the two double is :" << a + b << endl;
  }
};

int main()
{
  GeeksForGeeks gfg;
  cout << "The sum of two integers is :" << endl;
  gfg.add(10, 20); // Calls the first function

  cout << "The sum of the two double is:" << endl;
  gfg.add(10.2, 20.5); // Calls the second function
  return 0;
}