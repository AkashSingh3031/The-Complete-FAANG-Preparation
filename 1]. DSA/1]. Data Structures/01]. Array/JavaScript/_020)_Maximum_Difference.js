function maxDiff(arr) {
    let n = arr.length;
    let res = arr[1] - arr[0],
        minVal = arr[0];
    for (let i = 1; i < n; i++) {
        res = Math.max(res, arr[i] - minVal);
        minVal = Math.min(minVal, arr[i]);
    }
    return res;
}

let arr = [2, 3, 10, 6, 4, 8, 1];
console.log(`Maximum Difference = ${maxDiff(arr)}`);
