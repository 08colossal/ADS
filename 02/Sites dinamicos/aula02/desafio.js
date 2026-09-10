//desafio rayanne
// uma loja possui um carrinho com os preços dos produtos armazenados em um arrar
//aplique 20% de desconto no valor total a compra e aponte o valor final

const precoCart = [20, 25, 17, 39];
let soma = 0;
for(let i = 1; i<= 3; i++){
    soma += precoCart[i];
}
let m = soma * 0.8;
console.log("O valor total é:"+m.toFixed(0));
//pegar length, for i < len, [i]++, total*1,2

