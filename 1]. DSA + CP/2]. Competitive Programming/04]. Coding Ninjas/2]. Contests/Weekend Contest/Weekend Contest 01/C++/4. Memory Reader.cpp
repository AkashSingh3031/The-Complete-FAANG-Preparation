/*
    Time Complexity: O(2 ^ N)
    Space Complexity: O(1)

    where 'N' is the number of good memory points. 
*/

string memoryReader(vector<int> &memory) {
    int n = memory.size();
    
    // Check all possible combinations using bitmasking.
    for(int i = 1; i < (1<<n); i++){
        
        // Store the last memory point and the last jump length.
        int lastPoint = memory[0];
        int lastJump = memory[0];
        
        // If the last memory location is not included, the set is invalid.
        if(!(i & (1<<(n - 1))) || !(i%2)){
            continue;
        }
        
        bool flag = true;
        
        for(int j = 1; j < n; j++){
            if((1 << j)&i){                

                int currJump = memory[j] - lastPoint;
                
                // Check if the jump can be made
                if (abs(currJump - lastJump) > 1){
                    flag = false;
                    break;
                }
                
                lastPoint = memory[j];
                lastJump = currJump;
            }
        }
        // This set is valid.
        if (flag){
            return "YES";
        }
    }
        
    // No solution found.
    return "NO";
}
