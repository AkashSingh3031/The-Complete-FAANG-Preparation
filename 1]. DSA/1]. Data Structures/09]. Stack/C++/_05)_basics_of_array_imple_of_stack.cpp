#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;

class stack{
    int* arr;
    int top;

    public:
    stack(int n)
        {
            arr = new int[n];
            top= -1;
        }
    
    void push(int x,int n)
        {
            if(top == n-1)
                {
                    cout<<"\nStack Overflow";
                    return;
                }
            
            top++;
            arr[top] = x;
        }

    void pop()
        {
            if(top == -1)
                {
                    return;
                }
            top--;
        }

    int peek()
        {
            if(top == -1)
                {
                    cout<<"\nNo element ";
                    return -1;
                }
            return arr[top];
        }

    bool empty()
        {
            return top==-1;
        }
};



int main()
    {
        int n,x;
        cin>>n;
        stack st(n);
        

        for(int i=0;i<n;i++)
            {
                cin>>x;
                st.push(x,n);
            }
        
        for(int i=n;i>=0;i--)
            {
                cout<<st.peek()<<" ";
                st.pop();
            }

        return 0; 
    }
