function moveToEnd(arr) {
    let count = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] != 0) {
            [arr[i], arr[count]] = [arr[count], arr[i]];
            /*
            //swaping the values
            let temp = arr[i];
            arr[i] = arr[count];
            arr[count] = temp;
*/
            count++;
        }
    }
}

let arr = [0, 8, 5, 0, 0, 10, 0, 20];
console.log(`Before Move Zeros: ${arr}`);

moveToEnd(arr);

console.log(`After Move Zeros: ${arr}`);
