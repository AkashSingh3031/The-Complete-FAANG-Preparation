/*
Examples-1:
    Array: [1, 2, 3, 2, 1]
    Number of Identical Twins: 2

  Explanation:
    Identical Twins: [[1, 1], [2, 2]]
    Indexes: (0, 4), (1, 3)


Examples-2:
    Array: [1, 2, 2, 3, 2, 1]
    Number of Identical Twins: 4

  Explanation:
    Identical Twins: [[1, 1], [2, 2], [2, 2], [2, 2]]
    Indexes: (0, 5), (1, 2), (1, 4), (2, 4)


Examples-3:
    Array: [1, 1, 1, 1]
    Number of Identical Twins: 6

  Explanation:
    Identical Twins: [[1, 1], [1, 1], [1, 1], [1, 1], [1, 1], [1, 1]]
    Indexes: (0, 1), (0, 2), (0, 3), (1, 2), (1, 3), (2, 3)
*/

int getIdenticalTwinsCount(vector<int> &arr) {
    // add your logic here
	unordered_map<int, int> frequency;
   for (auto x: arr) {
       frequency[x]++;
   }
   int identicalTwinCount = 0;
   for (auto x: frequency) {
       identicalTwinCount += (x.second * (x.second - 1) / 2);
   }
   return identicalTwinCount;
}