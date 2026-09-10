import java.util.Scanner;
/*
 * Leia a renda mensal de uma pessoa e calcule o imposto de renda devido, conforme a tabela:

Renda mensal  -  Alíquota

Até R$ 1.637,11 - Isento

R$ 1.637,12 a R$ 2.453,50 - 7,5%

R$ 2.453,51 a R$ 3.271,38 - 15,0%

R$ 3.271,39 a R$ 4.087,65 - 22,5%

A partir de R$ 4.087,66 - 27,5%

O programa deve permitir várias consultas seguidas, conforme opção do usuário (perguntar "deseja continuar? 1- sim ou 2 - não após cada cálculo). -> do{} while();
 */
public class Ex07{
	
	public static double percentual(double renda) {
		double p;
		if (renda <= 1637.11) {
			p = 0;
		}
		else if(renda <= 2453.5){
			p = 7.5;
		}
		else if(renda <= 3271.38) {
			p = 15;
		}
		else if(renda <= 4087.65) {
			p = 22.5;
		}
		else {
			p = 27.5;
		}
		return p;
	}
	
	public static double calculo(double renda, double percentual) {
		double c = renda * percentual / 100;
		return c;
	}
	
	public static void main(String[] args) {
		try (Scanner scan = new Scanner(System.in)) {
			int escolha;
			
			do {
				System.out.println("\nQual sua renda mensal?");
				double rendaMensal = scan.nextDouble();
				double porcentagem = Ex07.percentual(rendaMensal);
				double imposto = Ex07.calculo(rendaMensal, porcentagem);
				
				System.out.println("O valor do seu imposto de renda é: " + imposto);
				System.out.println("\nDeseja realizar uma nova consulta?\n1 - sim\n2 - não");
				escolha = scan.nextInt();
				
			}
			while(escolha == 1);
		}
	}
}