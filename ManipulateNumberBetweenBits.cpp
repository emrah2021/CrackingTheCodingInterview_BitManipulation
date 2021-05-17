#include <iostream>
#include "math.h"

using namespace std;

int manipulateNumberBetweenBits(int N, int M, int i, int j)
{
    M = M << i; 
    
    unsigned int masknumber = 0;
    for(int k=i; k<=j; k++)
        masknumber += pow(2,k);
    
    // reverse bits
    masknumber = ~masknumber;
   
    // clear specific bits
    N &= masknumber;
    
    N |= M;
    
    return N;
}

int main()
{
    int N = 0b100000000000;
    int M = 0b10101;
    
    N = manipulateNumberBetweenBits(N, M, 2, 6);
    cout << N;

    return 0;
}
