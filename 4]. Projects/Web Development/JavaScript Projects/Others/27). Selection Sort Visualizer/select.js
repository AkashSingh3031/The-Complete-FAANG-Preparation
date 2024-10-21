const input = document.getElementById('input-value');
const inputVisualizer = document.getElementById('input-visualizer');
const outputVisualizer = document.getElementById('output-visualizer');
let arr = [];

function handleAdd() {
  const value = input.value;
  const node = document.createElement('div');
  const textnode = document.createTextNode(value);
  node.appendChild(textnode);
  inputVisualizer.appendChild(node);
  arr.push(Number(value));
}

function handleReset() {
  inputVisualizer.innerHTML = '';
  outputVisualizer.innerHTML = '';
  arr = [];
}

function sleep(ms) {
  return new Promise((resolve) => setTimeout(resolve, ms));
}

async function handleSort() {
  outputVisualizer.innerHTML = '';
  for (let i = 0; i < arr.length - 1; i++) {
    let min = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    await sleep(1000);

    const div = document.createElement('div');
    for (let j = 0; j < arr.length; j++) {
      const node = document.createElement('span');
      const textnode = document.createTextNode(arr[j]);
      node.appendChild(textnode);
      if (j < i) node.style.backgroundColor = '#40c896';
      if (j === min || j === i) node.style.backgroundColor = '#e6852c';
      div.appendChild(node);
    }
    outputVisualizer.appendChild(div);

    if (min !== i) {
      let temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }

    await sleep(1000);

    const newdiv = document.createElement('div');
    for (let j = 0; j < arr.length; j++) {
      const node = document.createElement('span');
      const textnode = document.createTextNode(arr[j]);
      node.appendChild(textnode);
      if (j <= i || (i === arr.length - 2 && j === arr.length - 1))
        node.style.backgroundColor = '#40c896';
      newdiv.appendChild(node);
    }
    outputVisualizer.replaceChild(newdiv, div);
  }
}
