/*
    Time Complexity: O(Q * M)
    Space Complexity: O(M)

    Where 'Q' is the number of queries and 'M' is the length of charming array.
*/

int mod = 1000000007;
int MAX = 5005;


// Extended eucliden algorithm that helps in finding modular multiplicative inverse of 'num'.
long long extGcd(long long &x, long long &y, long long num, long long mod)
{
    long long x1, y1;
    if(num == 0)
    {
        x = 0;
        y = 1;
        return mod;
    }

    long long gcd = extGcd(x1, y1, mod % num, num);

    x = y1 - (mod / num) * x1;

    y = x1;

    return gcd;
}

// Utility function to return modular multiplicative inverse of 'num'.
long long modInverse(long long num)
{
    long long x, y;
    long long gcd = extGcd(x, y, num, mod);
    
    if(x < 0)
    {
        x += mod;
    }

    return x;
}

// Utility function to find factorial and modular multiplicative inverse .
void preCompute(vector<long long> &factorial, vector<long long> &inverse)
{
    factorial[0] = 1;
    inverse[0] = 1;
    inverse[1] = 1;

    for(int i = 1; i < MAX; i++)
    {
        factorial[i] = (factorial [i - 1] * i) % mod;
        inverse[i] = modInverse(factorial[i]);
    }

    return ;
}

// Utility function to find 'x' raise to the power 'n' % mod.
long long power(long long x, long long n)
{
    if(x == 0)
    {
        return 0;
    }
    if(x==1 || n==0)
    {
        return 1;
    }

    if(n & 1)
    {
        return (power((x * x) % mod, n / 2) * x) % mod;    
    }
    return power((x * x) % mod, n / 2);
}

// Utility function to return nCk % mod  value.
long long nCk (long long n, long long k, vector<long long> & factorial, vector<long long> & inverse)
{
    // nCk is equal to n! / k! (n-k)! .
    return (((factorial[n] * inverse[k] ) % mod ) * inverse[n - k] ) % mod;
}

vector<int> charmingArr(int q, vector< vector<int> > &queries)
{
    // Array to store result.
    vector<int> result;

    // Array to store the factorial of natural numbers.
    vector<long long> factorial(MAX);

    // Array to store the inverse of above factorial numbers.
    vector<long long> inverse(MAX);

    // Pre-Calculation of factorial and Inverse to avoid time overhead per query.
    preCompute(factorial, inverse);

    // Loop for each query.
    for(int i = 0; i < q; i++)
    {   
        
        // Store the length of charming array in variable 'm'.
        long long m = queries[i][0];

        // Store range of elements of array in 'n'.
        long long n = queries[i][1];

        // Take variable that stores the number of ways to fill the gap left to first 'n'.  
        long long npowx1 = 1;

        // Take variable that stores the number of ways to fill the gap right to first 'n'.  
        long long npowx = power(n, m - n);

        // Find modular multiplicative inverse of 'n'.
        long long inverseN = modInverse(n);
        
        // Variable to store the answer of query 'i'.
        long long ans=0;


        // Loop from 'n' to 'm'.
        for(int j = n; j <= m; j++)
        {
            // Store the current nCk value.
            long long nck = nCk (j - 1, n - 1, factorial, inverse);
            
            // Update answer.
            ans = ( ans + ((nck * npowx) % mod * npowx1) % mod ) % mod;
            
            // Update 'npowx1'.
            npowx1 = (npowx1 * (n - 1)) % mod;
            
            // Update 'npowx'.
            npowx = (npowx * inverseN) % mod;
        }

        // Push the answer of 'i'th query in 'result' Array.
        result.push_back((int)ans);
    }

    // Return result.
    return result;
}