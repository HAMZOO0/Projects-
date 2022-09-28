// C++ program to convert decimal number to hexadecimal
#include <iostream>
using namespace std;

// function to convert decimal number to hexadecimal
// void decToHexa(int n) { cout << hex << n << endl; }

// driver code
int main()
{
    int n = 1111111111; // 10 support
                        // cin>>n;
    decToHexa(n);

    ++n;
    decToHexa(n);
      ++n;
    decToHexa(n);
      ++n;
    decToHexa(n);
      ++n;
    decToHexa(n);
      ++n;
    decToHexa(n);
    

    return 0;
}

// This code is contributed by phasing17.
