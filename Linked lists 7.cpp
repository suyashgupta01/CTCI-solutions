#include<stack>
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

Node* check_intersection_by_reference(Node *head1, Node *head2)
{
	Node *temp1 = head1;
	Node *temp2 = head2;
	
	// take temp1, temp2 to the end of each LL
	while(temp1 != NULL) {temp1 = temp1->next;}
	while(temp2 != NULL) {temp2 = temp2->next;}	
	
	if(temp1 == temp2) // If ends are same => intersecting LLs. We need to return the intersecting node
	{
		// push the references of both linked lists into seperate stacks
		// compare the tops & pop out the references
		// If they differ, we've reached the one step before the intersection => return the ref of next node of the LL
		
		stack<Node*> s1, s2; temp1 = head1; temp2 = head2;
		while(temp1 != NULL)
		{
			s1.push(temp1);
			temp1 = temp1->next;
		}
		while(temp2 != NULL)
		{
			s1.push(temp1);
			temp2 = temp2->next;
		}
		while(!s1.empty() and !s2.empty())
		{
			if(s1.top() != s2.top())
				return s1.top()->next; // or s1.top()->next | same thing as they both point to the same intersecting node
		}
	}
	else 
		return NULL;
}

// CTCI's way
Node* check_intersection_by_reference1(Node *head1, Node *head2)
{
	if(head1 == NULL or head2 == NULL)
		return NULL;
	
	Node *temp1 = head1; Node *temp2 = head2; int counter1 = 0; int counter2 = 0;
	
	// take temp1, temp2 to the end of each LL
	while(temp1 != NULL) {temp1 = temp1->next; counter1++;}
	while(temp2 != NULL) {temp2 = temp2->next; counter2++;}	
	
	if(temp1 == temp2) // If ends are same => intersecting LLs. We need to return the intersecting node
	{
		// Get rid of the extra beginning nodes of the longer LL
		// Move forward the longer LL's head forward to make the lenghts of LLs same
		if (counter1 > counter2)
		{
			// draw intersecting LLs on paper to understand counter1-counter2
			for(int i = 0; i<counter1-counter2; i++) {head1 = head1->next;}
			
		}
		else
		{
			for(int i = 0; i<counter2-counter1; i++) {head2 = head2->next;}
		}
		
		// Now iterate both LLs simultaneously and return when the first same reference is encountered, return it
		temp1 = head1; temp2 = head2; 
		while(temp1 != NULL and temp2 != NULL)
		{
			if (temp1 == temp2) return temp1;
			temp2=temp2->next;
			temp1=temp1->next;
		}
	}
	else 
		return NULL;
}

int main()
{
	Node* head1 = NULL;
	insert_at_tail(head1, 5);
	insert_at_tail(head1, 6);
	insert_at_tail(head1, 7); // X
	insert_at_tail(head1, 8);
	
	Node* head2 = NULL;
	insert_at_tail(head2, 1);
	insert_at_tail(head2, 2);
	// Now making the last node of LL2 point to X.
	head2->next->next = head1->next->next;
	
//	Node* temp = check_intersection_by_reference(head1, head2);
//	cout<<temp->data; // should print 7
	
	Node* temp = check_intersection_by_reference1(head1, head2);
	cout<<temp->data; // should print 7
	
	return 0;
}
