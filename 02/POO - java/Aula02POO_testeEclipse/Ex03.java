import java.util.Scanner;
/*
 * Para doar sangue é necessário ter idade entre 18 e 67 anos e peso superior a 50 kg. Pergunte idade e peso e diga se a pessoa pode doar
 * */
public class Ex03{
   
    public static boolean verifyAge(int a) {
    	if (a >= 18 && a <= 67) {
    		return true;
    	}
    	else {
    		return false;
    	}
    	
    }
    
    public static boolean verifyWeight(int w) {
    	if (w >= 50) {
    		return true;
    	}
    	else {
    		return false;
    	}
    }

    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) { //o eclipse sugeriu usar try(?)
			System.out.println("Digite sua idade: ");
			int num = scan.nextInt();
			System.out.println("Digite seu peso: ");
			int peso = scan.nextInt();
			if (Ex03.verifyAge(num) == true && Ex03.verifyWeight(peso) == true) {
				System.out.println("Você pode doar sangue! Idade: " + num + " Peso: " + peso);
			}
			else {
				System.out.println("Você não preenche todos os requisitos para doar sangue! idade: " + num + " Peso: " + peso);
			}
        }
    }

}
