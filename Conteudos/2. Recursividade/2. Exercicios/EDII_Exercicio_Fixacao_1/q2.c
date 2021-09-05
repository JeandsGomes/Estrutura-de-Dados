#include <stdio.h>
#include <stdlib.h>

#define MAX 50

/*
2) Faça uma função que dado um número inteiro devolva os divisores do mesmo, a função deve ser recursiva.
*/

void retorna_divisores(int vet[MAX],int n, int aux, int *tamanho){

/*
*Oque a função faz??
Uma função que dado um número inteiro devolva os divisores do mesmo.

*Quais são os parametros ??
Seus parametros são: 
vet : Vetor vazio que sera armazenado os divisores da variavel n.

n: Variavewl do tipo interio que representa o numero que queremos saber os 
divisores.

aux : Variavel do tipo inteiro que auxilia que sera decrementada a cada chamada
de função para que seja verificado se essa variavel é divisor ou não por 'n'. 
É preferivel que seja inicializada com o valor de 'n'.

tamanho: Ponteiro do tipo interio que apos a execução da função contera o valor
do tamanho da quantidade de divisores armazenados em vet.

*Qual é a função retorna?
A função não tem retorno.

*/

    if(aux > 0){//condição de parada
        if(n % aux == 0){//Verifica se 'n' é divisivel por 'aux'.
            vet[*tamanho] = aux;//insere o valor divisor de 'n'.
            *tamanho = *tamanho + 1;//incrementa tamanho.
        }
        retorna_divisores(vet,n,--aux,tamanho);//recursão decrementando o valor de 'aux'.
    }
}

//imprime os valores contidos no vetor
void imprimir(int vetor[MAX], int index, int tamanho_vetor){
    if(index < tamanho_vetor){ //condição de parada
        printf("vetor[%d] = %d\n",index,vetor[index]); 
        imprimir(vetor,++index,tamanho_vetor);//recursão sem pendencia incrementando o index
    }
}


int main(){

    int vet[50];
    int n = 50;
    int aux = n;
    int *tamanho = (int *)malloc(sizeof(int));
    *tamanho = 0;

    retorna_divisores(vet,n,aux,tamanho);

    int index = 0;
    imprimir(vet,index,*tamanho);

    return 0;
}