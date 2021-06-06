#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <bitset>

using namespace std;

int getNumberOfChangeBits(int a, int b)
{
	int c = a ^ b;
	int count = 0;
	while (c > 0)
	{
		count += (c & 1);
		c = c >> 1;
	}

	return count;
}


int main()
{
	int count = getNumberOfChangeBits(31, 14);
	cout << count << endl;

  cin.get();
	return 0;
}
