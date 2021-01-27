#include<iostream>
#include <string>
using namespace std;

// true length = len of string without extra spaces at end to accomodate %20
// T = O(n), S = O(1)
string urlify(string s, int true_length)
{	
	int final_index = s.length() - 1; // this is len of string along with extra spaces at last

	// now iterate string in reverse and put %20 in place of spaces
	for(int i = true_length-1; i >=0; i--)
	{
//		cout<<"\ni = "<<i;
//		cout<<"  s[i] = "<<s[i]<<"  ";
		if(s[i] == ' ')
		{
			s[final_index] = '0';
			s[final_index - 1] = '2';
			s[final_index - 2] = '%';
			final_index = final_index - 3;
//			cout<<s<<"|\n";
		}
		else
		{
			s[final_index] = s[i];
			final_index --;
//			cout<<s<<"|\n";
		}
	}
	
	return s;
}

int main()
{
	cout<<"\n"<<urlify("hello world  ", 11);
	return 0;
}
