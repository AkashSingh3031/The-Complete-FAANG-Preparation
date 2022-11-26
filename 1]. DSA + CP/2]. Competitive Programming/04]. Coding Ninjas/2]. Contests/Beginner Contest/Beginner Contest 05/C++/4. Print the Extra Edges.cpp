/*
	Time complexity: O(E x log(N))
	Space complexity: O(N)
	
	Where 'N' and 'E' are the total number of nodes and edges in the given graph, respectively.
*/

// The required Comparator Function.
int find(int x, vector<int> &parent){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent[x], parent);
}

vector<vector<int>> extraEdges(int n, int e, vector<vector<int>> &edges){
    vector<vector<int>> ans;
    vector<int> parent(n);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    for(auto x: edges){
        int vParent = find(x[0], parent);
        int uParent = find(x[1], parent);
        if(vParent == uParent){
            ans.push_back(x);
        }else{
            parent[vParent] = uParent;
        }
    }
    return ans;
}