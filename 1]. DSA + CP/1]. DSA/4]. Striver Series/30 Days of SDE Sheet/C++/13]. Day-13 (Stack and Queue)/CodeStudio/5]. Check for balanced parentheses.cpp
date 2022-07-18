bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    for(auto i:expression)  
    {
        if(i=='(' or i=='{' or i=='[') 
            st.push(i);
        else
        {
            if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) 
                return false;
            st.pop();
        }
    }
    return st.empty();
}