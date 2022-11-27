/*
    Time Complexity: O((Q + N) * log(N))
    Space Complexity: O(N)

    Where ‘Q’ is the number of friends and ‘N’ is the length of the string’.
*/

struct fenwickTree {
    vector<int> bit;
    int n;

    // Constructor for Fenwick Tree.
    fenwickTree(int n) 
    {
        this->n = n;

        // Initializing with 0. 
        bit.assign(n, 0);
    }


    // Function to add value at specific index.
    void add(int idx, int delta) 
    {
        for (; idx < n; idx = idx | (idx + 1))
        {
            bit[idx] += delta;
        }
    }

    // Function to return prefix sum.
    int sum(int r) 
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
        {
            ret += bit[r];
        }
        return ret;
    }

  
};

string birthdayBash(string s, vector<vector<int>> query)
{
    int n = s.size();
    int q = query.size();

    // Creating a Fenwick Tree also known as Binary Index Tree. 
    fenwickTree F(n);
    for(int i = 0; i < q; i++){
        int type = query[i][0];
        int x = query[i][1];

        if(type == 1)
        {   
            // Adding 1 at index 'x'.
            F.add(x, 1);

            // Adding -1 at index 'n' - 'x'. 
            F.add(n - x, -1);
            
        }
        else
        {   
            // Finding prefix sum from 0 to index 'x'.
            int cn = F.sum(x);

            // If number of operation is odd, we need to update at index 'n' - 'x' - 1.
            if(cn % 2 == 1) 
            {
                x = n - x - 1;
            }

            
            // Updating the character at index 'x'
            if(s[x] == 'z')
            {
                s[x] = 'a';
            }
            else
            {
                s[x]++;
            }
        }
    }
    for(int i = 0; i < n / 2; i++)
    {   
        // Finding prefix sum from 0 to index 'x'.
        int cn = F.sum(i);
        
        // If number of operation is odd, swap index 'i' and 'n' - 'i' - 1;
        if(cn % 2 == 1)
        {
            swap(s[i], s[n - i - 1]);
        }
            
    }
    return s;  
}