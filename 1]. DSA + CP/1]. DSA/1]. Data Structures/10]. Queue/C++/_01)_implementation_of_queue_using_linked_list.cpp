#include <bits/stdc++.h>
using namespace std;

class node
	{
		public:
		int data;
		node* next;
		node(int x)
			{
				data = x;
				next = NULL;
			}
	};

class que
	{
		node* front;
		node* back;
		
		public:

		que()
			{
				front = NULL;
				back = NULL;	
			}

		void push(int x);
		void pop();
		int peek();
		bool isempty();
	};

void que::push(int x)
	{
		node* n = new node(x);
		
		if(isempty())
			{
				front = n;
				back = n;
			}

		back->next = n;
		back = n;

	}

void que::pop()
	{
		if(isempty())
			{
				cout<<"Queue is empty";
				return ; 
			}
		node* todelete = front;
		front = front->next;
		delete todelete;
	}

int que::peek()
	{
		if(isempty())
			{
				cout<<"Queue is empty";
				exit(1);
			}
		return front->data;
	}

bool que::isempty()
	{
		if(front == NULL)
			{
				return true;
			}
		else{return false;}
	}

int main()
{
	que q;
	int n,m,x;

	cin>>n;
	for(int i=0;i<n;i++)
		{
			cin>>x;
			q.push(x);
		}

	while(!q.isempty())	
		{
			cout<<q.peek()<<" ";
			q.pop();
		}

	return 0;
}
