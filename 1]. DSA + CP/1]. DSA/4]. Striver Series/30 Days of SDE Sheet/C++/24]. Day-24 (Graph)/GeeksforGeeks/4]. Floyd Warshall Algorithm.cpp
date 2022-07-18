//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    
	    for(int k=0; k<n; k++){
	        for(int u=0; u<n; u++){
	            for(int v=0; v<n; v++){
	                if(matrix[u][k] != -1 and matrix[k][v] != -1){
	                    if(matrix[u][v] == -1){
	                        matrix[u][v] = matrix[u][k] + matrix[k][v];
	                    }
	                    else{
	                        matrix[u][v] = min(matrix[u][v], matrix[u][k]+matrix[k][v]);
	                    }
	                }
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends