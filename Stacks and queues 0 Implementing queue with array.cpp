#include<iostream>
using namespace std;

class Queue
{
	private:
	int front_index, rear_index, n; int* arr;
	
	public:
	Queue(int x)		
	{
		arr = new int[x]; n = x; front_index = -1; rear_index = -1;
	}
	void enqueue(int x) // insert element
	{
		if(full()) 
			return; // overflow | queue full
		else if(empty())
		{ 
			front_index++; rear_index++; 
		}
		else
			rear_index++;
		arr[rear_index] = x;
	}
	void dequeue() // delete element
	{
		if(empty()) 
			return; // underflow | queue empty
		else if(front_index == rear_index) // only one value left in queue
		{
			// reset the queue -> it will now be fully empty
			front_index = -1; rear_index = -1;
		}
		else
			front_index++;
	}
	bool empty()
	{
		return(front_index == -1 and rear_index == -1);
	}
	bool full()
	{
		return(rear_index == n-1);
	}
	int front()
	{
		if(empty()) return -1;
		return arr[front_index];
	}
	int rear()
	{
		if(empty()) return -1;
		return arr[rear_index];
	}
};

int main()
{
	Queue q(5);
	cout<<q.empty()<<'\n';
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	cout<<q.front()<<'\n'; // prints 10
	cout<<q.rear()<<'\n'; // prints 30
	q.dequeue(); q.dequeue(); q.dequeue();
	cout<<q.front()<<'\n'; // prints -1
	cout<<q.rear()<<'\n'; // prints -1
}
