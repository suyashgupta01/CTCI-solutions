#include<iostream>
#include<vector>
using namespace std;

// There are only upper, lowercase letters. No other characters in strings
// o/p of format: Char-num-of-continuous-occurrences
// T = O(n) assuming line X takes linear/ constant time. 
// S = O(n)
string compress(string str)
{
	int n = str.length();
	string new_str = "";
	int current_char_count = 1;
	
	for(int i = 0; i<n; i++)
	{
		if(str[i] == str[i+1])
			current_char_count++;
		else
		{
			new_str.append(str[i] + to_string(current_char_count)); // line X
			current_char_count = 1;
		}
	}
	
	// return new_str only if it is shorter than the original string
	if (new_str.length() >= n)
		return str;
	else
		return new_str;

//	return new_str;
}

int main()
{
	cout<<compress("ZZxxxAAAAAAa");
}

// NOTE: In Java, strings are immutable and concatination is of O(n^2) complexity as a new string needs to be created
// However, there's no such issue in c++
