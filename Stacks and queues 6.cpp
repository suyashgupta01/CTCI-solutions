#include<iostream>
#include<string>
#include<vector> // using this instead of Linked List

using namespace std;

// CTCI's way
class Queue_
{
	// 2 seperate stacks for cats and dogs
	private:
		vector<pair<int,string>> dogs;
		vector<pair<int,string>> cats;
		int age = 0; // will be use to find the oldest animal to dequeue

	public:
		void enqueue(string animal_name, string animal_type)
		{
			if(animal_type == "cat")
				cats.push_back({age, animal_name});
			else if(animal_type == "dog")
				dogs.push_back({age, animal_name});
			age--;
			// else if it's neither a cat not a dog, do nothing
		}
		string dequeue_any()
		{
			// take a look at the tops of both stacks,
			// dequeue the older one
			string temp;
			if(cats.empty() and dogs.empty())
				return "no animal left";
			else if(cats.empty() and !dogs.empty()) // only cats left
			{
				temp = cats.begin()->second;
				cats.erase(cats.begin());
			}
			else if(!cats.empty() and dogs.empty()) // only dogs left
			{
				temp = dogs.begin()->second;
				dogs.erase(dogs.begin());
			}
			else // both cats and dogs are there
			{
				if(cats.begin()->first > dogs.begin()->first)
				{
					temp = cats.begin()->second;
					cats.erase(cats.begin());
				}
				else
				{
					temp = dogs.begin()->second;
					dogs.erase(dogs.begin());
				}
			}
			return temp;
		}
		string dequeue_cat()
		{
			if(cats.empty())
				return "no cat left";
			string temp = cats.begin()->second;
			cats.erase(cats.begin());
			return temp;
		}
		string dequeue_dog()
		{
			if(dogs.empty())
				return "no dog left";
			string temp = dogs.begin()->second;
			dogs.erase(dogs.begin());
			return temp;
		}
};

// My approach: Not as good as CTCI's as it requires iteration through the vector in dequeue_cat(), dequeue_dog().
class Queue
{
	private:
		vector<pair<string, string>> v; // animal_name, animal_type
		// no need to declare f, r as we have v.begin() and v.end() 
	public:
		bool empty()
		{
			return(v.size() == 0);
		}
		void enqueue(string animal_name, string animal_type)
		{
			// not checking for full as using vector
			v.push_back({animal_name, animal_type});
		}
		string dequeue_any() // returns name of animal
		{
			string temp;
			if(empty())
				return "no animal left";
			else
			{
				temp = v.begin()->first;
				v.erase(v.begin());
			}
			return temp; 
		}
		string dequeue_cat()
		{
			string temp;
			if(empty())
				return "no animal left";
			else
			{
				// iterate via vector until a cat if found
				vector<pair<string, string>>::iterator it = v.begin();
				while(it != v.end())
				{
					if(it->second == "cat")
					{
						temp = it->first;
						v.erase(it);
						return temp; 
					}
					it++;
				}
				return "no cat found";
			}		
		}
		string dequeue_dog()
		{
			string temp;
			if(empty())
				return "no animal left";
			else
			{
				// iterate via vector until a dog if found
				vector<pair<string, string>>::iterator it = v.begin();
				while(it != v.end())
				{
					if(it->second == "dog")
					{
						temp = it->first;
						v.erase(it);
						return temp; 
					}
					it++;
				}
				return "no dog found";
			}		
		}
};

int main()
{
	Queue_ q;
//	cout<<q.empty()<<"\n"; // prints 1
	q.enqueue("tommy", "dog");
	q.enqueue("tom", "cat");
	q.enqueue("bob", "cat");
	q.enqueue("tiffany", "dog"); 
//	cout<<q.empty()<<"\n"; // prints 0
	cout<<q.dequeue_any()<<"\n"; // prints tommy
	cout<<q.dequeue_dog()<<"\n"; // prints tiffany
	cout<<q.dequeue_dog()<<"\n"; // prints no dog
	cout<<q.dequeue_cat()<<"\n"; // prints tom
}
