public class Serie extends Conteudo{
    private int temporadas;

    public String(String titulo, int duracao, int temporadas){
        super(titulo, duracao);
        this.temporadas = temporadas;
    }

    @Override
    public String exibirDetalhes(){
        return "Serie: " + super.exibirDetalhes() + " - Temporadas" + temporadas; 
    }
}