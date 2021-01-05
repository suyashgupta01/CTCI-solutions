#include<iostream>
#include<vector>
using namespace std;

// There are only upper, lowercase letters. No other characters in strings
// o/p of format: Char-num-of-continuous-occurrences
string compress(string str)
{
	string new_str;
	int n = str.length();
	char current_char = str[0];
	int current_char_count = 0;

	for(int i=1; i<n; i++) // loop delebrately starts from i=1 as 1st val of current_char is the 0th element
	{
		if(str[i] == current_char)
			current_char_count += 1;
		else
		{
			current_char = str[i];
			new_str.append(string(1, current_char));
			new_str.append(to_string(current_char_count));
		}

	}

	if(new_str.size() <= n)
		return new_str;
	else
		return str;
}

int main()
{
	cout<<compress("aabbccc");
	return 0;
}