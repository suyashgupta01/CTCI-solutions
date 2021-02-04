// -------------------- boilerplate for Linked List starts --------------------

#include<iostream>
#include<vector>
#include <string>
using namespace std;

class Node{
	public: 	
	int data;
	Node* next;
	
	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

void insert_at_head(Node* &head, int val)
{
	// create a new node with given value and next = address of 0th node of linked list
	// then store it's address in a pointer
	Node* n = new Node(val);
	n->next = head;
	
	head = n;
}

void display(Node* head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

string search(Node* head, int key)
{
	int location_counter = -1;
	Node* temp = head;
	while(temp != NULL)
	{
		location_counter++;
		if(temp->data == key) 
			{ return "\n" + to_string(key) + " found at position " + to_string(location_counter) + "\n"; }
		temp = temp->next;
	}
	return "\n" + to_string(key) + " not found\n";
}

void delete_by_location(Node* &head, int loc)
{
	int location_counter = -1;
	Node* temp = head;
	Node* temp1; // this will store the address of the node to the left of the node to be deleted.
	Node* temp2; // this will store the address of the node to be deleted -> we'll use to deallocate its memory.
	while(temp != NULL)
	{
		location_counter++;
		if(location_counter == loc-1)
		{
			temp1 = temp;
			temp2 = temp1->next;
		}	
		if(location_counter == loc+1)
		{
			// currently temp points to the node that's to the right of the node to be deleted.
			temp1->next = temp;
			return;
		}
		temp = temp->next;
	}
	delete temp2;
}

void delete_all_nodes(Node* &head) // empty the memory to avoid leaked memory
{
	vector<Node*> all_addresses; // will store addresses of all nodes
	Node* temp = head;
	while(temp != NULL)
	{
		all_addresses.push_back(temp);
		temp = temp->next;
	}
	
	for(int i=0; i<all_addresses.size(); i++)
	{
		delete all_addresses[i];
	}
}
// -------------------- boilerplate for Linked List ends --------------------

class Stack
{
	// We perform insertion and deletion at the start of the LL as this gives O(1) for both.
	// top_ptr (head) points to the top of the stack (LL)
	
	private:	
	Node* top_ptr; 
	
	public:

	Stack()
	{
		top_ptr = NULL;
	}
	
	void push(int x) // insert at the top of stack
	{
		// stack overflow when the heap memory is exausted -> dynamically memory can't be allocated 
		// -> NULL is returned as mem address on using new keyword

		Node* n = new Node(x);
		
		if(n == NULL) return; // stack overflow
		
		n->next = top_ptr;
		top_ptr = n;
	}
	
	void pop() // delete the topmost element of the stack
	{
		if(top_ptr == NULL) return; // stack underflow
		
		top_ptr = top_ptr->next;
	}
	
	int top() // returns the topmost element of the stack
	{
		if(top_ptr == NULL) {return -1;} // empty stack
		
		return top_ptr->data;
	}
	
	bool empty()
	{
		return top_ptr==NULL; // return true if stack is empty, else false
	}
};

int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	cout<<s.top()<<'\n'; // should print 40
	s.pop(); s.pop(); s.pop(); s.pop();
	cout<<s.top()<<'\n'; // should print -1
	cout<<s.empty(); //should print 1
	return 0;
}
