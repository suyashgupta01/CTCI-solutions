#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class SetOfStacks
{
	public:
	
	int threshold;
	vector<stack<int>*> list_of_stacks; // stores POINTERS of different stacks that are created
	int current_stack = -1; // shows which stack is being used out of the different stacks stored in the vector
	
	SetOfStacks(int th)
	{
		threshold = th;
	}
	
	void push(int val)
	{
		// first insertion of program OR current stack is full
		if(list_of_stacks.size() == 0 or list_of_stacks[current_stack]->size() >= threshold) 
		{
			// Creating new stack dynamicallly, else it'll be erased when scope of the function ends
			stack<int>* s_ptr = new stack<int>; 
			list_of_stacks.push_back(s_ptr);
			current_stack++;
			s_ptr->push(val); 
			cout<<"new stack created\n";
			cout<<val<<"pushed\n";
		}
		else // current stack is has space
		{
			list_of_stacks[current_stack]->push(val);
			cout<<val<<"pushed\n";
		}
	}
	
	void pop()
	{
		if(current_stack == -1)
		{
			cout<<"stack underflow\n";
			return; // no items to delete
		}
			
		stack<int>* current_stack_ptr = list_of_stacks[current_stack];
		cout<<current_stack_ptr->top()<<" popped\n";
		current_stack_ptr->pop();
		
		if(current_stack_ptr->size() == 0) // if this stack has become empty after popping an element
		{
			delete current_stack_ptr; // remove the stack from the memory
			list_of_stacks.erase(list_of_stacks.end() - 1); // also remove the ptr from the list of stacks (last element...)
			current_stack--;
		}
	}
	
	void pop_at(int substack_index)
	{
		if(substack_index > list_of_stacks.size() -1)
		{
			cout<<"given index exceeds the size of the list of substacks\n";
			return;	
		}
		stack<int>* ptr_to_required_substack = list_of_stacks[substack_index];
		if(ptr_to_required_substack->size() == 0)
		{
			cout<<"stack underflow; no element in substack "<<"\n";
			return;
		}
		else
		{
			cout<<ptr_to_required_substack->top()<<" popped\n";
			ptr_to_required_substack->pop();
		}
		// now, we need to manage rolling over elements
		// and then if last stack becomes empty, delete it
			
	}
	
	void left_shift()
};

int main()
{
	SetOfStacks s(2); // => maximum 2 elements in one stack
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.pop_at(1); // pop 40; wrote 1 as substack indices start at 0
	s.pop();
	s.pop();
	s.pop();
	return 0;
}
