#include<unordered_set>
#include<algorithm>
#include<iterator>
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

bool in_set(unordered_set<int> s, int elem)
{
	unordered_set<int>::iterator it;
	it = s.find(elem);
	if(it == s.end())
		return false;
	else
		return true;
}

// taking head by reference as we'll modify original linked list
void remove_dups(Node* &head)
{
	unordered_set<int> s;
	Node* temp = head;
	Node* before_temp = NULL; // this pointer trails 1 step behind the temp pointer
	while(temp != NULL)
	{
		if(in_set(s, temp->data)) // if current val is already in the set, delete it from linked list
		{
			before_temp->next = temp->next;
		}
		else // else add it to the set
		{
			s.insert(temp->data);
			before_temp = temp;
			// read NOTE at bottom
		}
		temp = temp->next;
		// """x"""
	}
	
}

int main()
{
	Node* head = NULL;
	insert_at_tail(head, 5);
	insert_at_tail(head, 1);
	insert_at_tail(head, 2);
	insert_at_tail(head, 1);
	insert_at_tail(head, 2);
	insert_at_tail(head, 1);
	insert_at_tail(head, 3);
	insert_at_tail(head, 4);
	insert_at_tail(head, 5);
	insert_at_tail(head, 5);
	display(head);
	cout<<"\n";
	remove_dups(head);
	display(head);
	cout<<"\n";
	delete_all_nodes(head);	
	return 0;
}

// NOTE: 
// we update before_temp only when the newly encountered node isn't a duplicate
// if we update before_temp at """x""" (in every iteration),
// then it will point may point to a node that has been deleted 
// and even worse is this-> deleted_node    duplicate_node_to_be_deleted       next_good_node
//                             ^                        ^
//                          before_temp               temp
// in this case, a node that's supposed to be deleted will point to the next good node!
