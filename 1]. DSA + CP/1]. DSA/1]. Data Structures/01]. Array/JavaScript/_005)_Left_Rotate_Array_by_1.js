function lRotateOne(arr, n) {
    let temp = arr[0];
    for (let i = 1; i < n; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

let arr = [1, 2, 3, 4, 5];
let n = 5;
console.log(`Before Left Rotation -> ${arr}`);
lRotateOne(arr, n);
console.log(`After '1' Left Rotation -> ${arr}`);
