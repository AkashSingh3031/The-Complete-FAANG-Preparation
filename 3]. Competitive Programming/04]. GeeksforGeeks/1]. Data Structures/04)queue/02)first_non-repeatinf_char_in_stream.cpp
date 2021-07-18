string FirstNonRepeating(string A){
		    // Code here
		    int j;
		    queue<char>q;
		    string b;
		   int count[26]={0};
		    for(j=0;j<A.length();j++)
		    {
		        q.push(A[j]);
		        
		        count[A[j]-'a']++;
		        while(!q.empty())
		        {
		            if(count[q.front()-'a']>1)
		            {
		                q.pop();
		            }
		            else
		            {
		                b.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty())
		        {
		            b.push_back('#');
		        }
		    }
		    return b;
		}