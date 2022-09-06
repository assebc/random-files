const wrapper = document.querySelector(".wrapper"),
    searchInput = wrapper.querySelector("input"),
    volume = wrapper.querySelector(".word i"),
    infoText = wrapper.querySelector(".info_text"),
    synonyms = wrapper.querySelector(".synonyms .list"),
    removeIcon = wrapper.querySelector(".search span");
    let audio;

function data(result, word){
    if(result.title){
        infoText.innerHTML="Can't find meaning of"
    }
}