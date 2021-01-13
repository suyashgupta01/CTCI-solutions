#include<iostream>
using namespace std;

string bool_to_string(bool value)
{
	if (value == true)
		return "True\n";
	else 
		return "False\n";
}

// if usage of extra space is allowed
bool one_away(string s1, string s2)
{
	int n1 = s1.length();
	int n2 = s2.length();
	
	// if length of strings differ by over one => more than 1 edit required 
	int diff = n1 - n2;
	if(diff != 1 or diff != -1)
		return false;
	
	bool one_edit_made = false;
	
	if(n1 == n2) // in this case only one type of edit is possible -> replace a character
	{
		for(int i = 0; i<n1; i++)
		{
			if(s1[i] != s2[i] and (not one_edit_made))
			{
				one_edit_made = true;
				s1[i] = s2[i]; // this line isn't really needed but still...
			}
			else if (s1[i] != s2[i] and one_edit_made)
				return false;
		}
		return true;
	}	
	else // in this case only two types of edits are possible -> insert/ remove a character 
	     // these 2 edits are basically the same as (removing from the longer string) == (inserting into the shorter string)
	     // here, I'll insert into the shorter string
	{
		int longer_length;
		string shorter_string;
		if(n1>n2)
			{
				longer_length = n1; 
				shorter_string = "s2";
			}
		else
			{
				longer_length = n2; 
				shorter_string = "s1";
			}
		
		for(int i = 0; i<longer_length; i++)
		{
			if(s1[i] != s2[i] and (not one_edit_made))
			{
				one_edit_made = true;
				// now insert into the shorter string
				if(shorter_string == "s1")
					s1.insert(i, string(1, s2[i]));
				else if (shorter_string == "s2")
					s1.insert(i, string(1, s1[i]));
			}
			else if(s1[i] != s2[i] and one_edit_made)
				return false;
		}
		return true;
	}	
}

int main()
{
	cout<<bool_to_string(one_away("heeello", "hello")); // ok
	cout<<bool_to_string(one_away("hEllo", "hello"));
//	cout<<bool_to_string(one_away("john", "johnny "));
//	cout<<bool_to_string(one_away("onestring", "nestring"));
	return 0; 
}
