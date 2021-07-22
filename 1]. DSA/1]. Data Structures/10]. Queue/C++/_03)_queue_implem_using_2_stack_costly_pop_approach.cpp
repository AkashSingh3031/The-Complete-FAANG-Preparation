#include <bits/stdc++.h>
using namespace std;

class que
	{
		stack<int>s1;
		stack<int>s2;

		public:

		void push(int x)
			{
				s1.push(x);
			}

		int pop()
			{
				if(s1.empty() and s2.empty())
					{
						cout<<"Empty Queue";
						return -1;
					}

				if(s2.empty())
					{
						while(!s1.empty())
							{
								s2.push(s1.top());
								s1.pop();
							}
					}
				int topval = s2.top();
				s2.pop();
				return topval;
			}

		bool isempty()
			{
				if(s1.empty() and s2.empty()){ return true;}
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
