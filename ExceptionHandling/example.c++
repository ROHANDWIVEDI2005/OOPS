#include <iostream>
#include <stdexcept> // for std::out_of_range
#include <limits>    // for numeric_limits
using namespace std;
// Catch by Value vs. Reference
// By value(catch (MyException e)) makes a copy.
// By reference(catch (const MyException &e)) avoids copying and preserves derived types.
// Best practice : Always catch exceptions by(const) reference to avoid slicing and extra copies.
int main()
{
  int a = 1;

  do
  {
    try
    {
      // 1) Read x, or throw on bad input
      int x;
      cout << "Enter a number: ";
      if (!(cin >> x))
      {
        throw "Please enter a valid integer.";
      }

      // 2) Throw based on odd/even
      if (x % 2 != 0)
      {
        throw -1; // odd
      }
      else
      {
        throw 1; // even
      }
    }
    catch (const char *msg)
    {
      // Input error: clear and discard bad input then retry immediately
      cout << "Input error: " << msg << "\n";
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue; // restart the loop for a new input
    }
    catch (int e)
    {
      // odd/even result
      if (e == -1)
        cout << "Result: odd number\n";
      else
        cout << "Result: even number\n";
    }

    // 3) Ask if they want to go again
    cout << "Do you want to continue? (1 = yes, 0 = no): ";
    if (!(cin >> a))
    {
      // If even this fails, exit
    cout << "Bad input. Exiting.\n";
      break;
    }

  } while (a == 1);

  return 0;
}
