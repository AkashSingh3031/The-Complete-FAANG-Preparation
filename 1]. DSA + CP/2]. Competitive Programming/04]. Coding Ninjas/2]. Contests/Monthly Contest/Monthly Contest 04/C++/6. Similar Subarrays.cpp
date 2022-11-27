/*
    Time Complexity: O(N log N)
    Space Complexity:  O(N)

    where 'N' is the number of elements in the array 'arr'. 
*/

#include<unordered_map>

  
void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, int diff, vector<int> &lazy, vector<int> &tree)
{
    if (lazy[si] != 0)
    {
        tree[si] += lazy[si];
        if (ss != se)
        {
            
            lazy[si*2 + 1]  += lazy[si];
            lazy[si*2 + 2]  += lazy[si];
        }
  
        // Set the lazy value for current node as 0 as it
        // has been updated
        lazy[si] = 0;
    }
  
    // out of range
    if (ss>se || ss>ue || se<us)
        return ;
  
    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree[si] += diff;
  
        // same logic for checking leaf node or not
        if (ss != se)
        {
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
  
    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff, lazy, tree);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff, lazy, tree);
  
    // And use the result of children calls to update this
    // node
    tree[si] = max(tree[si*2+1] , tree[si*2+2]);
}
  
void updateRange(int n, int us, int ue, int diff, vector<int> &lazy, vector<int> &tree)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff, lazy, tree);
}
int getMaxUtil(int ss, int se, int qs, int qe, int si, vector<int> &lazy, vector<int> &tree)
{
    if (lazy[si] != 0)
    {
        tree[si] += lazy[si];
        if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }
  
    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return tree[si];

    int mid = (ss + se)/2;
    return max(getMaxUtil(ss, mid, qs, qe, 2*si+1, lazy, tree), 
           getMaxUtil(mid+1, se, qs, qe, 2*si+2, lazy, tree));
}

int getMax(int n, int qs, int qe, vector<int> &lazy, vector<int> &tree)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
  
    return getMaxUtil(0, n-1, qs, qe, 0, lazy, tree);
}

void constructSTUtil(int arr[], int ss, int se, int si, vector<int> &lazy, vector<int> &tree)
{

    if (ss > se)
        return ;
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }
    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1, lazy, tree);
    constructSTUtil(arr, mid+1, se, si*2+2, lazy, tree);
  
    tree[si] = max(tree[si*2 + 1] , tree[si*2 + 2]);
}
  
void constructST(int arr[], int n, vector<int> &lazy, vector<int> &tree)
{
    constructSTUtil(arr, 0, n-1, 0, lazy, tree);
}

int similarSubarrays(vector<int> &arr){
    
    int n = arr.size();
    vector<int> tree(4*n), lazy(4*n);

    // Keep track of the positions of a number.
    unordered_map<int,vector<int>> pos;

    int emp[n] = {0};

    // Construct the segment tree.
    constructST(emp, n, lazy, tree);
    
    unordered_map<int,int> mark;
    
    for(int i = 0; i < n; i++){
        pos[arr[i]].push_back(i);
    }
    int ans = 0;
    
    for(int i = 0; i < n - 1; i++){
        
        int len = (int)pos[arr[i]].size();
        // If the element is present less than three times, continue.
        if(pos[arr[i]].size()< 3){
            continue;
        }
        // If this element is last occurence we do not need to update it anymore.
        if(mark[arr[i]] == len - 1){
            continue;
        }
        // If this is the second last occurence we remove its contribution.
        if(mark[arr[i]] == len - 2){
            updateRange(n, i, pos[arr[i]][len - 1] - 1, -1, lazy, tree);
            mark[arr[i]] += 1;
            continue;
        }
        // If this is the first occurence we add all the points from second to last occurence.
        if(mark[arr[i]] == 0){
            updateRange(n, pos[arr[i]][1], pos[arr[i]][len-1] - 1, 1, lazy, tree);
            mark[arr[i]] += 1;
            ans = max(ans, getMax(n, i + 1, n - 1, lazy, tree));
        }
        else{
            updateRange(n, 1, pos[arr[i]][len - 1] - 1, -1, lazy, tree);
            updateRange(n, pos[arr[i]][mark[arr[i]] + 1], pos[arr[i]][len - 1] - 1, 1, lazy, tree);
            mark[arr[i]] += 1;
            ans = max(ans, getMax(n + 1, i + 1, n - 1, lazy, tree));
        }
        
    }        
    return ans;

}