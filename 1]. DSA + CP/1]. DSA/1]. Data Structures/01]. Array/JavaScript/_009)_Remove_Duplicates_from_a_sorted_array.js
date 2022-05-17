function remDups(arr) {
    let n = arr.length + 1;
    let temp = [];
    for (let i = 0; i < n; i++) {
        if (arr[i] != arr[i + 1]) {
            temp.push(arr[i]);
        }
    }
    return temp;
}

let arr = [0, 20, 20, 30, 30, 30, 30];
console.log(`Before Removal Duplicates-> ${arr}`);

let Res = remDups(arr);
console.log(`After Removal Duplicates-> ${Res}`);
