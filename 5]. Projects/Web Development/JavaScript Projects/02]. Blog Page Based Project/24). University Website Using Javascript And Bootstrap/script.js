// selecting elememts from webpage

const trainers = document.querySelectorAll(".trainers .member h4");
const campusImg = document.querySelector(".campusImg img");

//box shadow effect on image 

campusImg.addEventListener('mouseover',function(){
    this.classList.add('campus');
})

campusImg.addEventListener('mouseout',function(){
    this.classList.remove('campus');
})

// trainers section animation effect

trainers.forEach(function(card)
{
    card.addEventListener("mouseover", function()
    {
        this.classList.add("shade");
    });
});

trainers.forEach(function(card)
{
    card.addEventListener("mouseout", function()
    {
        this.classList.remove("shade");
    });
});