
import java.util.Scanner;
/*Faça um programa que receba a idade de uma pessoa e identifique se ela pode/deve votar este ano, sabendo que:

16 e 17 anos: voto facultativo

18 a 70 anos: voto obrigatório

Acima de 70 anos: voto facultativo*/
public class Ex02 {
   
    public static void votos(int n) {
        if (n == 16 || n == 17 || n > 70) {
        	System.out.println("Voto facultativo");
        }
        else if(n >= 18 && n <= 70) {
        	System.out.println("Voto obrigatório");
        }
        else {
        	System.out.println("Voto inválido");
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Sua idade: ");
        int num = scan.nextInt();
        Ex02.votos(num);
    }

}
