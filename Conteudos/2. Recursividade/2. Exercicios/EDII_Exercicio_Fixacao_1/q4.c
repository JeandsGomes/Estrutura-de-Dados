#include <stdio.h>
#include <stdlib.h>

/*
4) Faça um algoritmo em C que leia 5 números inteiros e então faça:
(a) Uma função recursiva sem pendência que calcule Mínimo Múltiplo Comum (MMC) entre os números 
lidos.
(b) Repita o exercício da letra a, mas agora faça uma função recursiva que deixa pendência.
*/


//(a) Uma função recursiva sem pendência que calcule Mínimo Múltiplo Comum (MMC) entre os números lidos.
void MMC_sem_pendencia(int a,int b,int c,int d,int e,int aux, int *MMC){

/*
*Oque a função faz??
Realiza a operação de MMC, inserindo na variavel '*MMC' o valor do Minimo Multiplo Comum.

*Quais são os parametros ??
Seus parametros são: 
a : Variavel do tipo inteiro 1° valor.

b : Variavel do tipo inteiro 2° valor.

c : Variavel do tipo inteiro 3° valor.

d : Variavel do tipo inteiro 4° valor.

e : Variavel do tipo inteiro 5° valor.

aux : Variavel do tipo inteira, que sera incrementada com mais 1 a medida que a variavel 'aux'
não for mais divisivel pelas variaveis citadas a cima. É esperado que a variavel seja iniciada
com o valor 2.

MMC: Ponteiro do tipo inteiro que contera o valor do Minimo Multiplo comum.

*Qual é a função retorna?
A função não tem retorno.

*/

    int flag = 0;
    int numero; 

    //Etapa de verificação da divisibilidade de 'aux' em relação as variaveis 'a','b','c','d','e'. 
    if(a != 1 && a % aux == 0){
        a = a/aux;
        flag = 1;
    }
    if(b != 1 && b % aux == 0){
        b = b/aux;
        flag = 1;
    }
    if(c != 1 && c % aux == 0){
        c = c/aux;
        flag = 1;
    }
    if(d != 1 && d % aux == 0){
        d = d/aux;
        flag = 1;
    }
    if(e != 1 && e % aux == 0){
        e = e/aux;
        flag = 1;
    }

    
    if( a+b+c+d+e == 5 && flag == 1){//Verifica se as variaveis verificadas são maiores que 1 (1+1+1+1+1 = 5) e se 'aux' é divisor de alguma variavel.
        *MMC = (*MMC) * aux;
    }else{
        if(flag == 1){//Verifica se existe alguma variavel divisivel por 'aux'.
            numero = aux;
        }else{
            numero = 1;
            aux++;
        }
        *MMC = (*MMC) * numero;
        MMC_sem_pendencia(a,b,c,d,e,aux,MMC);//chamada da recurção.
    }

}


//(b) Repita o exercício da letra a, mas agora faça uma função recursiva que deixa pendência.
int MMC_com_pendencia(int a,int b,int c,int d,int e, int aux){

/*
*Oque a função faz??
Realiza a operação de MMC, inserindo na variavel MMC o valor do Minimo Multiplo Comum.

*Quais são os parametros ??
Seus parametros são: 
a : Variavel do tipo inteiro 1° valor.

b : Variavel do tipo inteiro 2° valor.

c : Variavel do tipo inteiro 3° valor.

d : Variavel do tipo inteiro 4° valor.

e : Variavel do tipo inteiro 5° valor.

aux : Variavel do tipo inteira, que sera incrementada com mais 1 a medida que a variavel 'aux'
não for mais divisivel pelas variaveis citadas a cima. É esperado que a variavel seja iniciada
com o valor 2.

*Qual é a função retorna?
Retorna o valor do Minimo Multiplo Comum.

*/

    int flag = 0;
    int MMC = 1;
    int numero;
    int numero_2;//recebe o valor retornado na função

    if(a != 1 && a % aux == 0){
        a = a/aux;
        flag = 1;
    }
    if(b != 1 && b % aux == 0){
        b = b/aux;
        flag = 1;
    }
    if(c != 1 && c % aux == 0){
        c = c/aux;
        flag = 1;
    }
    if(d != 1 && d % aux == 0){
        d = d/aux;
        flag = 1;
    }
    if(e != 1 && e % aux == 0){
        e = e/aux;
        flag = 1;
    }
    
    if( a+b+c+d+e == 5){
        MMC = aux;
    }else{
        if(flag == 1){
            numero = aux;
        }else{
            numero = 1;
            aux++;
        }

        numero_2 = MMC_com_pendencia(a,b,c,d,e,aux);//recursão
        MMC = MMC * numero * numero_2; //pendecia
    }


    return MMC; 
}

int main(){

    int a,b,c,d,e;
    int aux = 2;
    int *MMC = (int*)malloc(sizeof(int));
    *MMC = 1;

    printf("Informe o PRIMEIRO numero: ");scanf("%d",&a);
    printf("Informe o SEGUNDO numero: ");scanf("%d",&b);
    printf("Informe o TERCEIRO numero: ");scanf("%d",&c);
    printf("Informe o QUARTO numero: ");scanf("%d",&d);
    printf("Informe o QUINTO numero: ");scanf("%d",&e);

    MMC_sem_pendencia(a,b,c,d,e,aux,MMC);
    printf("MMC sem pendencia: %d\n",*MMC);
    printf("MMC com pendencia: %d\n",MMC_com_pendencia(a,b,c,d,e,aux));

    return 0;
}