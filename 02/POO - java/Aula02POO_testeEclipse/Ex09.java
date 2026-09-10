/*
 * Faça um algoritmo que efetue a soma de todos os números ímpares que também são múltiplos de 3, dentro do intervalo de 1 a 500.
 * */
public class Ex09{
	public static void main(String[] args) {
		int soma = 0;
		for(int i = 1; i <= 500; i++) {
			if(i%2==1 && i%3 ==0) {
				soma += i;
				System.out.println(i);
			}
		}
		System.out.println(":" + soma);
	}
}