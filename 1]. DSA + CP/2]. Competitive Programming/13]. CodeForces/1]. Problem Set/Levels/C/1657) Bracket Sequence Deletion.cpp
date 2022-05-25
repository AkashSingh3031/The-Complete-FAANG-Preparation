// https://codeforces.com/contest/1657/problem/C

#include <iostream>
#include <vector>

using namespace std;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    
    int remainingLength = n, cnt = 0;
    
    for(int start = 0; start < n; ++start){
        int sum = 0, minSum = 0;
        int cntSwitch = 1;
        
        bool found = false;
        
        for(int end = start; end < n; ++end){
            if(s[end] == '('){
                ++sum;
            }else{
                --sum;
            }
            
            minSum = min(minSum, sum);
            
            if(sum == 0 && minSum >= 0){
                // cout << "type 1 from " << start << " ~> " << end << endl;
                remainingLength -= (end - start + 1);
                found = true;
                
                start = end;
                break;
            }
            
            //
            
            if(end > start && s[end] != s[end - 1]) ++cntSwitch;
            
            if((end == start + 1 && s[end] == s[start]) || cntSwitch == 3){
                // cout << "type 2 from " << start << " ~> " << end << endl;
                remainingLength -= (end - start + 1);
                found = true;
                
                start = end;
                break;
            }
        }
        
        if(found){
            ++cnt;
        }else break;
    }
    
    cout << cnt << " " << remainingLength << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}