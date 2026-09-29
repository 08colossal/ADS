# Plano — Jogo da Velha (atualizado)

Arquivos: `tictactoe.html`, `botoes.css`, `logica.js`.
Somente `logica.js` precisa de alterações.

**Regra do jogo (definida com o usuário):** ao vencer ou empatar, mostrar o
resultado na tela por **1,2 s**, depois limpar o tabuleiro e começar nova
partida **sem zerar o placar**.

---

## ✅ O que já foi corrigido

| # | Bug | Solução aplicada |
|---|---|---|
| 1 | `b1..b9` copiavam o texto no load e nunca mudavam | Novo `lerTabuleiro()` (`logica.js:10`) lê os 9 botões **na hora** |
| 2 | Verificação rodava antes de escrever X/O | Escrita (linha 85) antes de `verificarVencedor()` (linha 88) |
| 3 | Retorno `undefined` e comparação `"1"`/`"0"` | `verificarVencedor()` sem parâmetro retorna `"X"`, `"O"` ou `null`; placar compara com `"X"`/`"O"` |
| 4 | `let [a,b,c] = linhas` destruturava o array errado | Corrigido para `let [a,b,c] = linha` (linha 28) |
| 5 | Índices 1..9 num array 0..8 | `linhas` com índices 0-based (linhas 23-24) |
| 6 | Vitória apagava o quadro na hora | Vitória/empate agora usam `setTimeout(limpar, 1200)` (linhas 93, 101) |

---

## ❌ O que falta (estado atual do código)

### Falta 1 — `logica.js:104-106`: `setTimeout(empate, 1200)` roda a TODA jogada

```js
else{
    setTimeout(empate, 1200);   // agenda um "empate" a cada jogada normal
}
```

Cada jogada sem vencedor agenda um `empate()` para 1,2 s depois, e
`empate()` chama `limpar()`, que tem esta guarda (linha 62):

```js
else if(verificarQuadroPreenchido() === false && verificarVencedor() !== null){ limpa }
```

**Linha do tempo do bug:** jogada 4 agenda `empate` para T+1,2 s → a jogada
vencedora acontece em T+1,19 s → o `empate` da jogada 4 dispara 0,01 s depois,
encontra o vencedor e **limpa o quadro na hora** (é o bug "some da tela mesmo
assim"). Também limpa sozinho no meio de partidas futuras.

**Solução:** apagar a função `empate()` (linhas 47-53, com condição impossível
na linha 50) e tratar empate **só com o quadro cheio**:

```js
else if(verificarQuadroPreenchido()){   // SÓ nas 9 casas cheias
    fimDeJogo = true;
    setTimeout(limpar, 1200);
}
```

### Falta 2 — não existe a flag `fimDeJogo`

Nos 1,2 s de delay o quadro continua clicável. Qualquer clique (inclusive em
casa ocupada, pois a linha 88 roda sempre) reexecuta `venceu === "X"` → `X++`
**outra vez** → placar dispara e agenda novas limpezas.

**Solução:** `let fimDeJogo = false;` e, no topo de `acao(n)`:

```js
if(fimDeJogo || botao.innerText !== "") return;
```

Vitória/empate: `fimDeJogo = true;` antes do `setTimeout`.
`limpar()`: `fimDeJogo = false;` ao final.

### Falta 3 — reset do turno só no branch do X (linhas 94-95)

- Branch do O (98-102) e empate não resetam → próxima partida começa com o
  jogador errado.
- O reset acontece **antes** da limpeza (clique durante o delay usa turno já
  zerado com o quadro ainda cheio).

**Solução:** tirar `jogador = 0; valor = "X";` das linhas 94-95 e colocar
**dentro de `limpar()`**, junto com a limpeza das casas.

### Falta 4 — `limpar()` com condições redundantes (linhas 56-68)

Dois ramos que fazem a mesma coisa. Simplificar:

```js
function limpar(){
    if(verificarQuadroPreenchido() || verificarVencedor() !== null){
        for(let i = 1; i <= 9; i++){
            document.querySelector('#botao' + i).innerText = "";
        }
        jogador = 0;
        valor = "X";
        fimDeJogo = false;
    }
}
```

*(ou remover as condições e limpar sempre — a função só é chamada em fim de
partida)*

### Falta 5 — features de interface (opt-in, mas recomendadas)

| Feature | Onde | Como |
|---|---|---|
| Mostrar de quem é a vez / resultado | `<h3 id="status">` (HTML linha 13) | `"Vez do X"`, `"Vez do O"`, `"X venceu!"`, `"O venceu!"`, `"Empate!"` — atualizar em `acao()` e resetar em `limpar()` |
| Placar iniciar em 0 | `#X` / `#O` (HTML 16-17) | No fim do `logica.js`: `document.querySelector("#X").innerText = 0;` idem para `#O` |
| Remover código morto | `logica.js:5` | Deletar `let contador = 0;` (nunca usado) |
| Console mais limpo | `logica.js:108-111` | Reaproveitar a variável `venceu` em vez de chamar `verificarVencedor()` 4× |

---

## 📋 Plano de execução (`logica.js` apenas)

1. Adicionar `let fimDeJogo = false;` (topo) e a guarda
   `if(fimDeJogo || botao.innerText !== "") return;` no início de `acao(n)`.
2. Nos 3 blocos de fim de jogo (vitória X, vitória O, empate):
   `fimDeJogo = true;` + `setTimeout(limpar, 1200);` — **sem** `limpar()` direto.
3. `else` → `else if(verificarQuadroPreenchido())`; **apagar** `empate()`.
4. `limpar()`: simplificar a condição; dentro: limpar casas, `jogador = 0`,
   `valor = "X"`, `fimDeJogo = false`.
5. Interface: `#status` com vez/vencedor/empate, placar inicial `0`,
   remover `contador`, limpar os `console.log`.
6. Atualizar este `plano.md` após a aplicação.

### Arquivos

| Arquivo | Ação |
|---|---|
| `logica.js` | Correções acima |
| `tic-tac-toe.html` | Nenhuma alteração necessária |
| `botoes.css` | Nenhuma alteração necessária |

---

## ✔️ Verificação

1. Abrir `tictactoe.html` no navegador (Ctrl+F5).
2. Completar uma linha → a linha vencedora **fica visível ~1,2 s**, depois some;
   placar soma 1 e **não zera**; nova partida começa com **X**.
3. Clicar em casa ocupada → nada muda (sem turno, sem placar).
4. Clicar durante o delay de 1,2 s → placar **não** soma de novo.
5. Preencher as 9 casas sem vencedor → "Empate!" e limpeza após 1,2 s.
6. Jogar 3+ partidas seguidas → placar só cresce, iniciante é sempre X.
