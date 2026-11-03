let nome = document.querySelector("#id_nome");
let inserir = document.querySelector("#id_inserir");
let buscar = document.querySelector("#id_buscar");

inserir.addEventListener("click", function(event){
    event.preventDefault(); // bloqueia a atualização
    localStorage.setItem("nome_clientes", nome.value);
    alert(`O nome ${nome.value} foi inserido com sucesso !`)
});

