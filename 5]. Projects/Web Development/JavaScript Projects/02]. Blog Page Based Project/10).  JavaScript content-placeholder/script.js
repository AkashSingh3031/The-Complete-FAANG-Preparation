const header = document.getElementById('header')
const title = document.getElementById('title')
const excerpt = document.getElementById('excerpt')
const profile_img = document.getElementById('profile_img')
const name = document.getElementById('name')
const date = document.getElementById('date')

const animated_bgs = document.querySelectorAll('.animated-bg')
const animated_bg_texts = document.querySelectorAll('.animated-bg-text')

setTimeout(getData, 2300)

function getData() {
    header.innerHTML = '<img src="https://images.unsplash.com/photo-1550660473-8d71a9ac0e76?ixlib=rb-1.2.1&ixid=MXwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHw%3D&auto=format&fit=crop&w=625&q=80" alt="">'
    title.innerHTML = 'Front-end Developer Student'
    excerpt.innerHTML = 'Systems Analysis and Development - Senac. HTML, CSS and JavaScript'
    profile_img.innerHTML = '<img src="author.jpeg" alt="">'
    name.innerHTML = 'Júlia Mendes'
    date.innerHTML = 'Jan 19, 2021'

    animated_bgs.forEach(bg => bg.classList.remove('animated-bg'))
    animated_bg_texts.forEach(bg => bg.classList.remove('animated-bg-text'))
}