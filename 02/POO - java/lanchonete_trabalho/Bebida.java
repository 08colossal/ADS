public class Bebida extends Produto {
    private boolean gelada;

    public Bebida(String codigo, String nome, double preco, boolean gelada) {
        super(codigo, nome, preco);
        this.gelada = gelada;
    }

    @Override
    public double calcularPrecoFinal() {
        if (gelada) {
            return preco + 1.0;
        } else {
            return preco;
        }
    }
}