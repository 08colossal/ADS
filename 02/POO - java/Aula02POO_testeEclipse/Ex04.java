import java.util.Scanner;
/*
 *As maçãs custam R$ 1,30 cada se forem compradas menos de uma dúzia, e R$ 1,00 cada se forem compradas 12 ou mais. Leia a quantidade comprada e calcule o custo total. 
 **/
public class Ex04 {
   
    public static double valorMaca(double r) {
        double m = 0;
    	if (r > 0 && r <= 11) {
        	m = 1.3;
        }
        else if(r >= 12) {
        	m = 1;
        }
        return m;
    }

    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
			System.out.println("Digite quantas maçãs quer comprar: ");
			double quantidade = scan.nextDouble();
			double valor = Ex04.valorMaca(quantidade);
			System.out.println("O valor total é: R$ " + quantidade * valor);
        }
        
    }

}
