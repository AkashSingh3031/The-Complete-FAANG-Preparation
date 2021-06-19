function getLargest(arr) {
    for (let i = 0; i < arr.length; i++) {
        let flag = true;
        for (let j = 1; j < arr.length; j++) {
            if (arr[j] > arr[i]) {
                flag = false;
                break;
            }
        }
        if (flag == true) return i;
    }
    return -1;
}

let arr = [10, 5, 20, 8];
let index = getLargest(arr);
console.log(`Index = ${index}
Largest Number in [${arr}] is ${arr[index]}`);
