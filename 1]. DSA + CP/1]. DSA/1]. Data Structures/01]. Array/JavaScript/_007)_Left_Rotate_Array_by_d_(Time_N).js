function leftRotate(arr, d, n) {
    let temp = new Array(d);
    for (let i = 0; i < d; i++) {
        temp[i] = arr[i];
    }
    for (let i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }
    for (let i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
}

let arr = [1, 2, 3, 4, 5];
let n = 5;
let d = 2;
console.log(`Before Left Rotation->${arr}`);
leftRotate(arr, d, n);
console.log(`After '2' Left Rotation->${arr}`);
