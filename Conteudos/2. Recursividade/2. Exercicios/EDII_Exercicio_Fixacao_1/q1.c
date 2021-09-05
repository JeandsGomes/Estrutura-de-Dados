#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
1) Faça o rastreamento do códigos a seguir e diga o que os mesmos fazem, dizendo qual a diferença entre eles. 
Obs.: A string b, contém 0s e 1s.
Obs.: Na chamada de misterio1 e de misterio2 dec e p devem ser 0 e i deve ser strlen(b) - 1.
Obs.: a função pow, calcula a potência de 2 elevado a i.
Obs.: O número da posição 0(zero) de b, será a posição strlen(b) -1 do número binário.
Obs.: rastrear código significa, fazer uma simulação com valores mostrando o que acontece no código.
*/

void misterio1(char b[20], float *dec, int p, int i)
{
    if(p < strlen(b))
    {
        if(b[p] == '1')
            *dec = *dec + pow(2,i);
        misterio1(b,dec,++p,--i);
    }
}

/*

*Oque a função faz??
Transforma um numero binario do tipo string em um numero em escala decial do tipo float

*Quais são os parametros ??
Seus parametros são: 
    b : String que contera o numero em binario;
    dec : Ponteiro float que apos a execução da função contera o valor do numero informado 
    em b, convertido para escala decimal. Deve ser inicializado com o valor zero;
    p : Inteiro com função de contador de casas unitarias do numero em binario contido na 
    variavel 'b';
    i = Interio que contem o valor da quantidade de casas unitarias que ainda serão lidas
    no numero contido em 'b'.

*O que a função retorna?
A função não tem retorno.

*Descrição de como funciona:
Inicialmente é verificado pelo 1° IF se o valor da variavel 'p' é menor que o tamnha da 
STRING 'b'. Caso a condição seja falsa, a função é encerrada. Se a condição for verdadeira 
sera feita uma segunda verificação.

No segundo IF, sera verificado se o caractere da string 'b', na posição 'p' é igual a '1'.
Caso a condição seja falça não acontecera nada. Se a condição for verdadeira sera adicionado 
a '*dec' o valor de 2 elevado ao valor de 'i'. Ao terminar a verificação sera chamada a função 
'misterio1' entrando assi em recursividade.

*Observaçõs:
Como não a processamento apos a chamada da função, podemos dizer que essa função é recursiva
sem pendencia.

*mostrar exemplos:
Exemplo:
1° entrada: b = "010", dec = 0, p = 0, i = 2, b[p] = '0';
2° entrada: b = "010", dec = 0, p = 1, i = 1, b[p] = '1';
3° entrada: b = "010", dec = 2, p = 2, i = 0, b[p] = '0';
4° entrada: b = "010", dec = 2, p = 3, i = -1.
*/


float misterio2(char b[20], float dec, int p, int i)
{
    printf("- dec = %f,p = %d, i = %d\n",dec,p,i);
    if(p < strlen(b))
    {   
        dec = misterio2(b,dec,p+1,i-1);
        if(b[p] == '1')
            dec = dec + pow(2,i);
    }
    return(dec);
}

/*

*Oque a função faz??
Retorna um numero em escala decial do tipo float a partir de um numero binario do tipo string.

*Quais são os parametros ??
Seus parametros são: 
    b : String que contera o numero em binario;
    dec : Variavel float com o valor do numero informado em b, convertido para escala decimal. 
    Deve ser inicializado com o valor zero;
    p : Inteiro com função de contador de casas unitarias do numero em binario contido na 
    variavel 'b';
    i = Interio que contem o valor da quantidade de casas unitarias que ainda serão lidas
    no numero contido em 'b'.

*O que a função retorna?
Retorna um valor float, convertido para escala decimal da variavel 'b'.

*Descrição de como funciona:
Inicialmente é verificado pelo 1° IF se o valor da variavel 'p' é menor que o tamnha da 
STRING 'b'. Caso a condição seja falsa, sera passado para a proxima instrução. Se a condição 
for verdadeira, sera chamada a função 'misterio1' entrando assi em recursividade. A recursividade
so partira para a etapa de desempilhamento quando a condição do 1° if for falso. Sendo assim o 
a ultima função chamada retornara 'dec' com valor 0.

Apos a etapa de chamada das funções, sera verificado se o caractere da string 'b', na posição 'p' 
é igual a '1'. Caso a condição seja falça sera passado para a proxima instrução. Se a condição for 
verdadeira sera adicionado a '*dec' o valor de 2 elevado ao valor de 'i'. Ao final dessa operação 
sera passado para a proxima instrução.

A proxima instrução sera o retorno da variavel dec, que por conta da desempilagem das funções chamadas
retornara o valor esperado.

*Observaçõs:
Como ha processameno apos a chamada da função, podemos dizer que essa função é recursiva com 
pendencia.

*mostrar exemplos:
Exemplo:
1° entrada: b = "010", dec = 0, p = 0, i = 2, b[p] = '0';
2° entrada: b = "010", dec = 0, p = 1, i = 1, b[p] = '1';
3° entrada: b = "010", dec = 2, p = 2, i = 0, b[p] = '0';
4° entrada: b = "010", dec = 2, p = 3, i = -1.
*/

int main(){
    char b[] = "010";
    float *dec;
    dec = (float *)malloc(sizeof(float));
    *dec = 0;
    int p = 0;
    int i = strlen(b)-1;

    misterio1(b,dec,p,i);
    printf("miterio1 = %f\n",*dec);
    *dec = 0;
    printf("misterio2 = %f\n",misterio2(b,*dec,p,i));

    return 0;
}