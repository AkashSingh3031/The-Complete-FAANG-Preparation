/*
    Time Complexity : O( N * logN )
    Space Complexity : O( N * logN )
    
    where 'N' is the size of array 'ARR'. 
*/

vector < int > orzValue(int n, vector < int > arr) {

  // Empty Hashsets 'ORZ' and 'LAST' and empty array 'ANS'.
  unordered_set < int > last, orz;
  vector < int > ans;

  for (int i = 0; i < n; i++) {

    // Empty hashset 'CURR' that stores different 'ORZ' values ending at 'i'.
    unordered_set < int > curr;
    for (int j: last) {
      curr.insert(j | arr[i]);
      orz.insert(j | arr[i]);
    }

    // Adding current element, as it also ends at 'i'.
    curr.insert(arr[i]);
    orz.insert(arr[i]);

    // Copying 'CURR' to 'LAST'.

    last = curr;
  }

  // Inserting values of 'ORZ' into 'ANS'.
  for (int i: orz) {
    ans.push_back(i);
  }

  // Sorting 'ANS' array.
  sort(ans.begin(), ans.end());

  // Returning 'ANS'.
  return ans;
}