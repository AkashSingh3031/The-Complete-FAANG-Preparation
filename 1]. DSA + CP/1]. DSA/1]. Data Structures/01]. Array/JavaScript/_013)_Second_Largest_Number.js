function getLargest(arr) {
    let largest = 0;
    for (let i = 1; i < arr.length; i++) if (arr[i] > arr[largest]) largest = i;
    return largest;
}

function getSecondLargest(arr) {
    let largest = getLargest(arr);
    let res = -1;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] != arr[largest]) {
            if (res == -1) res = i;
            else if (arr[i] > arr[res]) res = i;
        }
    }
    return res;
}

let arr = [10, 5, 18, 20];
let index = getSecondLargest(arr);
console.log(`Index = ${index}
Second Largest Number in [${arr}] is ${arr[index]}`);
