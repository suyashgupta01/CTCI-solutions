#include <iostream>
#include <algorithm> // to use std::sort() --> C++ uses something called Introsort T = n log n, S = log n

using namespace std;

string bool_to_string(bool value)
{
	if (value == true)
		return "True\n";
	else 
		return "False\n";
}

// This solution is case sensitive & whitespace sensite (as ascii codes are used! - there are seperate codes for capital, small, whitespace)
// T = O(n1 + n2) = O(n), S = O(n1) 
bool check_permutation(string s1, int n1, string s2, int n2)
{
	// strings are permutations iff all chars of one strings are there in the other
	
	if(n1 != n2)
		return false;
	
	if(n1 == 1 and n2 == 1)
		return true;
	
	int char_count[256] = { 0 }; // each index i corresponds to an ascii character & its count is in char_count[i]
	int ascii_code_of_char;
	
	// fill char_count with counts of s1
	for(int i = 0; i<n1; i++)
	{
		ascii_code_of_char = int(s1[i]);
		++char_count[ascii_code_of_char];
	}
	
	// for each character in s2, decrease corresponding from char_count
	for(int i = 0; i<n2; i++)
	{
		ascii_code_of_char = int(s2[i]);
		--char_count[ascii_code_of_char];	
		
		if(char_count[ascii_code_of_char] < 0)
			return false;
	}
	
	return true;
}

// Another approach is to sort both strings and then compare the resultants
// This solution is also case sensitive & whitespace sensite 
// T = O(n logn) , S = O(logn)
bool check_permutation1(string s1, int n1, string s2, int n2)
{
		
	if(n1 != n2)
		return false;
	
	if(n1 == 1 and n2 == 1)
		return true;
		
	sort(s1.begin(), s1.end()); // sorts in place
	sort(s2.begin(), s2.end()); // sorts in place
	
	for(int i = 0; i<n1; i++)
	{
		if(s1[i] != s2[i])
			return false;
	}
	
	return true;
}

int main()
{
	string string1 = "hellobro123aa";
	string string2 = "hellobro321aa";
	cout<<bool_to_string(check_permutation(string1, 13, string2, 13));
	cout<<bool_to_string(check_permutation1(string1, 13, string2, 13));	
	
	string string3 = "strings";
	string string4 = "chippss";
	cout<<bool_to_string(check_permutation(string3, 7, string4, 7));
	cout<<bool_to_string(check_permutation1(string3, 7, string4, 7));	
	return 0;
}
