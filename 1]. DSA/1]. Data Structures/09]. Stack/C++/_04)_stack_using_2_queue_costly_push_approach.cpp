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
				q2.push(x);
				while(!q1.empty())
					{
						q2.push(q1.front());
						q1.pop();
					}
				queue<int> temp = q1;
				q1 = q2;
				q2 = temp;
				n++;
			}

		void pop()
			{
				if(q1.empty())
					{
						cout<<"Empty Stack";
						return;
					}
				q1.pop();
				n--;
			}

		int top(){	return q1.front();}
		
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
