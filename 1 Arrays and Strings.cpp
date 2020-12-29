#include <iostream>
using namespace std;

string bool_to_string(bool value)
{
	if (value == true)
		return "True\n";
	else 
		return "False\n";
}

// If we aren't allowed to use additional data structure & modify the i/p string
// T= O(n^2), S = O(1)
bool is_unique(string s, int n)
{
	if (n == 1)
		return true; 
		
	if (n > 256)
		return false; // extended ASCII has only 256 characters => over 256 means there has to be repetition
		
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if (s[i] == s[j] and i != j)
				return false;
		}
	}
	return true;
}

// If we are allowed to modify the string
// T = O(n logn) S = O(depends on sorting algo used)
bool is_unique1(string s, int n)
{
	// sort the string; if any 2 adjacent elements are same -> false
	if (n == 1)
		return true; 
		
	if (n > 256)
		return false;
	
	// apply some sorting algo that sorts the string s in place
	
	for(int i = 0; i<n-1; i++)
	{ 
		if (s[i] == s[i+1])
			return false;
	}
	return true;
}

// If we're allowed to use additional data structure
// T = O(n) & S = O(1) 
bool is_unique2(string s, int n)
{
	bool characters[n] = { false }; // maintain a boolean array for the characters. The 256 indices represent 256 characters
	
	for(int i = 0; i<n; i++)
	{
		int ascii_character = int(s[i]);
		if(characters[ascii_character] == true)
			return false;
		else
			characters[ascii_character] = true;
	}
}

int main()
{
	cout<<bool_to_string(is_unique("1234asdfqw", 10));
	cout<<bool_to_string(is_unique("falsef1232", 10));
	cout<<bool_to_string(is_unique2("12we547hgf", 10));
	cout<<bool_to_string(is_unique2("falsef1232", 10));
	return 0;
}
