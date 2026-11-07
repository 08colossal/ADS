import java.util.ArrayList;

public class Catalogo{
    privateArrayList<Conteudo> conteudos = new ArrayList<>(); //<Tipo a ser guardado> | é uma lista de VETORES, ent dá pra adicionar bastante coisa

    public void adicionar(Conteudo conteudo){
        conteudos.add(Conteudo);
    }

    public void ListarTodos(){
        for (Conteudo conteudo : conteudos){
            System.out.println(conteudo.exibirDetalhes());
        }
    }

    public Conteudo buscarPorTitulo(String titulo){
        for (Conteudo conteudo : conteudos){ //para cada conteudos da lista conteudo da classe Conteudo
            if (conteudo.getTitulo().equalsIgnoreCase(titulo)){ // se o this.filme é igual a 'filme'
                return conteudo;
            }
        }
    }
}