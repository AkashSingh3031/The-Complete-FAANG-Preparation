/*
    Time Complexity: O(N)
    Space Complexity: O(K)

    where 'N' is the length of the string and 'K' is constraint described in the problem.
*/

int kString(int k, string s){
    int n = s.size();

    // Creating a 2-D array 'occ[k][2]'.
    int occ[k][2];
    for (int i = 0; i < k; i++){
        for (int j = 0; j < 2; j++){
            occ[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        if (s[i] == '0'){

            // Incrementing occurrence of 0 at (i % k).
            occ[i % k][0]++;
        }
        else{

            // Incrementing occurrence of 1 at (i % k).
            occ[i % k][1]++;
        }
    }

    // Creating variable 'ans' to store our answer.
    int ans = 0;

    for (int i = 0; i < k; i++){
        
        // We can change those characters that has minimum occurrence.
        ans += min(occ[i][0], occ[i][1]);
    }

    // We are returning the answer here.
    return ans;
}