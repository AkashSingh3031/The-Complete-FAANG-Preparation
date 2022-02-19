'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

var getMaxLessThanK = function(n, k){
    let max_value = 0;
    for ( var i = 1 ;i < n ;i++){
        for (var j = i+1 ; j < n+1; j++){
            if ( Number(i & j) < k){  // This line
                if(Number(i & j) > max_value){ // And this line
                    max_value = i & j;
                }
            }
        }
    }
    return max_value;
}


function main() {
    const q = +(readLine());
    
    for (let i = 0; i < q; i++) {
        const [n, k] = readLine().split(' ').map(Number);
        
        console.log(getMaxLessThanK(n, k));
    }
}