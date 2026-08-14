import java.util.Scanner;

public class Aula02Ex03 {
    public static void result(int num){
        if (num%2==0){
            System.out.println("O número é par!");
        }
        else{
            System.out.println("O número é ímpar!");
        }
    } 
    public static void main(String[] args) {
       //par e impar 
       Scanner scan = new Scanner(System.in);
       System.out.println("Digite um inteiro:");
       int parImpar = scan.nextInt();
       Aula02Ex03.result(parImpar);
    }
}
