


#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	int t[10]={0};
	int n=s.length()	;
	for(int i=0;i<n;i++){
		if(s[i] == '0') {
            t[0]++;
        } else if(s[i] == '1') {
            t[1]++;
        } else if(s[i] == '2') {
            t[2]++;
        } else if(s[i] == '3') {
            t[3]++;
        } else if(s[i] == '4') {
            t[4]++;
        }
		else if(s[i] == '5') {
            t[5]++;
        }
		else if(s[i] == '6') {
            t[6]++;
        }
		else if(s[i] == '7') {
            t[7]++;
        }
		else if(s[i] == '8') {
            t[8]++;
        }
		else if(s[i] == '9') {
            t[9]++;
        }
	}							
	for(int i=0;i<10;i++){
		cout<<i<<" "<<t[i]<<"\n";
	}	
}

