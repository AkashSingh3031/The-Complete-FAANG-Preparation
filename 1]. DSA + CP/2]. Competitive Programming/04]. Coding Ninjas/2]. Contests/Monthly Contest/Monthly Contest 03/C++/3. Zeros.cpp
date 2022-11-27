long long solution(long long a, long long b){
    
    //Variable for storing 10^b
    long long B = 1;

    // Calculating 10^b abd storing it it the variable B
    for(int i = 0; i<b; i++){
        B *= 10;
    }

    //Variable for storing the answer
    long long ans;

    //Calculating the Lowest Common Multiple of a and 10^b
    ans = (a/__gcd(a,B)) * B;

    return ans;
}