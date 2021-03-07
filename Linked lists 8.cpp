// ----------- boilerplate starts ---------

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

void insert_at_tail(Node* &head, int val)
{
	// create a new node with given value and next = NULL then store it's address in a pointer
	Node* n = new Node(val);  

	if (head == NULL) // if linked list is empty
	{
		head = n;
		return;
	}
	
	// now traverse the linked list to the last
	Node* temp = head;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	
	// now temp points to the last node of the list
	temp->next = n;
	
}

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

// ----------- boilerplate ends ---------


// My method start ------- 	T = S = O(N)
bool node_exists_in_vector(Node* x, vector<Node*> v)
{
	for(int i = 0; i<v.size(); i++)
	{
		if(v[i] == x)
			return true;
	}
	return false;
}

Node* return_loop_start_node(Node* head) // taking by value as linked list doesn't have to be modified
{
	vector<Node*> v;
	Node* temp = head;
	
	while(temp != NULL)
	{
		if(node_exists_in_vector(temp->next, v)) // if current node's next's address doesn't exist in v.
			v.push_back(temp->next);
		else // loop found, we're on the last element of the array. The next of this is the starting node of the loop.
			return(temp->next);
		temp = temp->next;
	}
}
// My method end -------

// CTCI method start ------- T = O(N), S = O(1)

Node* return_loop_start_node1(Node* head)
{
	Node* fast = head; Node* slow = head,
	// slow -> 1 & fast -> 2 steps at a time.
	// If there is a loop, slow and fast are going to initersect
	while(xxx)
	{
		if(slow == fast) // loop detected -> intersection happens -> k nodes after the start of the loop
		{
			
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	cout<<"\nNo loop found";
}
// CTCI method end -------

int main()
{
	Node* head1 = NULL;
	insert_at_tail(head1, 5);
	insert_at_tail(head1, 6); // x
	insert_at_tail(head1, 7); 
	insert_at_tail(head1, 8);
	head1->next->next = head1->next; // making the last node of point to X.
	cout<<return_loop_start_node(head1)->data; // prints 6
	return 0;
}
