const numbers = document.querySelectorAll('.numbers');
const result = document.querySelector('.result');
const signs = document.querySelectorAll('.sign');
const equals = document.querySelector('.equals');
const clear = document.querySelector('.clear');
const negative = document.querySelector('.negative');
const mod = document.querySelector('.mod');

let firstValue = "";
let isFirstValue = false;
let secondValue = "";
let isSecondValue = false;
let sign = "";
let resultValue = 0;

for(let i = 0;i<numbers.length;i++){
    numbers[i].addEventListener('click', (e)=> {
        let atr = e.target.getAttribute('value');
        if(isFirstValue === false){
            getFirstValue(atr);
        }

        if(isSecondValue === false){
            getSecondValue(atr);
        }
    });
}

function getFirstValue(el){
    result.innerHTML = "";
    firstValue += el;
    result.innerHTML = firstValue;
    firstValue = +firstValue;
}

function getSecondValue(el){
    if(firstValue != "" && sign != ""){
        secondValue += el;
        result.innerHTML = secondValue;
        secondValue = +secondValue;
    }
}

function getSign(){
    for(let i = 0;signs.length;i++){
        signs[i].addEventListener('click', (e) => {
            sign = e.target.getAttribute('value');
            isFirstValue = true;
        })
    }
}

getSign();

equals.addEventListener('click', () => {
    result.innerHTML = "";
    switch(sign){
        case "+":
            resultValue = firstValue + secondValue; 
            break;

        case "-":
            resultValue = firstValue - secondValue; 
            break;
        case "x":
            resultValue = firstValue * secondValue;
            break;

        case "/":
            resultValue = firstValue / secondValue; 
            break;
    }
    
    result.innerHTML = resultValue;
    firstValue = resultValue;
    secondValue = "";
})

function checkResultLength(){
    resultValue = JSON.stringify(resultValue);

    if(resultValue.length >= 8){
        resultValue = JSON.parse(resultValue);
        result.innerHTML = resultValue.toFixed(5);
    }
}

negative.addEventListener('click', () =>{
    result.innerHTMl = "";
    if(firstValue != ""){
        resultValue = -firstValue;
        firstValue = resultValue;
    }

    if(firstValue != "" && secondValue != "" && sign != ""){
        resultValue = -resultValue;
    }

    result.innerHTML = resultValue;
})

mod.addEventListener('click', () => {
    result.innerHTML = "";
    if(firstValue != ""){
        resultValue = firstValue / 100;
        firstValue = resultValue;
    }
    
    if(firstValue != "" && secondValue != "" && sign != ""){
        resultValue = resultValue / 100;
    }

    result.innerHTML = resultValue;
    
})

clear.addEventListener('click', () => {
    result.inenrHTML = 0;

    firstValue = "";
    isFirstValue = false;
    secondValue = "";
    isSecondValue = false;
    sign = "";
    resultValue = 0;
})