/*
    Time Complexity : O( N * logN )
    Space Complexity : O( N )
    
    where 'N' is the size of array 'ARR'. 
*/

int samePlace(int n, vector < int > arr) {

  // Array of pairs , value index stores value and index of values.
  vector < pair < int, int > > value_index;

  for (int i = 0; i < n; i++) {
    value_index.push_back(make_pair(arr[i], i));
  }

  // Sorting on the basis of first value.
  sort(value_index.begin(), value_index.end());

  // Variable 'ANS' with initial value '0'.
  int ans = 0;

  for (int i = 0; i < n; i++) {

    // incrementing 'ANS' when index is same after sorting the 'VALUE_INDEX'.
    if (value_index[i].second == i) {
      ans++;
    }
  }

  return ans;
}