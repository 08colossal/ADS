import java.util.Scanner;

public class Aula02Ex02 {
   
    public static void tabuada(int n) {
        for (int i = 1; i <= 10; i++){
            int r = i*n;
            System.out.println(n + " x " + i + " = " + r);
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Digite o algarismo para formar a tabuada: ");
        int num = scan.nextInt();
        Aula02Ex02.tabuada(num);
    }

}
