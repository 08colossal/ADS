public class Filme extends Conteudo{ //utiliza atributos da classe Conteudo
    private String diretor;

    public Filme(Strinf titulo, int duracao, String diretor){
        super(titulo, duracao); //puxa da classe mãe
        this.diretor = diretor;
    }

    @Override //sobrescreve o método que existia na classe mãe
    public String exibirDetalhes(){
        return "Filme: " + super.exibirDetalhes() + " - Diretor: " + diretor;
    }
}