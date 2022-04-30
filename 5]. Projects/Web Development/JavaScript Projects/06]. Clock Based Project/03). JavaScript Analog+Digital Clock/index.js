setInterval(() => {
    d = new Date();
    htime = d.getHours();
    mtime = d.getMinutes();
    stime = d.getSeconds();
    hrotation = 30*htime + mtime/2;
    mrotation = 6*mtime;
    srotation = 6*stime;

    hr.style.transform = `rotate(${hrotation}deg)`;
    mn.style.transform = `rotate(${mrotation}deg)`;
    sc.style.transform = `rotate(${srotation}deg)`;
}, 1000);