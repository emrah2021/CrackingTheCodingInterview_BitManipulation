#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <bitset>

using namespace std;

string getBinaryRepresentation(string inputString)
{
	string outputStr = "";
	int value = 0;
	int remain = 0;
	int pos = inputString.find(".");
	if (pos == -1)
	{
		value = stoi(inputString);
		while (value > 0)
		{
			remain = value % 2;
			value = value / 2;
			outputStr = to_string(remain) + outputStr;
		}
	}
	else
	{
		value = stoi(inputString.substr(0, pos));
		double dec_value = stof(inputString.substr(pos));
		double dec_remain = 0.0;
		string outputDecStr = "";

		while (value > 0)
		{
			remain = value % 2;
			value = value / 2;
			outputStr = to_string(remain) + outputStr;
		}
		while (dec_value > 0)
		{
			if (outputDecStr.length() > 32)
			{
				outputStr = "ERROR";
				break;
			}
			dec_value *= 2;
			if (dec_value < 1)
			{
				outputDecStr += to_string(0);
			}
			else
			{
				outputDecStr += to_string(1);
				dec_value = dec_value - 1;
			}
		}

		outputStr = outputStr + "." + outputDecStr;
	}

	return outputStr;
}


int main()
{
	string input = "33.125";
	string binary = getBinaryRepresentation(input);
	cout << "binary: " << binary << " of: " << input << endl;

  cin.get();
	return 0;
}
