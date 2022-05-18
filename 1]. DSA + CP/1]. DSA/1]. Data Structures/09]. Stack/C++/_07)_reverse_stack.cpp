#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <ctype.h>

using namespace std;

void insertatbottom (stack<int> &st, int ele)
    {
        if(st.empty())
            {
                st.push(ele);
                return;
            }
        int topele = st.top();
        st.pop();
        insertatbottom(st,ele);

        st.push(topele);
    }

void reversestack(stack<int> &st)
    {
        if(st.empty())
            {
                return;
            }

        int ele = st.top();
        st.pop();
        reversestack(st);
        insertatbottom(st,ele);
    }

int main()
    {
        stack<int> st;
        int n,e;
        cin>>n;
        for(int i=0;i<n;i++)
            {
                cin>>e;
                st.push(e);
            }
            
         reversestack(st);
        
        while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
            }

        return 0; 
    }
