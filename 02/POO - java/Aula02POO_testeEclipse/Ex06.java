import java.util.Scanner;
/*
 * Imprima o menu:

1 - área de um círculo

2 - área de um retângulo

3 - área de um quadrado

De acordo com a escolha do usuário, peça os dados necessários e calcule a área correspondente (Área Círculo = 3.14 * raio * raio, Área Retângulo = base * altura, Área Quadrado = lado * lado).
 * */
public class Ex06{
	public static void menu(){
		System.out.println("1 - Área de um circulo"
				+ "\n2 - Área de um retângulo"
				+ "\n3 - Área de um quadrado"
				+ "\nDigite sua escolha: ");
	}
	
		
	public static void main(String[] args) {
		try (Scanner scan = new Scanner(System.in)) {
			Ex06.menu();
			int escolha = scan.nextInt();
			
			switch(escolha) {
			case 1:
				System.out.println("Digite o raio do circulo:");
				double valorRaio = scan.nextDouble();
				System.out.println("A área é: " + 3.14*valorRaio*valorRaio);
				break;
				
			case 2:
				System.out.println("Digite os valores de base e altura:");
				double valorBase = scan.nextDouble();
				double valorAltura = scan.nextDouble();
				System.out.println("A área é: " + valorBase*valorAltura);
				break;
				
			case 3:
				System.out.println("Digite o valor dos lados:");
				double valorLado = scan.nextDouble();
				System.out.println("A área é: " + valorLado*valorLado);
				break;
				
			default:
				System.out.println("Opção inválida");
				break;
			}
		}
	}
}