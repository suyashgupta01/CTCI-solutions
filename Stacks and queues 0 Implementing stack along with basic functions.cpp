#include<iostream>
using namespace std;

class Stack
{
	private:	
	int top_index; // stores the current topmost index of array
	int* arr; 
	int n; // stores the size of stack
	
	public:

	Stack(int size)
	{
		n = size;
		arr = new int[size]; // dynamically declaring array
		top_index = -1;
	}
	
	void push(int x) // insert at the top of stack
	{
		if(top_index == n-1) {return;} // stack overflow
		
		top_index++;
		arr[top_index] = x;
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
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	cout<<s.top()<<'\n'; // should print 40
	s.pop(); s.pop(); s.pop(); s.pop();
	cout<<s.top(); // should print -1
	return 0;
}
