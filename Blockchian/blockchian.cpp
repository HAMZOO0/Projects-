#include <iostream>
#include <time.h>

using namespace std;

void decToHexa(int n) { cout << hex << n << endl; }
void  BlockChain(int No_block);

int main(int argc, char const *argv[])
{
     int Number_of_Blocks=0;
     cout<<"Number of Blocks :: ";
     cin>>Number_of_Blocks;

     BlockChain(Number_of_Blocks);

     
     return 0;
}

void  BlockChain(int No_block)
{
     time_t timetoday;
     time(&timetoday);

     long int Hash = 1111111111;
     int Block_number = 0;

    

     for (int i = 0; i < No_block; i++)
     {
          cout << "\nBlock Number ::" << Block_number++ << endl
          << "Time ::"
          << asctime(localtime(&timetoday)) << "Block Hash ::";
           decToHexa(Hash);
           Hash++;
           cout<<endl;
        
     }
     

}

// asctime(localtime(&timetoday)); current time

