var gameBoardSize = 40;
var gamePoints = 0;
var gameSpeed = 100;

$(document).ready$(function(){
    console.log("Ready Player One!");
    createBoard();
    $(".btn").click(function(){
        startGame();
    });
});

var Snake = {
    position: [[20,20], [20,19], [20,18]],
    size: 3,
    direction: "r",
    alive: true
}

var Food = {
    position: [],
    present: false
}

function createBoard(){
    $("#gameBoard").empty();
    var size = gameBoardSize;

    for(i = 0; i<size;i++){
        $("#gameBoard").append('<div class="row"></div>');
        for(j = 0; j<size; j++){
            $(".row:last-child").append('<div class="pixel"></div>');
        }
    }
}

function moveSnake(){
    var head = Snake.position[0];

    switch(Snake.direction){
        case 'r':
            head[1] +=1;
            break;
        case 'l':
            head[1] -=1;
            break;
        case 'u':
            head[0] -=1;
            break;
        case 'd':
            head[0] +=1;
            break;
    }

    if(alive(head)){
        $(".row:nth-child(" + head[0] + ")> .pixel:nth-child(" + head[1] + ")").addClass("snakePixel");

        for(var i = 0; i< Snake.size;i++){
            $(".row:nth-child(" + Snake.position[i][0] + ")> .pixel:nth-child(" + Snake.position[i][1] + ")").addClass("snakePixel");
        }

        if(head.every(function(e,i){
            return e === Food.position[i];
        })){
            Snake.size++;
            Food.present = false;
        }
    }

}
