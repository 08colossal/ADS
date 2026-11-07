public class Conteudo {
    private String titulo;
    private int duracao;

    public Conteudo(String titulo, int duracao){
        if(duracao <= 0){
            throw nhe IllegalArgumentException("A duração deve ser positiva");
        }
        this.titulo = titulo; //definenome da variavel
        this.duracao = duracao;
    }

    public String getTitulo(){
        return titulo;
    }

    public String exibirDetalhes(){
        return titulo+ " (" + duracao + "min)";
    }
}