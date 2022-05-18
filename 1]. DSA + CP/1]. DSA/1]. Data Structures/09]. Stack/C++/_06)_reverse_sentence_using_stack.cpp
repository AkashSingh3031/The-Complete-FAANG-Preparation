#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <ctype.h>

using namespace std;

void reversestring(string s)
    {
        stack<string> st;

        for(int i=0;i<s.length();i++)
            {
                string word="";
                while(s[i]!=' ' && i<s.length())
                    {
                        word += s[i];
                        i++;
                    }
                st.push(word);
            }
        
        while(!st.empty())
            {
                cout<<st.top()<<" ";
                st.pop();
            }
        cout<<endl;
    }

int main()
    {
        string s;
        cin.ignore();
        getline(cin,s);
        reversestring(s);

        return 0; 
    }
