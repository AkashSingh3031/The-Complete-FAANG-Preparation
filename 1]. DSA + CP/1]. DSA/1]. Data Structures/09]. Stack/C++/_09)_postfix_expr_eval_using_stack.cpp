#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

int postfixevalutaion(string);

int main()
    {
        string s;
        cin>>s;
        cout<<postfixevalutaion(s);

        return 0;
    }

int postfixevalutaion(string s)
    {
        stack<int> st;
        
        for(int i=0;i<s.length();i++)
            {
                if(s[i]>='0' && s[i]<='9')
                    {
                        st.push(s[i]-'0');
                    }
                else
                    {
                        int op2=st.top();
                        st.pop();
                        int op1=st.top();
                        st.pop();

                        switch(s[i])
                            {
                                case '+':
                                    st.push(op1+op2);
                                    break;
                                
                                case '-':
                                    st.push(op1-op2);
                                    break;

                                case '*':
                                    st.push(op1*op2);
                                    break;

                                case '/':
                                    st.push(op1/op2);
                                    break;

                                case '^':
                                    st.push(pow(op1,op2));
                                    break;
                            }
                    }
            }
        return st.top();
    }
