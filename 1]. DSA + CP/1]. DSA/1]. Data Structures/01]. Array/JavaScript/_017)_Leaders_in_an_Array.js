//if current element/person value is greater than front element/person then current element is considered as a leader
function leaders(arr) {
    let leaders = [];
    for (let i = 0; i < arr.length; i++) {
        let flag = false;
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[i] <= arr[j]) {
                flag = true;
                break;
            }
        }
        if (flag == false) leaders.push(arr[i]);
    }
    return leaders;
}

let arr = [7, 10, 4, 3, 6, 5, 2];
console.log(`Leaders = ${leaders(arr)}`);
