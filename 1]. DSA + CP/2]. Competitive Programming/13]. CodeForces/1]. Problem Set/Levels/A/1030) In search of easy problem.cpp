#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int maxim = 0;
  for(int i=0;i<n;i++){
    int ans;
     cin >> ans;
    maxim = max(maxim ,ans);
  }
  if(maxim == 1)
    cout << "HARD";
  if(maxim == 0)
    cout << "EASY";
}
