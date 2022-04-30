const  testimonialsContainer = document.querySelector('.testimonial-container')
const  testimonial = document.querySelector('.testimonial')
const  userImage = document.querySelector('.user-image')
const  username = document.querySelector('.username')
const  role = document.querySelector('.role')

const testimonials = [
    {
      name: 'Teresa Smith',
      position: 'Marketing',
      photo: 'https://images.unsplash.com/photo-1438761681033-6461ffad8d80?ixid=MXwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHw%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=1500&q=80',
      text:
        "Lorem ipsum dolor sit amet consectetur adipisicing elit. Provident ipsam autem illo debitis quam? Reiciendis deserunt maiores provident esse cum libero quod? Libero maxime veritatis, nesciunt saepe quasi hic iure!Esse hic qui neque facere numquam, vel porro omnis nam velit nisi nemo quos deserunt ratione a modi autem veniam temporibus quis. Atque non earum minima quo.",
    },
    {
      name: 'June Cha',
      position: 'Software Engineer',
      photo: 'https://images.unsplash.com/photo-1534751516642-a1af1ef26a56?ixid=MXwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHw%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=335&q=80',
      text:
        "Lorem, ipsum dolor sit amet consectetur adipisicing elit. Harum consectetur sequi pariatur labore, possimus doloremque. Voluptates ipsum vero reiciendis obcaecati cupiditate, eveniet rerum modi odio officia sed deleniti labore voluptatibus!Hic nesciunt officia minima reprehenderit harum quod temporibus. Molestiae, debitis adipisci obcaecati quasi neque.",
    },
    {
      name: 'Sara Santos',
      position: 'Web Designer',
      photo: 'https://images.unsplash.com/photo-1524159730786-4e74a1b78d7d?ixlib=rb-1.2.1&ixid=MXwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHw%3D&auto=format&fit=crop&w=750&q=80',
      text:
      "Lorem ipsum dolor sit amet consectetur adipisicing elit. Temporibus accusamus ratione laborum quae voluptatibus debitis soluta quo cupiditate nihil natus, amet nostrum voluptatem earum modi quidem facilis totam reiciendis neque! Tempora maxime quos, impedit aut, distinctio dignissimos sed aspernatur earum quia dolor minus. Iste maiores.",
    },
    {
      name: 'Renan Duarte',
      position: 'Receptionist',
      photo: 'https://images.unsplash.com/photo-1507003211169-0a1dd7228f2d?ixlib=rb-1.2.1&ixid=MXwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHw%3D&auto=format&fit=crop&w=334&q=80',
      text:
        "Lorem ipsum dolor sit amet consectetur adipisicing elit. Temporibus accusamus similique maiores Saepe praesentium illum!",
    },
    {
      name: 'Jonathan Nunfiez',
      position: 'Teacher',
      photo: 'https://images.unsplash.com/photo-1563122870-6b0b48a0af09?ixlib=rb-1.2.1&ixid=MXwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHw%3D&auto=format&fit=crop&w=334&q=80',
      text:
        "There are many variations similique maiores Saepe of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even.",
    },
    {
      name: 'Sasha Jones',
      position: 'Accountant',
      photo: 'https://images.unsplash.com/photo-1508214751196-bcfd4ca60f91?ixid=MXwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHw%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=750&q=80',
      text:
      "Ste necessitatibus voluptatibus similique maiores Saepe praesentium illum voluptates facilis nihil consectetur error nulla recusandae maiores suscipit, pariatur excepturi debitis laudantium incidunt necessitatibus asperiores, iste vel cum, veritatis nesciunt repudiandae rem corporis. Optio, voluptatum unde!",
    },
    {
      name: 'Rita Wilson',
      position: 'Doctor',
      photo: 'https://images.unsplash.com/photo-1545133875-55b651cbf4aa?ixlib=rb-1.2.1&ixid=MXwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHw%3D&auto=format&fit=crop&w=375&q=80',
      text:
      "At vero eos et accusamus et iusto odio dignissimos ducimus qui blanditiis praesentium voluptatum deleniti atque corrupti quos dolores et quas molestias excepturi sint."
    },
  ]

  let idx = 1

  function updadeTestimonial(){
      const {name, position, photo, text } = testimonials[idx]

      testimonial.innerHTML = text
      userImage.src = photo
      username.innerHTML = name
      role.innerHTML = position

      idx++

      if(idx > testimonials.length - 1){
          idx = 0
      }
  }

setInterval(updadeTestimonial, 10000)