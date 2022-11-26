/*
    Time Complexity : O(N)
    Space Complexity : O(1)
    where 'N' is the size of 'ARR'.
*/

int strongestTeam(int n, vector < int > & arr) {

   // Two variables which will store maximum and second maximum.
   int maximum = 0, second_maximum = 0;
   for (int i = 0; i < n; i++) {
      // If my current power exceed or equals my current maximum.
      if (arr[i] >= maximum) {
         // I will replace second_maximum with current maximum, and maximum with current power.
         second_maximum = maximum;
         maximum = arr[i];
      } else {
         // Other wise store maximum of second_maximum and power[i] in second_maximum.
         second_maximum = max(second_maximum, arr[i]);
      }
   }
   // Returning team power , which is sum of maximum and second maximum.
   return maximum + second_maximum;
}