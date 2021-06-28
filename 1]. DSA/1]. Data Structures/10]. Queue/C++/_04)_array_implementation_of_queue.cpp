#include<bits/stdc++.h>
using namespace std;

class queu
    {
        int *arr;
        int front;
        int back;

        public:

        queu(int n)
            {
                arr = new int[n];
                front = -1;
                back = -1;
            }

        void push(int x,int n)
            {
                if(back == n-1)
                    {
                        cout<<"Queue Overflow";
                        return;
                    }
                back++;
                arr[back] = x;
                if(front == -1){front++;}
            }
        
        void pop()
            {
                if(front>back || front == -1)
                    {
                        cout<<"Queue Underflow";
                        return;
                    }
                front++;
            }

        int peek()
            {
                if(front>back || front == -1)
                    {
                        cout<<"Queue is Empty";
                        return -1;
                    }
                return arr[front];
            }

        bool empty()
            {
                if(front>back || front == -1)
                    {
                        return true;
                    }
                return false;
            }

    };

int main()
    {
        int n,x;
        cin>>n;

        queu q(n);
        
        for(int i=0;i<n;i++)
            {
                cin>>x;
                q.push(x,n);
            }
        
        while(!q.empty())
            {
                cout<<q.peek()<<" ";
                q.pop();
            }

    }
