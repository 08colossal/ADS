let jogador = 0;
let valor = "";
let X = 0;
let O = 0;
let contador = 0;

let b1 = document.querySelector("#botao1").innerText;
let b2 = document.querySelector("#botao2").innerText;
let b3 = document.querySelector("#botao3").innerText;
let b4 = document.querySelector("#botao4").innerText;
let b5 = document.querySelector("#botao5").innerText;
let b6 = document.querySelector("#botao6").innerText;
let b7 = document.querySelector("#botao7").innerText;
let b8 = document.querySelector("#botao8").innerText;
let b9 = document.querySelector("#botao9").innerText;

//* FUNÇÃO QUE VERIFICA SE HOUVE VENCEDOR

let verificarVencedor = () => {
    if(
        (b1 === b2 && b2 === b3 && b3 === b1 && b1 !== "" && b2 !== "" && b3 !== "") ||
        (b4 === b5 && b5 === b6 && b6 === b4 && b4 !== "" && b5 !== "" && b6 !== "") ||
        (b7 === b8 && b8 === b9 && b9 === b7 && b7 !== "" && b8 !== "" && b9 !== "") ||
        (b1 === b4 && b4 === b7 && b7 === b1 && b1 !== "" && b4 !== "" && b7 !== "") ||
        (b2 === b5 && b5 === b8 && b8 === b2 && b2 !== "" && b5 !== "" && b8 !== "") ||
        (b3 === b6 && b6 === b9 && b9 === b3 && b3 !== "" && b6 !== "" && b9 !== "") ||
        (b1 === b5 && b5 === b9 && b9 === b1 && b1 !== "" && b5 !== "" && b9 !== "") ||
        (b3 === b5 && b5 === b7 && b7 === b3 && b3 !== "" && b5 !== "" && b7 !== "")
    ){
        return String(jogador);
    }
};

//* FUNCAO QUE VERIFICA SE O QUADRO ESTÁ CHEIO

let verificarQuadroPreenchido = () =>{
    for(let i = 1; i <= 9; i++){
        if(document.querySelector('#botao' + i).innerText === ""){
            return false;
        }
    }
    return true;
};

//* FUNCAO QUE LIMPA O QUADRO

let limpar = () =>{
    if(verificarQuadroPreenchido()){
        for(let i = 1; i <= 9; i++){
            document.querySelector('#botao' + i).innerText = "";
        }
    }
};


//*  FUNCTION ACAO

function acao(n){
    
    let botao = document.querySelector('#botao' + n);    
    let placarX = document.querySelector("#X");
    let placarO = document.querySelector("#O");
    
    if(jogador === 0){
        jogador++;
        valor = "X";
    } else {
        jogador--;
        valor = "O";
    }

    
    
    console.log("Vencedor: " + verificarVencedor());
    let venceu = verificarVencedor();
    if(venceu === "1"){
        X++
        placarX.innerText = String(X);
        limpar();
        
    } else if(venceu === "0"){
        O++
        placarO.innerText = String(O);
        limpar();
    }


    if(botao.innerText === ""){
        botao.innerText = String(valor);
    }

    console.log("Jogador: " + jogador);
    console.log("Vencedor: " + verificarVencedor() + " X: " + X + " O: " + O);
    console.log("Verificar Quadro Preenchido:" + verificarQuadroPreenchido());
    console.log("------------");
}