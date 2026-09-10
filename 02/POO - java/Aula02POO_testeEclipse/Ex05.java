import java.util.Scanner;
/*
Com base no número de lados informado, apresente o nome da figura:

Lados Nome

3 Triângulo

4 Quadrado ou Retângulo

5 Pentágono

6 Hexágono * */
public class Ex05 {
   
    public static String nomeFigura(int n) {
        String nome;
    	if (n == 3) {
        	nome = "Triângulo";
        }
    	else if (n == 4) {
        	nome = "Quadrado ou Retângulo";
        }
    	else if(n == 5) {
    		nome = "Pentágono";
    	}
    	else if(n == 6) {
    		nome = "Hexágono";
    	}
    	else{
    		nome = "<Valor digitado inválido>";
    	}
		return nome;
    	
    }

    public static void main(String[] args) {
        try (Scanner scan = new Scanner(System.in)) {
			System.out.println("Quantos lados tem a figura?");
			int num = scan.nextInt();
			String figura = Ex05.nomeFigura(num);
			System.out.println("A figura é um " + figura + "!");
		}
    }

}
