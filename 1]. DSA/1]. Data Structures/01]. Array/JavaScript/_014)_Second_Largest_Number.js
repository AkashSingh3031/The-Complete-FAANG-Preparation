function getSecondLargest(arr) {
    let res = -1,
        largest = 0;
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > arr[largest]) {
            res = largest;
            largest = i;
        } else if (arr[i] != arr[largest]) {
            if (res == -1 || arr[i] > arr[res]) res = i;
        }
    }
    return res;
}
let arr = [10, 5, 18, 20];
let index = getSecondLargest(arr);
console.log(`Index = ${index}
Second Largest Number in [${arr}] is ${arr[index]}`);
