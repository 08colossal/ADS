public static void main(String[] args){
    Catalogo catalogo = new Catalogo();
    Scanner scanner = new Scanner();

    System.out.println("===Cadastro de filme===");
    System.out.println("Digite '1' para cadastrar um filme.\nDigite '2' para cadastrar uma série.");
    int tipoCadastro = scanner.nextInt();

    switch(tipoCadastro){
        case 1:
            System.out.println("Nome do filme: ");
            String nomeFilme = scanner.nextLine();

            System.out.println("\nNome do diretor: ");
            String nomeDiretor = scanner.nextLine();

            System.out.println("\nDuração do filme: ");
            int duracaoFilme = scanner.nextInt();

            catalogo.adicionar(new Serie(titulo:nomeFilme, diretor:direcaoFilme, duracao:duracaoFilme))
            break;

        case 2:
            System.out.println("Nome da série: ");
            String nomeSerie = scanner.nextLine();

            System.out.println("\nDuração do episódio: ");
            String duracaoEpisodio = scanner.nextInt();

            System.out.println("\nTemporadas: ");
            int temporadasSerie = scanner.nextInt();

            catalogo.adicionar(new Serie(titulo:nomeSerie, duracao:duracaoEpisodio, temporadas:temporadasSerie))
            break;
    }

    catalogo.adicionar(new Filme(titulo:"Interestelar", duracao:169, diretor:"Christopher Nolan"));
    catalogo.adicionar(new Filme(titulo:"Toy Story", duracao:81, diretor:"JohnLasseter"));
    catalogo.adicionar(new Serie(titulo:"Stranger Things", duracao:50, temporadas:4));

    System.out.println("=== Catálogo ===");
    catalogo.listarTodos();

    System.out.println("=== Busca ===");
    Conteudo encontrado = catalogo.buscarPorTitulo("toy story");
    if(encontrado != null){
        System.out.println("Encontrado: " + encontrado.exibirDetalhes());
    }
    else{
        System.out.println("Não encontrado");
    }
}