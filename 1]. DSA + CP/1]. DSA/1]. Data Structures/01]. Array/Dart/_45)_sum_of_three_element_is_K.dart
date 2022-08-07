/* 
An array of n elements, find three elements in the array, 
such that, their sum is equal to the given element K of that array.
*/

bool findTriplet(List<int> arr, int sum) {
  int l, r, m; // for left ,right and middle
  arr.sort();
  for (int i = 0; i < arr.length - 2; i++) {
    l = 0;
    r = arr.length - 1;
    m = (l + r) ~/ 2;
    while (l < r) {
      if (arr[i] + arr[m] + arr[r] == sum) {
        print('${arr[i]} + ${arr[m]} + ${arr[r]} = $sum');
        return true;
      } else if (arr[i] + arr[m] + arr[r] < sum) {
        l++;
      } else {
        r--;
      }
    }
  }

  print('Triplet not found.');
  return false;
}

void main() {
  var arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  int sum = 14;
  findTriplet(arr, sum);
}
