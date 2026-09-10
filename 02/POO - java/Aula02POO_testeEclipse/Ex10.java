import java.util.Scanner;
/*
 * Crie um algoritmo que simule as movimentações de uma conta corrente (número da conta, titular e saldo).
 * O programa deve exibir um menu em loop com as opções: 1 - Depositar, 2 - Sacar, 3 - Consultar saldo e 4 - Sair.
 * Se for depósito, credita o valor ao saldo; se for saque, debita do saldo (verifique se há saldo suficiente antes de debitar).
 * O programa só encerra quando o usuário escolher "Sair".
 * */
public class Ex10{
	
	public static void menu() {
		System.out.println("1 - Depositar\n2 - Sacar\n3 - Consultar saldo\n4 - Sair");
	}
	
	public static void main(String[] args) {
		try (Scanner scan = new Scanner(System.in)) {
			System.out.println("Titular da conta:");
			String nome = scan.nextLine();
			System.out.println("Número da conta:");
			int numero = scan.nextInt();
			System.out.println("Saldo atual da conta:");
			double saldo = scan.nextDouble(); 
					
			int opc;
			double adicional, retirar;
			do {
				Ex10.menu();
				opc = scan.nextInt();
				
				switch(opc) {
				case 1:
					System.out.println("Valor a ser depositado:");
					adicional = scan.nextDouble();
					saldo += adicional;
					break;
					
				case 2:
					System.out.println("Valor a sacar:");
					retirar = scan.nextDouble();
					if(retirar > saldo) {
						System.out.println("Saldo inválido para retirada");
					}
					else{
						saldo -= retirar;
					}
					break;
					
				case 3:
					System.out.println("\n\nSerial:" + numero + "		" + "Titular:" + nome + "\nSaldo atual:		" + saldo + "\n");
					break;
					
				case 4:
					System.out.println("Programa encerrado.");
					break;
				
				default:
					System.out.println("Opção inválida. Programa encerrado.");
					break;
				}
				
			}
			while(opc != 4);
		}
		
	}
}