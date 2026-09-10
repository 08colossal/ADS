/* 
Desafio:
"Filtrar produtos disponíveis e com preço abaixo de um valor definido"
Você deve criar um programa que:
Tenha um array de objetos representando produtos, cada um com:
nome (string)
preco (número)
disponivel (boolean)
Peça ao usuário (via prompt ou valor fixo no código) um preço máximo.
Use filter() para retornar apenas os produtos:
Que estejam disponíveis (disponivel === true)
E cujo preço seja menor ou igual ao valor informado.
Mostre o resultado no console.

Além de filtrar os produtos disponíveis e com preço abaixo do valor definido, você deve:
Formatar o nome do produto para maiúsculas.
Formatar o preço para o padrão brasileiro (R$ 0,00).
Retornar apenas um array de strings já prontas para exibição.
*/

let nome = "";
let preco = 0;
let disp = false;
let n = Number(prompt("Quantos produtos quer cadastrar?")); //number pq prompt(caixinha) lê texto!
let produtos = [n];

for (let i = 0; i < n; i++){
    nome = prompt("Qual o nome do produto?");
    preco = Number(prompt("Qual o valor do produto?"));
    disp = Boolean(prompt("Está disponível ou não? (true/false"));

    produtos[i] = {nome, preco, disp};
}

let pMax = Number(prompt("Qual o valor máximo de um produto?"));
let f = produtos.filter(produtos => produtos.disp === true && produtos.preco <= pMax);

console.log(`Filtrados: ${f}`);
/*
function format(nome, preco){
    nome.Upper();
    preco = `R$${preco}`;
    return nome, preco;
}

for (let i = 0; i < n; i++){
    format(nome, preco);
}*/