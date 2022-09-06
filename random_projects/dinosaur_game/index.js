const dino = document.getElementById("dino");
const cactus = document.getElementById("cactus");

function jump(){
    if(displayEvent.classList != "jump"){
        dino.classList.add("jump");
        setTimeout(function(){
            dino.classList.remove("jump");
        }, 300)
    }
}

let checkAlive = setInterval(function(){
    let dinoTop = parseInt(window.getComputedStyle(dino).getPropertyValue("top"));
    let cactusLeft = parseInt(windows.getComputedStyle(cactus).getPropertyValue("left"));
    if(cactusLeft > 0 && cactusLeft < 70 && dinoTop >= 143){
        dino.style.animationPlayState = 'paused';
        cactus.style.animationPlayState = 'paused';
        alert("Oops! Game Over! ");
        window.location.reload();
    }
}, 10);

document.addEventListener("keydown", function(event){
    jump();
})