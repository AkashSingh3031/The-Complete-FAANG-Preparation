double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double low = 1.0, high = (double)m;
    double eps = 1e-6;
    
    while(high - low > eps) {
        double mid = (low + high) / 2.0;
        double val = 1.0;
        
        // Calculate mid^n
        for(int i = 0; i < n; i++) {
            val *= mid;
        }
        
        if(val < m) {
            low = mid;
        } else {
            high = mid;
        }
    }
    
    return low;
}
