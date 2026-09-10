//personagem
function criarPersonagem() {
  const nome = document.getElementById("nome").value;
  const idade = parseInt(document.getElementById("idade").value);
  const res = document.getElementById("res-1"); //resultado

  if (!nome || isNaN(idade)) {
    res.innerText = "Preencha o nome e a idade!";
    return;
  }

  if (idade < 18) {
    res.innerHTML = `<strong>${nome}</strong> é jovem e ganhou <strong>+10 de Agilidade</strong>!`;
  } else {
    res.innerHTML = `<strong>${nome}</strong> é experiente e ganhou <strong>+10 de Força</strong>!`;
  }
}

//ataques
function calcularAtaque(nivel) {
  return nivel > 5 ? nivel * 10 : nivel * 5;
}

function executarAtaque() {
  const nivel = parseInt(document.getElementById("nivel").value);
  const res = document.getElementById("res-2");

  if (isNaN(nivel)) {
    res.innerText = "Digite um nível válido!";
    return;
  }

  const dano = calcularAtaque(nivel);
  res.innerHTML = `Dano calculado: <strong>${dano} HP</strong> de ataque!`;
}

//inimigos
function filtrarInimigos() {
  const vidaMonstros = [150, 45, 200, 80, 12, 300];
  const monstrosFracos = vidaMonstros.filter(vida => vida < 100);
  
  document.getElementById("res-3").innerHTML = 
    `Inimigos fracos (&lt; 100 HP): <code>[${monstrosFracos.join(", ")}]</code>`;
}

// pocoes
function potencializarPocoes() {
  const pocoes = [5, 12, 8, 20, 3];
  const pocoesMelhoradas = pocoes.map(pocao => pocao <= 10 ? pocao * 2 : pocao);
  
  document.getElementById("res-4").innerHTML = 
    `Novas poções: <code>[${pocoesMelhoradas.join(", ")}]</code>`;
}

//combos
function executarCombo() {
  const res = document.getElementById("res-5");
  let historico = [];

  for (let i = 1; i <= 5; i++) {
    historico.push(`Golpe #${i}`);
  }

  res.innerHTML = `Combo desferido: <strong>${historico.join(" ➔ ")}</strong>!`;
}

