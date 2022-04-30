const container = document.getElementById('container')
const colors = ['#e74c3s', '#8e44ad', '#3498db', '#e67e22', '#2ecc71', '#ff007f', '#ffda00','#0000cd']

const SQUARES = 600;

for(let i = 0; i < SQUARES; i++) {
    const square = document.createElement('div')
    square.classList.add('square')

    square.addEventListener('mouseover', () => setColor(square))
    square.addEventListener('mouseout', () => removeColor(square))

    container.appendChild(square)
} 

function setColor(element) {
    const color = getRandomColor()
    element.style.background = color
    element.style.boxShadow = `0 0 2px ${color}, 0 0 10px ${color}`
}

function removeColor(element) {
    element.style.background = '#1d1d1d'
    element.style.boxShadow = ' 0 0 2px #000'

}

function getRandomColor(element) {
    return colors[Math.floor(Math.random() * colors.length)]
}