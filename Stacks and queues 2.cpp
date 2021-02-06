#include<iostream>
using namespace std;

class Stack
{
	private:	
	int top_index; // stores the current topmost index of arr & min_upto
	int* arr; 
	int* min_upto; // for each elemt this stores the value of the min element upto and including the current element
	int n; // stores the size of stack
	
	public:

	Stack(int size)
	{
		n = size;
		arr = new int[size]; // dynamically declaring array
		min_upto = new int[size]; // dynamically declaring array
		top_index = -1;
	}
	
	int min()
	{
		if(top_index == -1)	return -1; // empty stack
		
		return min_upto[top_index];
	}
	
	void push(int x) // insert at the top of stack
	{
		if(top_index == n-1) {return;} // stack overflow
		
		top_index++;
		arr[top_index] = x;
		
		if(x < min_upto[top_index-1]) // if min of below elemt < current element, make it min of current element too
			min_upto[top_index] = x;
		else
			min_upto[top_index] = min_upto[top_index-1];
	}
	
	void pop() // delete the topmost element of the stack
	{
		if(top_index == -1) {return;} // stack underflow

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
	s.push(20);
	s.push(30);
	s.push(10);
	s.push(40);
	cout<<"min = "<<s.min()<<'\n';
	s.pop(); s.pop(); s.pop(); s.pop(); 
	cout<<"min = "<<s.min()<<'\n';
	return 0;
}
