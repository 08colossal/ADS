// 1. Crie um jogo da velha (esquema de botôes)
// 2. Se a pessoa clicar vai colorir para vermelho ou azul
// 3. Se tiver vermelho, troca para azul
// 4. Se tiver azul, troca para vermelho

function acelerar(){
    let b = document.querySelector(".botao");
    b.style.backgroundColor = "red";
    let v = document.querySelector(".video");
    v.playbackRate = 2;
}

function desacelerar(){
    let v = document.querySelector(".video");
    v.playbackRate = 0.20;
}