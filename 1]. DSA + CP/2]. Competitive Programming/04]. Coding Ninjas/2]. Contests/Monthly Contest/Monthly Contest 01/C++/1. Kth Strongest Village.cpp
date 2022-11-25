/*
    Time Complexity : O( N * logN )
    Space Complexity : O( N )
    
    where 'N' is the size of array 'ARR'. 
*/

int kthKingdom(int n, int k, vector < int > arr) {
   
   // An empty array of pairs, will contain values and index.
   vector < pair <int,int> > values;

   // Pushing back values and storing index with them.
   for(int i = 0; i < n ; i++ ){
         values.push_back( make_pair(arr[i] , i) );
   }

   // Sorting values on the basis of first value in descending order.
   sort(values.begin() , values.end() , greater < pair <int,int> >() );

   // Returning index value of 'Kth' largest Hokage.
   return values[k-1].second;
}
