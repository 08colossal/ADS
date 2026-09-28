function acao_botao(n){
    let b = document.querySelector("#b"+n);
    if(b.style.backgroundColor === "" || b.style.backgroundColor === "red"){
        b.style.backgroundColor = "blue";
    }else{
        b.style.backgroundColor = "red";
    }
}
