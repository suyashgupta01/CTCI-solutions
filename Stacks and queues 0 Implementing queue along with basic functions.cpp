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
		if(front_index == rear_index) return; // overflow | queue full
		
		front_index++;
		arr[front_index] = x;
	}
	void dequeue() // delete element
	{
		if(front_index == -1 and rear_index == -1) return; // underflow | queue empty
		
		rear_index--;
	}
	bool empty()
	{
		return(front_index == -1 and rear_index == -1);
	}
	int front()
	{
		if(front_index == -1) return -1;
		return arr[front_index];
	}
	int rear()
	{
		if(rear_index == -1) return -1;
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
	cout<<q.front()<<'\n';
	cout<<q.rear()<<'\n';
	q.dequeue(); q.dequeue(); q.dequeue();
	cout<<q.front()<<'\n';
	cout<<q.rear()<<'\n';
}
