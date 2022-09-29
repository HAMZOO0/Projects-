/*
    Developer Name ::  Hamza Sajid
     Date ::          29/09/202
*/

#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

// Decimal to Hexadecimal coverter function
void decToHexa(int n)
{
     // char array to store hexadecimal number
     char hexaDeciNum[100];

     // counter for hexadecimal number array
     int i = 0;
     while (n != 0)
     {
          // temporary variable to store remainder
          int temp = 0;

          // storing remainder in temp variable.
          temp = n % 16;

          // check if temp < 10
          if (temp < 10)
          {
               hexaDeciNum[i] = temp + 48;
               i++;
          }
          else
          {
               hexaDeciNum[i] = temp + 55;
               i++;
          }

          n = n / 16;
     }

     // printing hexadecimal number array in reverse order
     for (int j = i - 1; j >= 0; j--)
          cout << hexaDeciNum[j];
}

void BlockChain(int No_block); // prototype of blockchain function which creats the blocks

int main(int argc, char const *argv[])
{
     cout << "\nDeveloper Name Hamza Sajid \n";
     cout << "29/09/2022\n";

     int Number_of_Blocks = 0;

     cout << "\nNumber of Blocks :: ";
     cin >> Number_of_Blocks;

     BlockChain(Number_of_Blocks); // this actual parameter is number of blocks

     getch();
}

void BlockChain(int No_block)
{
     time_t timetoday;
     time(&timetoday); // current time function prototype

     long int Hash = 1111111111;  // here we set hash 1111111111
     static int Block_number = 0; // here we have blocks number

     int temp=000000001 ;   // temp variable use to store Previous block hash 

     for (int i = 0; i < No_block; i++) // this loop print all blocks data depends upon how much blocks we want to print
     {
          cout << "\nBlock Number ::" << Block_number++ << endl;

          cout << "Time ::" << asctime(localtime(&timetoday)) ;

          cout<<"Previous Block Hash :: "; 
          decToHexa(temp);

          cout<< "\nBlock Hash :: "; // increment in hash
          decToHexa(Hash);         // decimal to hexadecimal


          temp = Hash ; 
          Hash++;                   // hash increment


          cout << endl;
          getch();
     }
}

// asctime(localtime(&timetoday)); current time
//This is just a model project , programming beginners can understand how Block chain actually works in just simple way  
