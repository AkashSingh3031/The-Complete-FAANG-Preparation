// function to search for element in array
function search(arr, x) {
    for (let index = 0; index < arr.length; index++) {
        if (arr[index] === x) {
            return index;
        }
    }
    //if no such number exist in the array return -1
    return -1;
}

const arr = [20, 5, 7, 25];
console.log(`Searched index= ${search(arr, 5)}`);
