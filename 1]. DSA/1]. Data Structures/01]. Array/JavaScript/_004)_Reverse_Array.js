function reverse(arr) {
    let low = 0;
    let high = arr.length - 1;
    while (low < high) {
        let temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;

        low++;
        high--;
    }
}

let arr = [1, 2, 3, 4, 5];

console.log(`Befor Reverse -> ${arr}`);
reverse(arr);
console.log(`After Reverse -> ${arr}`);
