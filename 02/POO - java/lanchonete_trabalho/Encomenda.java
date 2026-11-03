public class Encomenda implements Entregavel {
    private String cliente;
    private double pesoKg;

    public Encomenda(String cliente, double pesoKg) {
        this.cliente = cliente;
        this.pesoKg = pesoKg;
    }

    @Override
    public double calcularEntrega() {
        return TAXA_ENTREGA + (pesoKg * 2.0);
    }

    @Override
    public void entregar() {
        double taxa = calcularEntrega();
        System.out.println("Encomenda de " + cliente + " entregue. Taxa: R$ " + taxa);
    }
}