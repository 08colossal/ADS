let arquivoHandle = null;

async function envio(){

    let formulario = document.querySelector("#forms");
    let nome = document.querySelector("#id_nome").value;
    let checkIn = document.querySelector("#id_checkIn").checked; //para checkbox
    let data = document.querySelector("#id_data").value;

    formulario.addEventListener("submit", async function(event){
        event.preventDefault();
        console.log("Enviado!");
    });

    let statusCheck = checkIn ? "Sim" : "Não";
    let novaLinha = `Nome: ${nome} | Check-in: ${statusCheck} | Data ${data}\n`
    
    let historico = document.querySelector("#historico");
    if (historico){
            historico.innerHTML += novaLinha.replace(/\n/, "<br>");
    }
/*/////// EDITAR ESSA PARTE USANDO O CÓDIGO DO PROFESSOR
    try{
        if(!arquivoHandle){
            [arquivoHandle] = await window.showOpenFilePicker({
                suggestedName:'results.txt',
                types: [{
                    description: 'Arquivos de texto',
                    accept: {'text/plain': ['.txt']}
                }]
            })
        }

        const arquivo = await arquivoHandle.getFile();
        const conteudoAntigo = await arquivo.text();
        const conteudoNovo = conteudoAntigo + novaLinha;

        const reescreve = await arquivoHandle.createWritable();
        await reescreve.write(conteudoNovo);
        await reescreve.close();

        const arquivoAtualizado = await arquivoHandle.getFile();
        const conteudoFinal = await arquivoAtualizado.text();

        if(historico){
            historico.innerHTML = conteudoFinal.replace(/\n/, "<br>");
        }
    }
    catch (erro){
        console.log("Cancelado")
    }*/

    //para +18 ou -18 tal console....
    //para check nao clicado...
    //pedir email e numero para check ligado...

    console.log(nome);
    console.log(data);
    console.log(checkIn);
}