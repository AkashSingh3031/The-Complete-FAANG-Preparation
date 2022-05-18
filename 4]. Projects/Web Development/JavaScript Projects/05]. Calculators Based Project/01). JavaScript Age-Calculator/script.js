const months = [31,28,31,30,31,30,31,31,30,31,30,31];

function ageCalc(){
    let today = new Date();
    let inputDate = new Date(document.getElementById("input-date").value);
    let ageMonth,ageDays,ageYear;
    let birthDetails = {
        date:inputDate.getDate(),
        month:inputDate.getMonth()+1,
        year:inputDate.getFullYear()
    }
    let currYear = today.getFullYear();
    let currMonth = today.getMonth()+1;
    let currDate = today.getDate();

    leapCheck(currYear);

    if( birthDetails.year > currYear ||
        (birthDetails.month > currMonth && birthDetails.year == currYear) || 
        (birthDetails.date > currDate && birthDetails.month == currMonth && birthDetails.year == currYear)
    ){
        alert("Not Born Yet!!");
        displayResult("-","-","-");
        return;
    }

    ageYear = currYear - birthDetails.year;

    if(currMonth >= birthDetails.month){
        ageMonth = currMonth - birthDetails.month;
    }
    else{
        ageYear--;
        ageMonth = 12 + currMonth - birthDetails.month;
    }

    if(currDate >= birthDetails.date){
        ageDays = currDate - birthDetails.date;
    }
    else{
        ageMonth--;
        let days = months[currMonth - 2];
        ageDays = days + currDate - birthDetails.date;
        if(ageMonth < 0){
            ageMonth = 11;
            ageYear--;
        }
    }
    displayResult(ageDays,ageMonth,ageYear);

    // current date is birthdate
    if((birthDetails.month == currMonth &&
      birthDetails.date == currDate)){
        document.getElementById('wishmsg').style.display = 'block';
    } else {
      document.getElementById('wishmsg').style.display = 'none';
    }
}

function displayResult(bDate,bMonth,bYear){
    document.getElementById("years").textContent = bYear;
    document.getElementById("months").textContent = bMonth;
    document.getElementById("days").textContent = bDate;
}

// leap year checker
function leapCheck(year){
    if(year % 4 == 0 || (year % 100 == 0 && year % 400 == 0)){
        months[1] = 29;
    }
    else{
        months[1] = 28;
    }
}