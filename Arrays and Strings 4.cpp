#include<iostream>
#include <string>
using namespace std;

bool check_permutation_of_palindrome(string str)
{
	// This program is case sensitive as ascii is used :)
	
	int count[256] = { 0 }; // each place corresponds to one character of extended ascii
	bool one_odd_occoured = false;
	int n = str.length();
		
	// count occourances of all characters
	for(int i=0; i<n; i++)
	{
		// ascii value of current character
		int val = int(str[i]);
		count[val] += 1;
	}
	
	// iterate through count and see number of occourances
	for(int i=0; i<256; i++)
	{
		if(n%2 ==0) // if length of string is even, no character can occour odd times
		{
			if(count[i]%2 != 0)
				return false;
		}
		else // if len of string is odd, one char (mid char) is allowed to occour odd times (1 time)
		{
			if(count[i]%2 != 0 and (not one_odd_occoured))
				one_odd_occoured = true;
			else if(count[i]%2 != 0 and one_odd_occoured)
				return false;
		}
	}
	return true;
}

string bool_to_string(bool value)
{
	if (value == true)
		return "True\n";
	else 
		return "False\n";
}

int main()
{
	cout<<bool_to_string(check_permutation_of_palindrome("asdfdsa"));
	cout<<bool_to_string(check_permutation_of_palindrome("nope"));
	return 0;
}
