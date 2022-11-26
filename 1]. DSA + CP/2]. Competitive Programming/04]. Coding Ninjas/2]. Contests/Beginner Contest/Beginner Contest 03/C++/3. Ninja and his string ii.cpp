/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where 'N' is the size of string 'S'.
*/

int canPalindrome(int n, string s) {

   // Hashmap will store frequency of all characters in string 'S'.
   unordered_map < char, int > frq;

   for (char c: s) {
      frq[c]++;
   }

   // 'ODD_COUNT' stores count of total characters in string 'S' with odd frequency.
   int odd_count = 0;

   for (auto a: frq) {
      if (a.second % 2) {
         odd_count++;
      }
   }

   // If count is less than 1, we will return '1' else '0'.
   if (odd_count <= 1) {
      return 1;
   }

   return 0;
}