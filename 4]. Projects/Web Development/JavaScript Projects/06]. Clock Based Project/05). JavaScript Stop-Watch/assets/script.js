const hrTxt = document.getElementById('hr');
const minTxt = document.getElementById('min');
const secTxt = document.getElementById('sec');
const countTxt = document.getElementById('count');

let hr = 0;
let min = 0;
let sec = 0;
let count = 0;
let timer = false;

const start = () => {
    timer = true;
    stopwatch();
}
const stop = () => {
    timer = false;
}
const reset = () => {
    timer = false;
    hr = 0;
    min = 0;
    sec = 0;
    count = 0;
    hrTxt.innerHTML = "00";
    minTxt.innerHTML = "00";
    secTxt.innerHTML = "00";
    countTxt.innerHTML = "00";
}

const stopwatch = () => {
    if(timer == true) {
        count += 1;

        if(count == 100) {
            sec += 1;
            count = 0;
        }
        if(sec == 60) {
            min += 1;
            sec = 0;
        }
        if(min == 60) {
            hr += 1;
            min = 0;
            sec = 0;
        }

        var hrStr = hr;
        var minStr = min;
        var secStr = sec;
        var countStr = count;
        if(hr < 10) {
            hrstr = "0" + hrStr;
        }
        if(min < 10) {
            minStr = "0" + minStr;
        }
        if(sec < 10) {
            secStr = "0" + secStr;
        }
        if(count < 10) {
            countStr = "0" + countStr;
        }
        hrTxt.innerHTML = hrstr;
        minTxt.innerHTML = minStr;
        secTxt.innerHTML = secStr;
        countTxt.innerHTML = countStr;

        setTimeout("stopwatch()",10);
    }
}