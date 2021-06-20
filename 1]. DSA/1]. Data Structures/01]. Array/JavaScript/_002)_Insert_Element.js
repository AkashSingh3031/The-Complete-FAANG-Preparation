function insert(arr, position, element) {
    // shift all elements one
    // place to the back until index
    for (i = arr.length; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    // insert the element at the index
    arr[position] = element;
}

let arr = [1, 2, 3, 5];
console.log(`before insertion -> ${arr}`);
insert(arr, 1, -4);
console.log(`After insertion -> ${arr}`);
