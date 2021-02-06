#include<iostream>
#include<vector>
using namespace std;

//// CTCI's way | a little less optimized
//class Stack
//{
//	private:	
//	int top_index; // stores the current topmost index of arr & min_upto
//	int* arr; 
//	int* min_upto; // for each elemt this stores the value of the min element upto and including the current element
//	int n; // stores the size of stack
//	
//	public:
//
//	Stack(int size)
//	{
//		n = size;
//		arr = new int[size]; // dynamically declaring array
//		min_upto = new int[size]; // dynamically declaring array
//		top_index = -1;
//	}
//	
//	int min()
//	{
//		if(top_index == -1)	return -1; // empty stack
//		
//		return min_upto[top_index];
//	}
//	
//	void push(int x) // insert at the top of stack
//	{
//		if(top_index == n-1) {return;} // stack overflow
//		
//		top_index++;
//		arr[top_index] = x;
//		
//		if(x < min_upto[top_index-1]) // if min of below elemt < current element, make it min of current element too
//			min_upto[top_index] = x;
//		else
//			min_upto[top_index] = min_upto[top_index-1];
//	}
//	
//	void pop() // delete the topmost element of the stack
//	{
//		if(top_index == -1) {return;} // stack underflow
//
//		top_index--;
//	}
//	
//	int top() // returns the topmost element of the stack
//	{
//		if(top_index == -1) {return -1;} // empty stack
//		
//		return arr[top_index];
//	}
//	
//	bool empty()
//	{
//		return top_index==-1; // return true if stack is empty, else false
//	}
//};

// CTCI's way | a littles more optimized
// Instead of mentaining a whole array/ stack of the same size as that of our stack,
// mentain a dynamic data st (stack/ vector etc) & append to it only when [pushed element] < [current min upto that pt]
// NOTE: CTCI uses a stack, but I'm using a vector => slightly differs from CTCI
class Stack
{
	private:	
	int top_index; // stores the current topmost index of arr & min_upto
	int* arr; 
	int n; // stores the size of stack
	vector<int> min_vec; // its lastest element represents the minimum element of stack
	int top_index_of_min_vec; // alternatively use pointer: v.end() - 1
	
	public:

	Stack(int size)
	{
		n = size;
		arr = new int[size]; // dynamically declaring array
		top_index = -1;
		top_index_of_min_vec = -1;
	}
	
	int min()
	{
		if(top_index == -1)	return -1; // empty stack
		
		return min_vec[top_index_of_min_vec];
	}
	
	void push(int x) // insert at the top of stack
	{
		if(top_index == n-1) {return;} // stack overflow
		
		top_index++;
		arr[top_index] = x;
		
		// if incoming element < min => append it to min_vec,
		if(top_index_of_min_vec != -1)  // Confirm that stack is not empty, as min_vec[-1] would cause issues
		{
			// append incoming element to min_vec if it is less than the current min.
			if(x < min_vec[top_index_of_min_vec]) 
			{
				min_vec.push_back(x); 
				top_index_of_min_vec++;
			}	
			// else don't append to min_vec
		}
		else // if min_vec is empty, just append it to min_vec
		{
			min_vec.push_back(x); 
			top_index_of_min_vec++;
		}
		// else do nothing
	}
	
	void pop() // delete the topmost element of the stack
	{
		if(top_index == -1) {return;} // stack underflow

		if(arr[top_index] == min_vec[top_index_of_min_vec]) // if the element being removed is the min, update the new min
			top_index_of_min_vec--;
		top_index--;
	}
	
	int top() // returns the topmost element of the stack
	{
		if(top_index == -1) {return -1;} // empty stack
		
		return arr[top_index];
	}
	
	bool empty()
	{
		return top_index==-1; // return true if stack is empty, else false
	}
};

int main()
{
	Stack s(4);
	cout<<"min = "<<s.min()<<'\n';
	s.push(20);
	s.push(30);
	s.push(10);
	s.push(40);
	cout<<"min = "<<s.min()<<'\n';
	s.pop(); s.pop(); s.pop(); s.pop(); 
	cout<<"min = "<<s.min()<<'\n';
	return 0;
}
