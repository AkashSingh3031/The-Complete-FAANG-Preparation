/*
If current element/person value is greater than front element/person 
then current element is considered as a leader
*/

List findLeaders(arr) {
  var n = arr.length;
  var currLeader = arr[n - 1];
  var leaders = [arr[n - 1]];

  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] > currLeader) {
      currLeader = arr[i];
      leaders.add(currLeader);
    }
  }
  return leaders;
}

void main() {
  var arr = [7, 10, 4, 3, 6, 5, 2];
  var leaders = findLeaders(arr);
  print('Leaders in the array are: $leaders');
}
