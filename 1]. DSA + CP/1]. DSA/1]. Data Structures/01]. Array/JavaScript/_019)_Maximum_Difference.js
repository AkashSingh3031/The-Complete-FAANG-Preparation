function maxDiff(arr) {
    let n = arr.length;
    let res = arr[1] - arr[0];
    for (let i = 0; i < n; i++)
        for (let j = i + 1; j < n; j++) res = Math.max(res, arr[j] - arr[i]);
    return res;
}

let arr = [2, 3, 10, 6, 4, 8, 1];
console.log(`Maximum Difference = ${maxDiff(arr)}`);
