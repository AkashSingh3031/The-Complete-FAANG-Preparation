// baseUrl:"api.openweathermap.org/data/2.5/weather?q={city name}&appid={API key}



const weatherApi={
    key:"98c874b438284f7137222e672eb56639",
    baseUrl:"https://api.openweathermap.org/data/2.5/weather"

}

const searchInputBox=document.getElementById('input-box');
//anonymus -->event listener on keypress
searchInputBox.addEventListener('keypress',(event)=>{
    if(event.keyCode ==13){
console.log(searchInputBox.value);
getWeatherReport(searchInputBox.value);
    }
}); 



// get weather report

function getWeatherReport(city){
    fetch(`${weatherApi.baseUrl}?q=${city}&appid=${weatherApi.key}&units=metric`)
     .then(weather=>{
         return weather.json();
     }).then(showWeatherReport);
}


//show weather report
function showWeatherReport(weather){
console.log(weather);


let city=document.getElementById('city');
city.innerText=`${weather.name},${weather.sys.country}`;

let temp1=document.getElementById('temp');
temp1.innerHTML=`${Math.round(weather.main.temp)}&deg;C`;

let minmax=document.getElementById('min-max');
minmax.innerHTML=`${Math.floor(weather.main.temp_min)}&deg;C (min)/${Math.ceil(weather.main.temp_max)}&deg;C (max)`;

let type=document.getElementById('weather');
type.innerText=`${weather.weather[0].main}`;


let date=document.getElementById('date');
let todaydate=new Date();
date.innerText=dateManage(todaydate);


if(type.textContent=='Clear'){
    document.body.style.backgroundImage="url(1049442.jpg)";
}
else if(type.textContent=='Clouds'){
    document.body.style.backgroundImage="url(download.jpg)";

}
else if(type.textContent=='Rain'){
    document.body.style.backgroundImage="url(rainy-destinations.jpg)";

}
else if(type.textContent=='Thunderstorm'){
    document.body.style.backgroundImage="url(Delhi-lightining-2.jpg)";

}
else if(type.textContent=='Haze'){
    document.body.style.backgroundImage="url(images.jpg)";

}



}




//Date manage
function dateManage(dateArg){
    let days=["Sunday","Monday","Tuesday","Thursday","Wednesday","Thursday","Friday","Saturday"];
    let months=["January","February","March","April","May","June","July","August","September","October","November","December"];

    let year=dateArg.getFullYear();
    let month=months[dateArg.getMonth()];
    let date=dateArg.getDate();
    let day=days[dateArg.getDay()];

    return `${date} ${month} ${day},${year}`;


}
