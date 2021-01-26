#include<iostream>
using namespace std;

// To access the members of a structure/ class 
// using an object, we use . operator

// To access the members of a structure/ class 
// using a pointer, we use -> operator

// "head" points to the first node of linked list
// head = NULL if linked list = empty

// We take head by ref when we're modifying the linked list
// else we take it by value

// excellent explaination:
// https://www.youtube.com/watch?v=Crqgl10aIGQ

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
			{ return "\n" + to_string(key) + " found at position " + to_string(location_counter); }
		temp = temp->next;
	}
	return "\n" + to_string(key) + " not found";
}

int main()
{
	Node* head = NULL;
	insert_at_tail(head, 1);
	insert_at_tail(head, 2);
	insert_at_tail(head, 3);
	insert_at_tail(head, 4);
	insert_at_tail(head, 5);
	insert_at_head(head, 77);
	display(head);
	cout<<"\n"<<search(head, 3);
	cout<<"\n"<<search(head, 223232);
}
