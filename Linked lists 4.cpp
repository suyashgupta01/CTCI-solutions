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

// Taking head by val cuz ain't gotta modify the linked list

// My method: We may say this is a bit unfair ;)
bool is_palindrome(Node* head) 
{
	// copy to a vector, then check for vector
	Node* temp = head;
	vector<int> v;
	int front, back;
	
	while(temp != NULL)
	{
		v.push_back(temp->data);
		temp = temp->next;
	}
	
	int n = v.size();
	for(int i = 0; i<n; i++)
	{
		front = v[i];
		back = v[n-i-1];
		if(front != back)
			return false;	
		if(i >= n-i-1) // when both i and n-i reach the mid, exit loop as the whole vecor has been checked
			break;
	}
	return true;
}

// CTCI's way1
bool is_palindrome1(Node* head) 
{
	// reversing the linked list's first half in place and comparing it to the second
}

void reverse(Node* &head)
{
	
}

int main()
{
	Node* head = NULL;
	insert_at_tail(head, 10);
	insert_at_tail(head, 20);
	insert_at_tail(head, 30);
	insert_at_tail(head, 40);
	insert_at_tail(head, 50);
	display(head);
	cout<<"\n"<<is_palindrome(head)<<"\n"; // should print 0
	
	Node* head1 = NULL;
	insert_at_tail(head1, 1);
	insert_at_tail(head1, 2);
	insert_at_tail(head1, 3);
	insert_at_tail(head1, 2);
	insert_at_tail(head1, 1);
	display(head1);
	cout<<"\n"<<is_palindrome(head1); // should print 1	
	
	delete_all_nodes(head);
	delete_all_nodes(head1);
	
	return 0;
}
