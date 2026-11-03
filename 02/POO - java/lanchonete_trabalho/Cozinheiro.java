public class Cozinheiro extends Funcionario {
    private String especialidade;
    public static final double ADICIONAL_COZINHA = 150.0;

    public Cozinheiro(String nome, double salario, String especialidade) {
        super(nome, salario);
        this.especialidade = especialidade;
    }

    @Override
    public double calcularSalario() {
        return super.calcularSalario() + ADICIONAL_COZINHA;
    }

    public void cozinhar() {
        System.out.println(nome + " está preparando pratos de " + especialidade + ".");
    }
}