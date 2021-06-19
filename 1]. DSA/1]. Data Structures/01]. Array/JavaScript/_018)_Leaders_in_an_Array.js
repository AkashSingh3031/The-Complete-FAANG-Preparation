//if current element/person value is greater than front element/person then current element is considered as a leader
function leaders(arr) {
    let n = arr.length;
    let cur_leader = arr[n - 1];
    let leaders = [arr[n - 1]];
    for (let i = n - 2; i >= 0; i--) {
        if (cur_leader < arr[i]) {
            cur_leader = arr[i];
            leaders.push(cur_leader);
        }
    }
    return leaders;
}

let arr = [7, 10, 4, 3, 6, 5, 2];
console.log(`Leaders = ${leaders(arr)}`);
