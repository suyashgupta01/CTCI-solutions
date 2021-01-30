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

// Will be taking head by value as we don't have to modify the linked list

int kth_element_from_last1(Node* head, int k)
{
	if (head == NULL)
		return -1;
	// Assuming that idices from last START FROM 1. 
	// Assuming that length of the linked list is not known (if it's known then question hi nhi bachega lol)
	Node* temp;
	int len, counter, position_from_start;
	
	//find length of LL 
	counter = 0;
	temp = head;
	while(temp != NULL) 
	{
		counter++;
		temp = temp->next;
	}
	len = counter;
	
	// find at what position the elemtn will be from start
    position_from_start = len - k; // draw on paper to be clear
	
	// now find the element
	counter = 0;
	temp = head;
	while(temp != NULL) 
	{
		if(counter == position_from_start)
			return temp->data;
		counter++;
		temp = temp->next;
	}
	
	return -1; 
}

// CTCI's iterative approach
int kth_element_from_last2(Node* head, int k)
{
	if (head == NULL)
		return -1;
	// use two pointers
	// temp starts from the head
	// forward starts from head+k
	// => when forward is at the end, temp is at end-k = len of LL - k = kth position from last
	Node* temp;
	Node* forward;
	int counter;
	
	// move forward upto (head+k)th position, ie: at kth index
	counter = 0;
	temp = head;
	while(temp != NULL)
	{
		if(counter == k)
		{
			forward = temp;
			break;
		}
		counter++;
		temp = temp->next;
	}
	
	// iterate through LL upto the end
	temp = head;
	while(forward != NULL)
	{
		forward = forward->next;
		temp = temp->next;
	}	
	
	return temp->data;
}

int main()
{
	Node* head = NULL;
	insert_at_tail(head,10);
	insert_at_tail(head,20);
	insert_at_tail(head,30);
	insert_at_tail(head,40);
	insert_at_tail(head,50);
	insert_at_tail(head,60);
	insert_at_tail(head,70);
	insert_at_tail(head,80);
	insert_at_tail(head,90);
//	cout<<kth_element_from_last1(head, 3);
	cout<<kth_element_from_last2(head, 3);	
}
