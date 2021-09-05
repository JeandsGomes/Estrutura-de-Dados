#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 20
#define ROW 3

/*
3) Faça uma função em C que leia um vetor de strings não ordenado e depois faça: 
(a) uma função recursiva com pendência que devolva a string de maior tamanho.
(b) uma função recursiva sem pendência que devolva a quantidade de strings que iniciam com vogal.
(c) uma função recursiva que devolva um vetor contendo somente as strings com tamanho >=4 e que 
iniciam com letra maiúscula.
*/

char *maior_tam(char str[ROW][TAM], char res[TAM], int i){

/*
*Oque a função faz??
Função recursiva com pendência que devolva a string de maior tamanho.

*Quais são os parametros ??
Seus parametros são: 
str : Vetor de duas dimenções que contem as strings.

res : String que recebera a string de maior tamanho.

i : Vriavel do tipo inteiro, tem como função contar a quantidade de strings dentro do vetor 'str'.

*Qual é a função retorna?
Retorna a string de maior tamanho.

*/

    if (i < ROW){//condição de parada
        
        res = maior_tam(str, res, i+1);//recursão com acressimo no valor da variavel 'i'.
        if(strlen(str[i]) > strlen(res))//verifica se a str[i] é maior que a String na variavel 'res'.
            strcpy(res, str[i]);//Copia a str[i] e a coloca na String 'res'.
    }
    return res;
}


int is_vogal(char v){
/*
*Oque a função faz??
Verifica se o caractere é uma vogal ou não.

*Quais são os parametros ??
Seus parametros são: 

v : varactere que sera verificado.

*Qual é a função retorna?
Retorna 1 se o caractere for uma vogal, e 0 caso contrario.
*/
    int res=0;

    if(toupper(v) == 'A' || toupper(v) == 'E' || toupper(v) == 'E' || toupper(v) == 'I' || toupper(v) == 'O' || toupper(v) == 'U')
        res = 1;
    
    return res;

}

void qtd_init_vogais(char str[ROW][TAM], int i, int *res){
/*
*Oque a função faz??
Verifica se o caractere é uma vogal ou não.

*Quais são os parametros ??
Seus parametros são: 

str : Vetor de duas dimenções que contem as strings.

i : Variavel do tipo inteiro, que conta a quantidade de palavras.

res : Ponteiro do tipo interio que conta a quantidade de strings iniciadas com vagais dentro
do vetor 'str'.

*Qual é a função retorna?
Não há retorno nessa função.
*/  
    if(i < ROW){//condição de parada

        if(is_vogal(str[i][0])){
            (*res)++;//incrementa ao contador de strings iniciadas por vogais.
        }
        qtd_init_vogais(str, ++i, res);//recursão com acressimo no valor da variavel 'i'.
    }
}

// i e y iniciam com 0, tem também dois vetores de string como paramentos sendo o res de saída.
void str_maior4_maius(char str[ROW][TAM], char res[ROW][TAM], int i, int *y){
/*
*Oque a função faz??
Adiciona na variavel 'res' somente as strings com tamanho >=4 e que iniciam com letra maiúscula.

*Quais são os parametros ??
Seus parametros são: 

str : Vetor de duas dimenções que contem as strings.

res: Vetor de duas dimenções que contera as strings com tamanho >=4 e que iniciam com letra maiúscula.

i : Variavel do tipo inteiro, que conta a quantidade de palavras.

y : Ponteiro do tipo interio que conta a quantidade de strings com tamanho >=4 e que iniciam com 
letra maiúscula.

*Qual é a função retorna?
Não há retorno nessa função.
*/
    if( i < ROW){
        if(isupper(str[i][0]) && strlen(str[i]) >= 4){
            strcpy(res[*y],str[i]);
            (*y)++;
            str_maior4_maius(str, res, ++i, y);
        }else{
            str_maior4_maius(str, res, ++i, y);
        }
    }
}


int main(){
    char str[ROW][TAM], maior[TAM], maioresq4[ROW][TAM];
    int y, qtd_vogais=0;

    // leitura do vetor de strings não ordenado
    for(int i=0;  i < ROW;i++){
        printf("Digite uma string: ");
        scanf("%s", str[i]);
    }

    strcpy(maior,maior_tam(str,maior, 0));
    printf("Maior string: %s\n", maior);

    qtd_init_vogais(str, 0, &qtd_vogais);
    printf("Quantidade que inciam com Vogais: %d\n", qtd_vogais);

    str_maior4_maius(str, maioresq4, 0, &y);
    printf("Maiores que 4 e inicio maiuscula\n ");
    for(int i=0; i < y; i++){
        printf("%s\n", maioresq4[i]);
    }

    return 0;
}