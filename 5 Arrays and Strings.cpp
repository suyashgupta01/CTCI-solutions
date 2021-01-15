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
	if(diff > 1 or diff < -1) return false;
		
	if(s1.compare(s2) == 0) return true; // if both strings are identical, return true
	
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
		int n, smaller_s; // smaller index, smaller string
		if(n1<n2)
			{
				n = n1;
				smaller_s = 1;
			}
		else
			{
				n = n2;
				smaller_s = 2;
			}
			
		for(int i = 0; i<n; i++) // we traverse up to the smaller index
		{
			if(s1[i] != s2[i] and (not one_edit_made))
			{
				one_edit_made = true;
				// insert into the smaller string -> now the s1 and s2 will become of same size
				if(smaller_s == 1)
					s1.insert(i, "x"); // correct thing in place of x = string(1, s2[i])
				else if (smaller_s == 2)
					s2.insert(i, "x"); // correct thing in place of x = string(1, s1[i])	
			}
			else if (s1[i] != s2[i] and one_edit_made) return false; 
		}
		
//		 after traversing through the loop, there are 2 cases
//		 (1) an element was inserted in the smaller string 
//				-> now the last elements of both strings needs to be same to return true
//				-> else return false
//		 (2) no element was inserted in the smaller string 
//				-> now an element (= last elemt of larger string) can be inserted in the smaller string 
//				-> return true
		
		// update n1,n2 with new lengths (if any)
		n1 = s1.length();
		n2 = s1.length();
		
		if(n1 == n2) // (1)
		{
			if(s1[n1] == s1[n2])
				return true;
			else
				return false;
		}
		else // (2) 
			return true;
	}	
}

int main()
{
	cout<<bool_to_string(one_away("heexello", "hello")); // false
	cout<<bool_to_string(one_away("hellobro", "helloman")); // false
	cout<<bool_to_string(one_away("bILLY", "bILLY")); // true
	cout<<bool_to_string(one_away("hEllo", "hello")); // true
	cout<<bool_to_string(one_away("hllo", "hello")); // true
	cout<<bool_to_string(one_away("john", "johny")); // true
	cout<<bool_to_string(one_away("onestring", "nestring")); // true
	return 0; 
}
