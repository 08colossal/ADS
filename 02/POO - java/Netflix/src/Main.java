import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Catalogo catalogo = new Catalogo();
        Scanner scanner = new Scanner(System.in);

        System.out.println("===Cadastro de filme===");
        System.out.println("Digite '1' para cadastrar um filme.\nDigite '2' para cadastrar uma série.");
        int tipoCadastro = scanner.nextInt();
        scanner.nextLine(); // Consome o '\n' restante

        switch(tipoCadastro){
            case 1:
                System.out.println("Nome do filme: ");
                String nomeFilme = scanner.nextLine();

                System.out.println("\nNome do diretor: ");
                String nomeDiretor = scanner.nextLine();

                System.out.println("\nDuração do filme: ");
                int duracaoFilme = scanner.nextInt();
                scanner.nextLine();

                catalogo.adicionar(new Filme(nomeFilme, duracaoFilme, nomeDiretor));
                break;

            case 2:
                System.out.println("Nome da série: ");
                String nomeSerie = scanner.nextLine();

                System.out.println("\nDuração do episódio: ");
                int duracaoEpisodio = scanner.nextInt();

                System.out.println("\nTemporadas: ");
                int temporadasSerie = scanner.nextInt();
                scanner.nextLine();

                catalogo.adicionar(new Serie(nomeSerie, duracaoEpisodio, temporadasSerie));
                break;
        }

        catalogo.adicionar(new Filme("Interestelar", 169, "Christopher Nolan"));
        catalogo.adicionar(new Filme("Toy Story", 81, "JohnLasseter"));
        catalogo.adicionar(new Serie("Stranger Things", 50, 4));

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
}