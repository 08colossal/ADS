#include <stdio.h>

int fibonacci_recursivo (int n){
    if (n <= 1){
        return n;
    }
    return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2);
}

int main(void){
    int n;
    printf("Posicao inteira positiva:");
    scanf("%d", &n);

    if(n<0){
        printf("Deve ser maior ou igual a zero\n");
        return 1;
    }
    printf("Fibonacci recusrsivo na posicao %d = %d\n", n, fibonacci_recursivo(n));

    return 0;
}

int fibonacci_iterativo(int n){
    if (n<=1){
        return n;
    }

    int a = 0;
    int b = 1;
    int c;

    for (int i =2; i <= n; i++){
        c = a + b;
        a = n;
        b = c;
    }
    return b;
}
int main(void){
    int n;
    printf("Posição postiva: ");
    scanf("%d", &n);

    if (n<0){
        printf("Tem q ser maior que zero\n");
        return 1;
    }

    printf("Fibonacci iterativo na posicao %d = %d\n", n, fibonacci_iterativo(n));

    return 0;
}

/*

Caso base: "if (n <= 1){return n;}"





QUESTÕES TEÓRICAS

1. E X P L I Q U E A D I F E R E N Ç A E N T R E A S A B O R D A G E N S I T E R A T I V A E
R E C U R S I V A N O C Á L C U L O D O F A T O R I A L .

-   Iterativa: usa loop e multiplica os números até n, acumulando os resultados em variáveis, utilizando pouca memória;
-   Recursiva: a função chama a si mesma com f(n-1) até f(n) ser f(1), criando camadas na memória;



2 . S E N O C Ó D I G O D O F A T O R I A L R E C U R S I V O V O C Ê R E M O V E R A
L I N H A I F ( N < = 1 ) R E T U R N 1 ; , O Q U E A C O N T E C E R Á S E C H A M A R
F A T O R I A L ( 3 ) ? E X P L I Q U E O M O T I V O .

-   F(1) e abaixo disso (n = -988) será 0 em fibonacci, pois 0 é o primeiro número da sequência;
    Definir esse caso base faz o código não rodar infinitamente;
    Portanto, se a linha for excluida a memória terá overflow de camadas, pois terá um loop infinito.



3 . C O M O V O C Ê F A R I A P A R A M O D I F I C A R O C Ó D I G O D O F A T O R I A L
I T E R A T I V O P A R A I M P R I M I R C A D A M U L T I P L I C A Ç Ã O I N T E R M E D I Á R I A
( E X E M P L O : 1 X 2 = 2 , 2 X 3 = 6 , E T C . ) ? E S C R E V A A P E N A S A
L Ó G I C A , N Ã O O C Ó D I G O C O M P L E T O .

-   uma var result = 1;
    var anterior = result -> para guardar o resultado anterior;
    result = result * i (i que iniciará em 2, será menor que n em F(n)) 
    então printa anterior * 1 = result, para mostrar o cálculo



4 . P A R A F A T O R I A L ( 4 ) , Q U A I S S Ã O A S C H A M A D A S F E I T A S P E L A
V E R S Ã O R E C U R S I V A ?

    Fatorial(4)
    4 x fatorial(3)
    4 x 3 x fatorial(2)
    4 x 3 x 2 x fatorial (1)
    Quando chega no caso base, encerra as chamadas



5 . S E E X E C U T A R M O S O C Ó D I G O R E C U R S I V O D E F I B O N A C C I P A R A N
= 5 , Q U A I S S Ã O T O D A S A S C H A M A D A S D E F U N Ç Ã O Q U E
O C O R R E R Ã O 

    Fibonacci em posição 5 = F() em posição 4 + em posição 3 = ?
        F() em posição 4 -> F() em posição 3 + em posição 2 = ?
        
            F() em posição 3 -> F() em posição 2 + em posição 1 = ?
                F() em posição 2 -> F() em posição 1 + em posição 0 = ?
                        F() em posição 1 = 1;
                        F() em posição 0 = 0;
                F() em posição 1 = 1;

            F() em posição 2 -> F() em posição 1 + em posição 0 = ?
                F() em posição 1 = 1;
                F() em posição 0 = 0;
            
            F() em posição 1 = 1;
            

        F() em posição 3 -> F() em posição 2 + em posição 1 = ?
            
            F() em posição 2 -> F() em posição 1 + em posição 0 = ?
                F() em posição 1 = 1;
                F() em posição 0 = 0;
            
            F() em posição 1 = 1;



QUESTÕES DE CÓDIGO:


//1
//a
#include <stdio.h>
int socorro(int integer){
        if (integer == 0){
            return 0;
        }
        return (integer % 10) + socorro(integer / 10); 
        //123    3 + func(12) -> 2 + func(1) ==== 3 + 2 + 1 = 6
}
int main(){
    
    int positivo;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &positivo);
    int soma = socorro(positivo);
    printf("%d", soma);

    /*cond para algo zero
    tipo nome(vars) {
        if (smth = 0) {
            return resultado_base;
        }
        return combinacao_com_funcao(problema_menor);
    }*/
    return 0;
}  

//b
#include <stdio.h>
int main(){
    int integer, soma = 0;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &integer);
    while (integer > 0){
        soma += integer % 10; //divide por 10 e printa o resto
        printf("\n%d", soma);
        integer /= 10;
        printf("\n%d",integer);
    /*se integer = 509 -> 9(soma) 50 9(soma) 5 14(soma) 0 -> soma = 14*/
    }
    return 0;
} 





//2
//a
#include <stdio.h>
#include <string.h>

int main(){
    char frase[100]; //cmc do zero 
    printf("Digite uma FRASE ou uma frase se vc for bonzinho com a memoria ram do meu pc: ");
    fgets(frase, sizeof(frase), stdin);
    for (int i = strlen(frase) - 1; i >= 0; i--){
        printf("%c", frase[i]);        
    }
    //printf("Frase invertida: %s", strrev(frase));
    return 0;
}

//b

#include <stdio.h>
#include <string.h>

void inverte_string(char f[100]){
    if (strlen(f) <= 1){
        return;
    }
    for (int i = strlen(f) - 1; i >= 0; i--){
        printf("%c", f[i]);
    }    
}

int main(){
    char frase[100]; //cmc do zero 
    printf("Digite uma FRASE ou uma frase se vc for bonzinho com a memoria ram do meu pc: ");
    fgets(frase, sizeof(frase), stdin);
    inverte_string(frase);
    return 0;
}