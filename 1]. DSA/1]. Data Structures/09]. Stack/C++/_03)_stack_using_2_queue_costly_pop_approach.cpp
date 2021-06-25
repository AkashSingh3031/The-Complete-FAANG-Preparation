#include <bits/stdc++.h>
using namespace std;

class stackk
	{
		int n;
		queue<int> q1;
		queue<int> q2;

		public:

		stackk()
			{
				n = 0;
			}

		void push(int x)
			{
				q1.push(x);
				n++;
			}

		void pop()
			{
				if(q1.empty())
					{
						cout<<"Empty Stack";
						return;
					}
				while(q1.size()!=1)
					{
						q2.push(q1.front());
						q1.pop();
					}
				q1.pop();
				n--;
				queue<int> temp = q1;
				q1 = q2;
				q2 = temp;
			}

		int top()
			{
				if(q1.empty())
					{
						cout<<"Empty Stack";
						return -1;
					}
				while(q1.size()!=1)
					{
						q2.push(q1.front());
						q1.pop();
					}
				int ans = q1.front();
				q2.push(ans);
				queue<int> temp = q1;
				q1 = q2;
				q2 = temp;
				return ans;
			}
		
		int size(){return n;}

	};

int main()
{
	stackk s;
	int n,x;
	cin>>n;

	for(int i=0;i<n;i++)
		{
			cin>>x;
			s.push(x);
		}

	while(s.size()>0)
		{
			cout<<s.top()<<" ";
			s.pop();
		}

	return 0;
}
