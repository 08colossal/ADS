public class Pedido implements Entregavel {
    private String cliente;
    private double valor;

    public Pedido(String cliente, double valor) {
        this.cliente = cliente;
        this.valor = valor;
    }

    @Override
    public double calcularEntrega() {
        if (valor >= 50.0) {
            return 0.0;
        } else {
            return TAXA_ENTREGA;
        }
    }

    @Override
    public void entregar() {
        double taxa = calcularEntrega();
        System.out.println("Pedido de " + cliente + " entregue. Taxa: R$ " + taxa);
    }
}