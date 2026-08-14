import java.util.Scanner;
//leia 3 numeros e exiba o maior
public class Aula02Ex04 {

    public static void trisal(int a, int b, int c){
        if (a>b && a>c){
            System.out.println("O maior número é: " + a);
        }
        else if(b>a && b>c){
            System.out.println("O maior número é: ", b);
        }
        else if(C>a && c>b){
            System.out.println("O maior número é: ", c);
        }
        else{
            System.out.println("Algum numero ta repetido conserte bb");
        }
    } 
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

    }
}
