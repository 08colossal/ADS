import java.util.Scanner;
/*
 * Crie um programa que leia a quantidade de números que o usuário deseja digitar, e ao final apresente o maior e o menor valor digitado. Não suponha que todos os números serão positivos.
 */
public class Ex08{
	public static void main(String[] args) {
		try (Scanner scan = new Scanner(System.in)) {
			System.out.println("Quantos números deseja digitar?");
			int qtd = scan.nextInt();
			int atual, menor = 0 , maior = 0;
			
			for(int i = 1; i <= qtd; i++) {
				System.out.println(i + ":");
				atual = scan.nextInt();
				if (i == 1) {
					menor = atual;
					maior = atual;
				}
				if(atual == menor || atual < menor) {
					menor = atual;
				}
				if(atual == maior || atual > maior) {
					maior = atual;
				}				
			}
			
			System.out.println("Foram digitados " + qtd + " números. O maior foi " + maior + " e o menor foi " + menor);
			
		}
		
	}
}