const calc = () =>{
    let phy = document.getElementById('phy').value;
    let chem = document.getElementById('chem').value;
    let maths = document.getElementById('math').value;
    let cs = document.getElementById('cs').value;
    let eng = document.getElementById('eng').value;
    let grade = "";
  
    let totalGrade = parseFloat(phy) + parseFloat(chem) + parseFloat(maths) + parseFloat(cs) + parseFloat(eng);
    let percent = (totalGrade/500) * 100;
  
    if(percent <= 100  && percent >= 80){
      grade = 'A';
    }else if(percent <= 79  && percent >= 60){
       grade = 'B';
    }else if(percent <= 59  && percent >= 40){
       grade = 'C';
    }else{
       grade = 'F';
    }
  
    if(percent >= 39.5){
      document.getElementById('result').innerHTML = `Total Marks Out of 500 :  ${totalGrade} <br/> Percentage : ${percent}% <br/> Grade : ${grade} (You are Pass) `
    }
    else{
      document.getElementById('result').innerHTML = `Total Marks Out of 500 :  ${totalGrade} <br/> Percentage : ${percent}% <br/> Grade : ${grade} (You are Fail) `
    }
  }