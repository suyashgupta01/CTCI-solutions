// ----------- boilerplate starts ---------

#include<iostream>
#include<vector>
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

void delete_all_nodes(Node* head) // empty the memory to avoid leaked memory
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

// taking head by reference as we'll modify original linked list
void remove_dups(Node* &head)
{
	vector<int> unique_elements;
	int data;
	Node* temp = head;
	
	while(temp != NULL)
	{
		int data = temp->data;
		if (data_exists(data, unique_elements))
			//delete this node
		else 
		
		temp = temp->next;
	}
}

bool data_exists(int data, &v)
{
	for(int i=0; i<v.size(); i++)
	{
		if(data == v[i])
			return true;
	}
	return false;
}

int main()
{
	Node* head = NULL;
	insert_at_tail(head, 1);
	insert_at_tail(head, 55);
	insert_at_tail(head, 3);
	insert_at_tail(head, 4);
	insert_at_tail(head, 1);
	insert_at_tail(head, 55);
	insert_at_tail(head, 101);		
	return 0;
}
