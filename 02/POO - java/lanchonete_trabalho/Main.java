public class Main {
    public static void main(String[] args) {
        // Teste comida e bebida
        Produto l = new Lanche("L01", "X-Burger", 20.0, 2);
        l.exibirItem();
        System.out.println("Preço final: R$ " + l.calcularPrecoFinal());

        Produto b = new Bebida("B01", "Suco", 8.0, true);
        b.exibirItem();
        System.out.println("Preço final: R$ " + b.calcularPrecoFinal());

        // Teste cozinheiro
        Cozinheiro cozinheiro = new Cozinheiro("Paulo", 2000.0, "massas");
        cozinheiro.exibir();
        cozinheiro.cozinhar();

        // Teste pedidos
        Entregavel pedido = new Pedido("Ana", 35.0);
        pedido.entregar();

        Entregavel encomenda = new Encomenda("Bruno", 3.0);
        encomenda.entregar();
    }
}