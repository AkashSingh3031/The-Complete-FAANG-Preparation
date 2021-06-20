function moveToEnd(arr) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] == 0) {
            for (let j = i + 1; j < arr.length; j++) {
                if (arr[j] != 0) {
                    [arr[i], arr[j]] = [arr[j], arr[i]]; //swap the values
                    break;
                }
            }
        }
    }
}
let arr = [0, 8, 5, 0, 0, 10, 0, 20];
console.log(`Before Move Zeros: ${arr}`);

moveToEnd(arr);

console.log(`After Move Zeros: ${arr}`);
