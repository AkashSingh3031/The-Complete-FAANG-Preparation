class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long nn = n;
        if(nn < 0)
            nn = -1*nn;
        while(nn) {
            if(nn%2 != 0) {
                res = res*x;
                nn--;
            }
            else {
                x = x*x;
                nn = nn/2;
            }
        }
        if(n<0)
            res = 1/res;
        return res;
    }
};
