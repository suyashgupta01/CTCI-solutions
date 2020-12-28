#include <iostream>
using namespace std;

string bool_to_string(bool value)
{
	if (value == true)
		return "True";
	else 
		return "False";
}

// question 1

bool is_unique(string s, int n)
{
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


int main()
{
	cout<<bool_to_string(is_unique("asdfaerfcs", 10))<<"\n";
	cout<<bool_to_string(is_unique("asdfqwerth", 10));
	return 0;
}
