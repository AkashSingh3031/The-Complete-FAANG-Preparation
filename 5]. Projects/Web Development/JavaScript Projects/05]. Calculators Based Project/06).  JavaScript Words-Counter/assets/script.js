const textArea = document.getElementById('textArea');

textArea.addEventListener('input', function() {
    let text = this.value;
    document.getElementById('char').innerHTML = text.length
    text = text.trim();
    let words = text.split(" ");
    // console.log(words);
    let wordArr = words.filter(elm => elm != "");
    // console.log(wordArr);
    document.getElementById('word').innerHTML = wordArr.length;
});