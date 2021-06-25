
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
  
    bool ispar(string x)
    { stack<char> s;
        for(int i=0;i<x.length();i++)
        {
            if(x[i]=='('||x[i]=='{'||x[i]=='[')
            s.push(x[i]);
            else if(s.empty()==true)
            return false;
            else
            {
            switch(x[i])
            {
                case')':
                {
                if(s.top()!='(')
                return false;
                s.pop();
                break;}
                case'}':
                {
                if(s.top()!='{')
                return false;
                s.pop();
                break;}
            
            case']':
                {
                if(s.top()!='[')
                return false;
                s.pop();
                break;}
            }
        }
    }
    if(s.empty()==false)
    return false;
    return true;
}
};


int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  
