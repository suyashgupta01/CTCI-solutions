#include<iostream>
#include<string>
#include<vector> // using this instead of Linked List

using namespace std;

class Queue_
{
	// fill this
};

// My approach: Not as good as CTCI's as it requires iteration through the vector in dequeue_cat(), dequeue_dog().
class Queue
{
	private:
		vector<pair<string, string>> v; // animal_name, animal_type
	public:
		bool empty()
		{
			return(v.size() == 0);
		}
		void enqueue_any(string animal_name, string animal_type)
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
	Queue q;
	cout<<q.empty()<<"\n"; // prints 1
	q.enqueue_any("tommy", "dog");
	q.enqueue_any("tom", "cat");
	q.enqueue_any("bob", "cat");
	q.enqueue_any("tiffany", "dog"); 
	cout<<q.empty()<<"\n"; // prints 0
	cout<<q.dequeue_any()<<"\n"; // prints tommy
	cout<<q.dequeue_dog()<<"\n"; // prints tiffany
	cout<<q.dequeue_dog()<<"\n"; // prints no dog
	cout<<q.dequeue_cat()<<"\n"; // prints tom
}
