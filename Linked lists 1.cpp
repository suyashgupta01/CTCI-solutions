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

// function to check if a given value already exists in a vector
bool data_exists(int data, vector<int> v)
{
	for(int i=0; i<v.size(); i++)
	{
		if(data == v[i])
			return true;
	}
	return false;
}

// taking head by reference as we'll modify original linked list
void remove_dups(Node* &head)
{
	vector<int> unique_elements, indices_to_be_deleted;
	int data, index_counter;
	Node* temp_aage = head->next; // points to 1th node
	Node* temp_piche = head;      // points to 0th node
	
	while(temp_aage != NULL)
	{
		index_counter++;
		int data = temp_aage->data;
		if (data_exists(data, unique_elements))
			{	
				indices_to_be_deleted.push_back(index_counter);
			}
		else
			unique_elements.push_back(data);
		
		temp_aage = temp_aage->next;
		temp_piche = temp_piche->next;
	}
	
	for(int i = 0; i<indices_to_be_deleted.size(); i++)
	{
		cout<<indices_to_be_deleted[i]<< " ";
	}
	
	for(int i = 0; i<indices_to_be_deleted.size(); i++)
	{
		delete_by_location(head, indices_to_be_deleted[i]);
		
		// now as one element has been deleted
		// uske aage/ right vale sab ke index -1 ho gaye
		for(int j = i+1; i<indices_to_be_deleted.size(); j++)
		{
			indices_to_be_deleted[j]--;
		}
	}
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
	insert_at_tail(head, 25);	
	insert_at_tail(head, 1);
	insert_at_tail(head, 250);		
	display(head);
	cout<<"\n";
	remove_dups(head);
	display(head);
	cout<<"\n";
	delete_all_nodes(head);	
	return 0;
}
