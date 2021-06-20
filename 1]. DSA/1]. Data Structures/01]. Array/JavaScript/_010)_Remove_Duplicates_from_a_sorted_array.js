function remDups(arr) {
    let res = 1;
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] != arr[res - 1]) {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

let arr = [0, 20, 20, 30, 30, 30, 30];
console.log(`Before Removal Duplicates-> ${arr}`);

let Res = remDups(arr);
console.log(`After Removal Duplicates-> ${arr.splice(0, Res)}`);
