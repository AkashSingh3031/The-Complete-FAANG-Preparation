function updateText() {
  let val = document.getElementById("text-input").value;
  document.getElementById("text-output").innerText = val;
}

function makeBold(elem) {
  elem.classList.toggle("active");
  document.getElementById("text-output").classList.toggle("bold");
}

function makeItalic(elem) {
  elem.classList.toggle("active");
  document.getElementById("text-output").classList.toggle("italic");
}

function makeUnderline(elem) {
  elem.classList.toggle("active");
  let formattedText = document.getElementById("text-output");
  if (formattedText.classList.contains("underline")) {
    formattedText.classList.remove("underline");
  } else {
    formattedText.classList.add("underline");
  }
}

function alignText(elem, alignType) {
  document.getElementById("text-output").style.textAlign = alignType;
  let buttonsList = document.getElementsByClassName("align");
  for (let i = 0; i < buttonsList.length; i++) {
    buttonsList[i].classList.remove("active");
  }
  elem.classList.add("active");
}
