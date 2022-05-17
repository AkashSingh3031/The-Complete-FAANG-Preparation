#include <bits/stdc++.h>
using namespace std;

class que
	{
		stack<int>s1;

		public:

		void push(int x)
			{
				s1.push(x);
			}

		int pop()
			{
				if(s1.empty())
					{
						cout<<"Empty Queue";
						return -1;
					}

				int x = s1.top();
				s1.pop();

				if(s1.empty())
					{
						return x;
					}
				int item = pop();
				s1.push(x);
				return item;

			}

		bool isempty()
			{
				if(s1.empty()){ return true;}
				return false;
			}	

	};

int main()
{
	que q;
	int n,x;
	cin>>n;

	for(int i=0;i<n;i++)
		{
			cin>>x;
			q.push(x);
		}

	while(!q.isempty())
		{
			cout<<q.pop()<<" ";
		}

	return 0;
}
