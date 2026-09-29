let jogador = 0;
let valor = "";
let X = 0;
let O = 0;
let contador = 0;

/*let b1 = document.querySelector("#botao1").innerText;  ->  mudei para a função array*/

//~ FUNÇÃO QUE LÊ O VALOR DE TODOS OS BOTÕES
function lerTabuleiro(){
    let t = []
    for (let i = 1; i <= 9; i++){
        t.push(document.querySelector('#botao'+i).innerText);
    }
    return t;
}

//~ FUNÇÃO QUE VERIFICA SE HOUVE VENCEDOR
function verificarVencedor(){
    let j = lerTabuleiro();

    let linhas = [ //indices do array 't' -> lerTabuleiro()
        [0,1,2], [3,4,5], [6,7,8], [0,3,6],
        [1,4,7], [2,5,8], [0,4,8], [2,4,6] 
    ];

    for(let linha of linhas){
        let [a,b,c] = linha;
        if(j[a] !== "" && j[a] === j[b] && j[b] === j[c]){
            return j[a];
        }
    }

    return null;
};

//~ FUNCAO QUE VERIFICA SE O QUADRO ESTÁ CHEIO
function verificarQuadroPreenchido(){
    for(let i = 1; i <= 9; i++){
        if(document.querySelector('#botao' + i).innerText === ""){
            return false;
        }
    }
    return true;
};

//~ FUNÇÃO QUE DETECTA EMPATE
function empate(){
    if(verificarVencedor() === null){limpar();}
    if(verificarVencedor() === "X" && verificarVencedor() === "O"){
        limpar();
    }
};

//~ FUNCAO QUE LIMPA O QUADRO
function limpar(){
    if(verificarQuadroPreenchido() === true){
        for(let i = 1; i <= 9; i++){
            document.querySelector('#botao' + i).innerText = "";
        }
    }
    else if(verificarQuadroPreenchido() === false && verificarVencedor() !== null){
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
    
    //~ ESCREVER X e O
    if(jogador === 0){
        if(botao.innerText === "") { jogador++;  valor = "X"; }
    } else {
        if(botao.innerText === "") { jogador--;  valor = "O"; }
    }

    if(botao.innerText === "") { botao.innerText = String(valor); }

    //~ PLACAR
    let venceu = verificarVencedor();
    
    if(venceu === "X"){
        X++;
        placarX.innerText = X;
        setTimeout(limpar, 300); //aplica a função com delay
        jogador = 0;
        valor = "X";
    }

    else if(venceu === "O"){
        O++;
        placarO.innerText = O;
        setTimeout(limpar, 300); //aplica a função com delay
    }

    else{
        setTimeout(empate, 300); //aplica a função com delay
    }
            
    console.log("Vencedor: " + verificarVencedor());
    console.log("Jogador: " + jogador);
    console.log("Vencedor: " + verificarVencedor() + " X: " + X + " O: " + O);
    console.log("Verificar Quadro Preenchido:" + verificarQuadroPreenchido());
    console.log("------------");
}

// Quando clica em um botão já escrito;
// Placar;
//! Design;