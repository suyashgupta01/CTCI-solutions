#include<iostream>
using namespace std;

class Stack
{
	private:	
	int top_index; // stores the current topmost index of array
	int* arr; 
	int n; // stores the size of stack
	int min_element = -9999999; // do something about this
	
	public:

	Stack(int size)
	{
		n = size;
		arr = new int[size]; // dynamically declaring array
		top_index = -1;
	}
	
	int min()
	{
		return min_element;
	}
	
	void push(int x) // insert at the top of stack
	{
		if(top_index == n-1) {return;} // stack overflow
		
		if(x < min_element) {min_element = x;}
			
		top_index++;
		arr[top_index] = x;
	}
	
	void pop() // delete the topmost element of the stack
	{
		if(top_index == -1) {return;} // stack underflow
		
		if(arr[top_index] == min_element)
		{
			// find new min_element by iterating across the remaining array
		}
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
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	
	return 0;
}
