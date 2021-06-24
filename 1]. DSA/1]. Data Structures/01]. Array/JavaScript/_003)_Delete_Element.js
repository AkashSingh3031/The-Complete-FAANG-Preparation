function deleteElement(arr, element) {
    if (arr.indexOf(element) === -1) {
        return 'no such element exist in array';
    }
    let newArr = [];
    for (let i = 0; i < arr.length; i++) {
        if (i !== arr.indexOf(element)) {
            newArr.push(arr[i]);
        }
    }
    return newArr;
}

let arr = [1, 2, 3, 5];

console.log(arr);
console.log(`before deletion -> ${arr}`);
let deleteElemArr = deleteElement(arr, 25);
console.log(`after deletion -> ${deleteElemArr}`);
