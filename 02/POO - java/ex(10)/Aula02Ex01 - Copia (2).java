import java.util.Scanner;

public class Aula02Ex01 {
    public static double converter(double c) {
        return (c * 9/5) + 32;
    }
   
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Digite os celsius:");
        double celsius = scan.nextDouble();
        double temp = converter(celsius);
        System.out.println("Fahrenheit: " + temp);
    }

}
//0C * 9/5     + 32 = 32F
