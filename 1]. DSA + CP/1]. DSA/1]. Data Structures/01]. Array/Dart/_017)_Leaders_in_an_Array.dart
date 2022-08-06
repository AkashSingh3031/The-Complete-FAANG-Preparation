/*
If current element/person value is greater than front element/person 
then current element is considered as a leader
*/

List findLeaders(arr) {
  List leaders = [];
  for (int i = 0; i < arr.length; i++) {
    var flag = false;
    for (var j = i + 1; j < arr.length; j++) {
      if (arr[i] <= arr[j]) {
        flag = true;
        break;
      }
    }
    if (flag == false) {
      leaders.add(arr[i]);
    }
  }
  return leaders;
}

void main() {
  var arr = [7, 10, 4, 3, 6, 5, 2];
  var leaders = findLeaders(arr);
  print('Leaders in the array are: $leaders');
}
