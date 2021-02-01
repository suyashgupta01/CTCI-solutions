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

// CTCI's way:

// returns head; basically a copy of the linked list
Node* duplicate(Node* head)
{
	Node *temp = head;
	Node *new_head = NULL;
	
	while(temp != NULL)
	{
		insert_at_tail(new_head, temp->data);
		temp = temp->next;
	}
	
	return new_head;
}

void reverse(Node *&head)
{
	if(head == NULL)
		return;
		
	Node *temp, *next, *prev;
	temp = head;
	prev = NULL;

	while(temp!=NULL)
	{
		next = temp->next; // save the reference of the next node
		temp->next = prev; // reverse this connection/ link
		prev = temp;       // store the address of the current node to be used in the next iteration
		temp = next;       // update temp; now temp points to the next node
	}
	
	// when loop is done, prev points to the last node or the original LL = first node of reversed LL
	head = prev;
}

bool is_palindrome1(Node* head) 
{
	// Create a copy of the linked list
	Node *head_old = duplicate(head);
	
	// reversing the linked list in place
	reverse(head);
	
	// Compare the linked lists 
	// Actually, We only need to compare the first halves of the linked lists, 
	// for that we can calcuate the length and iterate upto length/2, but not doing that for now
	Node* temp1 = head_old; // original LL
	Node* temp2 = head;     // reversed LL
	while(temp1 != NULL and temp2 != NULL)
	{
		if(temp1->data != temp2->data)
			return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
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
//	cout<<"\n"<<is_palindrome(head)<<"\n"; // should print 0
	cout<<"\n"<<is_palindrome1(head)<<"\n"; // should print 0
	delete_all_nodes(head);
	
	Node* head1 = NULL;
	insert_at_tail(head1, 1);
	insert_at_tail(head1, 2);
	insert_at_tail(head1, 3);
	insert_at_tail(head1, 2);
	insert_at_tail(head1, 1);
	display(head1);
//	cout<<"\n"<<is_palindrome(head1); // should print 1	
	cout<<"\n"<<is_palindrome1(head1); // should print 1	
	delete_all_nodes(head1);

// Just to test reverse()
//	Node* head = NULL;
//	insert_at_tail(head, 10);
//	insert_at_tail(head, 20);
//	insert_at_tail(head, 30);
//	insert_at_tail(head, 40);
//	insert_at_tail(head, 50);
//	insert_at_tail(head, 60);
//	display(head);
//	cout<<"\n\n";
//	reverse(head);
//	display(head);
//	delete_all_nodes(head);
	
	return 0;
}
