/*
    Time Complexity: O(N * log(N) + Q * log(N))
    Space Complexity: O(N)

    where 'N' and 'Q' represent the number of elements in the 
    array and the number of rounds in the game, respectively.
*/

#include<climits>

/*
 It will take the input array arr, the segment tree array seg_tree, the count
 array cnt, the segment index si, the starting index of the segment ss and the
 ending index of the segment se. It will fill the seg_tree array and the cnt
 array.
*/
void build(vector<int> &arr, vector<int> &seg_tree, vector<int> &cnt, 
            int si, int ss, int se) {

  if(ss == se){

    seg_tree[si] = arr[ss];
    cnt[si] = 1;
    return;
  }

  int mid = (ss + se) / 2;
  build(arr, seg_tree, cnt, 2 * si, ss, mid);
  build(arr, seg_tree, cnt, 2 * si + 1, mid + 1, se);
  
  int fir = seg_tree[2*si];
  int sec = seg_tree[2*si+1];
  
  if(fir == sec){
      cnt[si] = cnt[2*si] + cnt[2*si+1];
  }
  else if(fir < sec){
      cnt[si] = cnt[2*si];
  }
  else{
      cnt[si] = cnt[2*si+1];
  }

  seg_tree[si] = min(seg_tree[2*si], seg_tree[2*si+1]);
}

/*
 It will take the input array arr, the segment tree array seg_tree, the count
 array cnt, the segment index si, the starting index of the segment ss, the
 ending index of the segment se, the starting index of the query qi and the
 ending index of the query qe. It will return a vector of integers where the
 first integer is the minimum element and the second integer is the count of
 that minimum element in that particular query interval.
*/

vector<int> query(vector<int> &arr, vector<int> &seg_tree, 
    vector<int> &cnt, int si, int ss, int se, int qs, int qe) {

  if(qs > se || qe < ss) {
      vector<int> res;
      res.push_back(INT_MAX);
      res.push_back(0);
      return res;
  }
  if(ss >= qs && se <= qe) {
      vector<int> res;
      res.push_back(seg_tree[si]);
      res.push_back(cnt[si]);
      return res;
  }

  int mid = (ss + se) / 2;
  vector<int> p1 = query(arr, seg_tree, cnt, 2*si, ss, mid, qs, qe);
  vector<int> p2 = query(arr, seg_tree, cnt, 2*si+1, mid+1, se, qs, qe);
  
  if(p1[0] == p2[0]) {
      vector<int> res;
      res.push_back(p1[0]);
      res.push_back(p1[1] + p2[1]);
      return res;
  }
  else if(p1[0] < p2[0]) {
      return p1;
  }
  else{
      return p2;
  }
}


vector<string> minimumGame(int n, int q, vector<int> &arr, vector<vector<int>> &intervals){
    
    /* Declare two integer vectors, seg_tree and cnt, to store the
    minimum element of a particular interval and the count of that element in
    that interval.*/
    vector<int> seg_tree(4*n + 5), cnt(4*n + 5);

    // Fill the vectors using the build function.
    build(arr,seg_tree, cnt, 1, 0, n-1);

    // Declare a vector of string 'ans' to store the answer of each round.
    vector<string> ans;

    // Iterate over the rounds.
    for(int i = 0; i < q; i++) {

        /*
         Declare four variables- 
         'alexStart' - Starting index for Alex. 
         'alexEnd' -Ending index for Alex. 
         'bobStart' - Starting index for Bob.
         'bobEnd' - Ending index forBob.
         */
        int alexStart = intervals[i][0];
        int alexEnd = intervals[i][1];
        int bobStart = intervals[i][2];
        int bobEnd = intervals[i][3];

        /*Find the minimum element and the count of that of the
        interval of Alex using the query function and store it in Alex.*/

        vector<int> Alex = query(arr, seg_tree, cnt, 1, 0, n-1, alexStart, alexEnd);
        
        /* Find the minimum element and the count of that of the interval of Bob
        using the query function and store it in Bob. */
        
        vector<int> Bob = query(arr, seg_tree, cnt, 1, 0, n-1, bobStart, bobEnd);

        // Extract the count from arrays 'Alex' and 'Bob' to 'alexCount' and 'bobCount'.
        int alexCount = Alex[1];
        int bobCount = Bob[1];

        // If 'alexCount' is more, then 'Alex' is the winner. 
        if(alexCount > bobCount){
            ans.push_back("Alex");
        } 
        // Else if 'bobCount' is more, then 'Bob' is the winner.
        else if(bobCount > alexCount){
            ans.push_back("Bob");
        }
        // Else the result is 'Draw'.
        else{
            ans.push_back("Draw");
        }
    }
    // Return the array 'ans' as the output.
    return ans;

}