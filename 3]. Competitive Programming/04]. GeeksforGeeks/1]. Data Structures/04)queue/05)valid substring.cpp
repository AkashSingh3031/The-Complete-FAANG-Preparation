int findMaxLen(string s) {
        // code here
        stack<int>st;
        st.push(-1);
        int i;
        string str;
        int mx=0;
        for(i=0;i<s.length();i++)
        {
        if(s[i]=='(')
        {
           st.push(i);
        }
        else if(s[i]==')')
        {
            st.pop();
            
            if(!st.empty())
            {
               
              mx=max(mx,i-st.top());
            }
            else
            {
                st.push(i);
            }
        }
        }
        return mx;
        
    }