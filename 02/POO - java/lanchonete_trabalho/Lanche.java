public class Lanche extends Produto {
    private int adicionais;

    public Lanche(String codigo, String nome, double preco, int adicionais) {
        super(codigo, nome, preco);
        this.adicionais = adicionais;
    }

    @Override
    public double calcularPrecoFinal() {
        return preco + (adicionais * 2.5);
    }
}