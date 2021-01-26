#include<iostream>
using namespace std;

// if usage of extra space is allowed
void rotate_array(int arr[3][3], int n)
{
	int result[n][n];
	for(int i = 0; i<n; i++)
	{
		int temp[n];
		for(int j = 0; j<n; j++)
		{
			temp[j] = arr[i][j];
		}
		
		// copy temp to resultant array 
		for(int ii = n-1; i>=0; ii--)
		{
			for(int jj = 0; jj<n; jj++)
			{
				result[ii][jj] = temp[jj];
			}
		}
	}
	for(int i =0; i<n; i++)
	{
		for(int j =0; j<n; j++)
			{
				cout<<result[i][j]<<" ";
			}	
		cout<<"\n";
	}
}


int main()
{
	int matrix[3][3] = {{1,2,3},
		  	      		{4,5,6},
		  	      		{7,8,9}};
	rotate_array(matrix, 3);
	return 0; 
}
