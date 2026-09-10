import java.util.Scanner;
/*
 * Faça um programa que receba um número e identifique se ele é positivo ou negativo. Se positivo, apresente o triplo desse número; se negativo, apresente-o elevado ao quadrado. 
 * */
public class Ex01 {
   
    public static void posNeg(int n) {
        if (n >= 0) {
        	System.out.println(n*3);
        }
        else {
        	System.out.println(n*n); //pesquisar na biblioteca função pow(n, 2) se existe;
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Digite um número inteiro: ");
        int num = scan.nextInt();
        Ex01.posNeg(num);
    }

}
