function getLargest(arr) {
    let n = arr.length;
    let res = 0;
    for (let i = 1; i < n; i++) if (arr[i] > arr[res]) res = i;
    return res;
}

let arr = [10, 5, 20, 8];

let index = getLargest(arr);

console.log(`Index = ${index}
Largest Number in [${arr}] is ${arr[index]}`);

let largestNumber = arr.reduce((a, b) => {
    return Math.max(a, b);
});

console.log(`Largest Number in [${arr}] is ${largestNumber1}`);

let largestNumber1 = arr.sort((a, b) => {
    return b - a;
})[0];
console.log(`Largest Number in [${arr}] is ${largestNumber1}`);
