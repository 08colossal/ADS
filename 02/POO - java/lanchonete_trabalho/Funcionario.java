public class Funcionario {
    protected String nome;
    protected double salario;

    public Funcionario(String nome, double salario) {
        this.nome = nome;
        this.salario = salario;
    }

    public double calcularSalario() {
        return salario;
    }

    public void exibir() {
        System.out.println(nome + " salário R$ " + calcularSalario());
    }
}