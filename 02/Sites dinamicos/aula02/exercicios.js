//programiz debugger
//1
let nome = prompt("1. Digite seu nome:");
let idade = prompt("   Digite sua idade:");
let profissao = prompt("   Digite sua profissão:");
console.log(`Olá, meu nome é ${nome}, tenho ${idade} anos e trabalho como ${profissao}.`);

//2
let n1 = parseFloat(prompt("2. Digite o primeiro número para somar:"));
let n2 = parseFloat(prompt("   Digite o segundo número:"));
console.log(`A soma é: ${n1 + n2}`);

//3
let idadePessoa = parseInt(prompt("3. Digite uma idade para verificar a maioridade:"));
console.log(idadePessoa >= 18 ? "Maior de idade" : "Menor de idade");

// 4
let numSinal = parseFloat(prompt("4. Digite um número para checar o sinal:"));
if (numSinal > 0) {
  console.log("O número é positivo.");
} else if (numSinal < 0) {
  console.log("O número é negativo.");
} else {
  console.log("O número é igual a zero.");
}

//5
let numParImpar = parseInt(prompt("5. Digite um número para checar se é par ou ímpar:"));
console.log(`O número é ${numParImpar % 2 === 0 ? "Par" : "Ímpar"}`);

//6
let nota1 = parseFloat(prompt("6. Digite a primeira nota:"));
let nota2 = parseFloat(prompt("   Digite a segunda nota:"));
let media = (nota1 + nota2) / 2;
console.log(`Média: ${media.toFixed(1)} - ${media >= 7 ? "APROVADO" : "REPROVADO"}`);

//7
console.log("7. Números de 1 até 10:");
for (let i = 1; i <= 10; i++) {
  console.log(i);
}

//8
let numTabuada = parseInt(prompt("8. Digite um número para ver a tabuada:"));
for (let i = 1; i <= 10; i++) {
  console.log(`${numTabuada} x ${i} = ${numTabuada * i}`);
}

//9
let somaTotal = 0;
for (let i = 1; i <= 100; i++) {
  somaTotal += i;
}
console.log(`9. A soma dos números de 1 até 100 é: ${somaTotal}`);

//10
let a = parseFloat(prompt("10. Digite o 1º número:"));
let b = parseFloat(prompt("    Digite o 2º número:"));
let c = parseFloat(prompt("    Digite o 3º número:"));
console.log(`O maior número digitado foi: ${Math.max(a, b, c)}`);

//11
function saudar(nomeParam) {
  return `Olá, ${nomeParam}! Seja bem-vindo(a).`;
}
let nomeSaudacao = prompt("11. Digite um nome para a saudação:");
console.log(saudar(nomeSaudacao));

//12
function calcularMedia(n1Param, n2Param) {
  return (n1Param + n2Param) / 2;
}
let fnNota1 = parseFloat(prompt("12. Digite a 1ª nota para a função:"));
let fnNota2 = parseFloat(prompt("    Digite a 2ª nota para a função:"));
console.log(`Média retornada pela função: ${calcularMedia(fnNota1, fnNota2)}`);

//13
let qtdNomes = parseInt(prompt("13. Quantos nomes deseja cadastrar no array?"));
let listaNomes = [];
for (let i = 0; i < qtdNomes; i++) {
  listaNomes.push(prompt(`    Nome ${i + 1}:`));
}
console.log("Nomes no console:");
listaNomes.forEach(n => console.log(n));

//14
let entradaFilter = prompt("14. Digite números separados por vírgula (ex: 1, 5, 12, 0.5):");
let arrFilter = entradaFilter.split(',').map(n => parseFloat(n.trim()));
let filtrados = arrFilter.filter(num => num > 10 || num < 2);
console.log("Números filtrados (< 2 ou > 10):", filtrados);

//15
const numero =[];
for (let i = 0; i<4; i++){
  let numEntrada = numero(prompt(`Vamos popular o nosso array. Envie o numero ${i+1}`));
  numero.push(numEntrada);
}

let resultado = numero.map(function(num){
  if(num<=10){
    return num * 2;
  }
  else{
    return num;
  }
});

console.log(resultado);