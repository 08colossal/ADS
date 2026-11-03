public abstract class Produto {
    protected String codigo;
    protected String nome;
    protected double preco;

    public Produto(String codigo, String nome, double preco) {
        this.codigo = codigo;
        this.nome = nome;
        this.preco = preco;
    }

    public void exibirItem() {
        System.out.println("[" + codigo + "] " + nome + " R$ " + preco);
    }

    public abstract double calcularPrecoFinal();
}