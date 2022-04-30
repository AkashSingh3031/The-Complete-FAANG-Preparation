const cel = document.getElementById('cel');
const fah = document.getElementById('fah');
const kel = document.getElementById('kel');

cel.addEventListener('input', function() {
    if(this.value != ""){
    let c = this.value;
    let f = (c * 9/5) + 32;
    let k = +c + 273.15;
    if(!Number.isInteger(f)) {
        f = f.toFixed(4);
    }
    if(!Number.isInteger(k)) {
        k = k.toFixed(4);
    }
    fah.value = f;
    kel.value = k;
    } else {
        fah.value = "";
        kel.value = "";
    }
});

fah.addEventListener('input', function() {
    if(this.value != ""){
    let f = this.value;
    let c = (f - 32) * 5/9;
    let k = c + 273.15;
    if(!Number.isInteger(c)) {
        c = c.toFixed(4);
    }
    if(!Number.isInteger(k)) {
        k = k.toFixed(4);
    }
    cel.value = c;
    kel.value = k;
    } else {
        cel.value = "";
        kel.value = "";
    }
});

kel.addEventListener('input', function() {
    if(this.value != ""){
    let k = this.value;
    let c = k - 273.15;
    let f = (k - 273.15) * 9/5 + 32;
    if(!Number.isInteger(c)) {
        c = c.toFixed(4);
    }
    if(!Number.isInteger(f)) {
        f = f.toFixed(4);
    }
    cel.value = c;
    fah.value = f;
    } else {
        cel.value = "";
        fah.value = "";
    }
});