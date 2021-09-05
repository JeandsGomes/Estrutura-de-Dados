#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
5) Dado uma lista simplesmente encadeada e ordenada de pessoas:
Faça as seguintes funções:
(a) Uma função recursiva que devolva o nome da pessoa mais velha da lista, caso exista mais de uma 
devolva um vetor com os nomes.
(b) Uma função recursiva que devolva a menor e a maior altura.
(c) Uma função recursiva que devolva o número de pessoas com a altura mediana.
(d) Uma função recursiva que devolva o número de pessoas abaixo de 40 anos com a altura maior do que a 
altura mediana. 
 Obs.: altura mediana = (menor altura + maior altura)/2
*/

struct pessoa{
    int Id;
    char Nome[100];
    int AnoNascimento;
    int Altura;
};
struct lista{
    struct pessoa Info;
    struct lista *Prox;
};

//Realiza a alocação da lista
struct lista *aloca_lista(){
    struct lista *No;
    No = NULL;

    No = (struct lista*)malloc(sizeof(struct lista));

    No->Prox = NULL;


    return No;
}

//Isere elementos na lista
void insere(struct lista **begin, struct lista **end,struct lista *No){
    struct lista *aux, *ant;

    aux = *begin;
    if(*begin == NULL){
        *begin = No;
        *end = No;

    }else if(No->Info.Id < (*begin)->Info.Id){
        *begin = No;
        No->Prox = aux;
    }
    
    else if(No->Info.Id > (*end)->Info.Id){
        aux = *end;
        aux->Prox = No;
        *end = No;
    }else{
        aux = *begin;
        while( No->Info.Id > aux->Info.Id && aux != NULL){
            ant = aux;
            aux = aux->Prox;
        }
        No->Prox = aux;
        ant->Prox = No;
        
    }
}

//Imprime elementos da lista
void imprimir(struct lista *pessoas){
    struct lista *aux;
    aux = pessoas;
    if(aux != NULL){
        printf("ID: %d\nNome: %s \nAno Nasc: %d\nAltura: %d\n\n\n", aux->Info.Id, aux->Info.Nome, aux->Info.AnoNascimento, aux->Info.Altura);

        imprimir(aux->Prox);
    } 
}


void mais_velha(struct lista *pessoas, int *velha){

/*
*Oque a função faz??
Insere o valor da idade da pessoa mais velha no ponteiro '*velha'.

*Quais são os parametros ??
Seus parametros são:

pessoas : Lista de pesssoas

velha : Ponteiro do tipo inteiro , que recbera o valor da idade do individuo mais velho. 

*Qual é a função retorna?
Esse função não tem retorno.

*/

    struct lista *aux;
    aux = pessoas;

    int idade;
    if(aux != NULL){
        idade = 2021 - aux->Info.AnoNascimento;

        if(idade > *velha){
            *velha = idade;
        }
        mais_velha(aux->Prox, velha);
    }
}


int qtd_mais_velhas(struct lista *pessoas, int maior_idade){
    
/*
*Oque a função faz??
Retorna a quantidade de pessoas que tem a idade igual ao valor da variavel 'maior_idade'.

*Quais são os parametros ??
Seus parametros são:

pessoas : Lista de pesssoas.

maior_idade : Variavel do tipo inteira com o valor da idade da pessoas mais velha da lista 'pessoas'. 

*Qual é a função retorna?
Retorna a quantidade de individuos na lista 'pessoas', que tem a idade igual ao valor da variavel 'maior_idade'.

*/

    struct lista *aux;
    aux = pessoas;

    int qtd=0;

    if(aux != NULL){
        if (2021 - aux->Info.AnoNascimento == maior_idade){
            qtd = qtd_mais_velhas(aux->Prox, maior_idade) + 1;
        }else{
            qtd = qtd_mais_velhas(aux->Prox, maior_idade) + 0;

        }
    }
    return qtd;
}


void nome_velha(struct lista *pessoas, int maior_idade, char nome[100]){

/*
*Oque a função faz??
Retorna o nome da pessoa mais velha.

*Quais são os parametros ??
Seus parametros são:

pessoas : Lista de pesssoas.

nome : Variavel do tipo inteira com o valor da idade da pessoas mais velha da lista 'pessoas'. 

*Qual é a função retorna?
Retorna o nome do individuo na lista 'pessoas', que tem a idade igual ao valor da variavel 'maior_idade'.

*/

    struct lista *aux;
    aux = pessoas;

    if(aux != NULL){
        if(2021 - aux->Info.AnoNascimento == maior_idade){
            strcpy(nome, aux->Info.Nome);
        }
        nome_velha(aux->Prox, maior_idade, nome);
    }
}

//(a) Uma função recursiva que devolva o nome da pessoa mais velha da lista, caso exista mais de uma 
//devolva um vetor com os nomes.
void mais_velhas(struct lista *pessoas, char nomes[100][100],int velha, int *i){

/*
*Oque a função faz??
Retorna um vetor com os nomes das pessoas com a maior idade.

*Quais são os parametros ??
Seus parametros são:

pessoas : Lista de pesssoas.

nomes : Vetor de String com duas dimençõe, que servira de local para inserir o nome dos individuos com maior idade.

velha : Variavel do tipo inteiro, com o valor da idade do individuo mais velha na lista 'pessoas'.

i : Ponteiro do tipo inteiro, que tem a função de contar a quantidade de idividuos com idade igual ao valor na variavel 'velha'.

*Qual é a função retorna?
Essa função não tem retorno.
*/

    struct lista *aux;
    aux = pessoas;

    if(aux != NULL){
        if(2021 - aux->Info.AnoNascimento == velha){
            strcpy(nomes[*i], aux->Info.Nome);
            (*i)++;//se pessoa tiver a idade da pessoas mais velha, copia seu nome para o vetor e incrementa o i
        }
        // chama recursivamente sem pendencia
        mais_velhas(aux->Prox, nomes, velha, i);
    }
}

//(b) Uma função recursiva que devolva a menor e a maior altura

// devolve menor e maior altura por referência
// paramentro menor e maior inicia com a idade da primeira pessoa da lista e a lista começa da segunda pessoa (pessoas->prox)
void maior_menor_altura(struct lista *pessoas, int *menor, int *maior){

/*
*Oque a função faz??
Devolve menor e maior altura por referência para as respectivas ponteiros 'maior' e 'menor'.

*Quais são os parametros ??
Seus parametros são:

pessoas : Lista de pesssoas.

menor : Poeito do tipo inteiro que recebera o valor da menor autura dos individuos na lista 'pessoas'.

maior : Poeito do tipo inteiro que recebera o valor da maior autura dos individuos na lista 'pessoas'.

*Qual é a função retorna?
Essa função não tem retorno.
*/

    struct lista *aux;
    aux = pessoas;

    if(aux != NULL){
        if(aux->Info.Altura > *maior){
            *maior = aux->Info.Altura;
        }
        if(aux->Info.Altura < *menor){
            *menor =aux->Info.Altura;
        }
        maior_menor_altura(aux->Prox, menor, maior);
    }
}

//(c) Uma função recursiva que devolva o número de pessoas com a altura mediana.
void qtd_mediana(struct lista *pessoas, int maior, int menor, int *qtd){
/*
*Oque a função faz??
Devolve o número de pessoas com a altura mediana.

*Quais são os parametros ??
Seus parametros são:

pessoas : Lista de pesssoas.

menor : Variavel do tipo inteiro com valor da menor autura dos individuos na lista 'pessoas'.

maior : Variavel do tipo inteiro com valor da maior autura dos individuos na lista 'pessoas'.

qtd : Ponteiro do tipo inteiro que recebe o valor da quantidade de pessoas com autura igual a mediana
das auturas dentro da lista 'pessoas'.

*Qual é a função retorna?
Essa função não tem retorno.
*/

    struct lista *aux;

    if (aux != NULL){
        if (aux->Info.Altura == (menor+maior)/2){
            (*qtd)++;
        }
        qtd_mediana(aux->Prox, maior, menor, qtd);
    }
    
}

//(d) Uma função recursiva que devolva o número de pessoas abaixo de 40 anos com a altura maior do que a 
//altura mediana. 
void idade_40_altura_med(struct lista *pessoas,int mediana, int *qtd){

/*
*Oque a função faz??
Devolve devolva o número de pessoas abaixo de 40 anos com a altura maior do que a altura mediana.

*Quais são os parametros ??
Seus parametros são:

pessoas : Lista de pesssoas.

media : Variavel do tipo inteiro com valor da autura mediana dos individuos na lista 'pessoas'.

qtd : Ponteiro do tipo inteiro que tem como função realizar a contagem dos individuos na lista 'pessoas',
com idade abaixo de 40 anos com a altura maior do que a altura mediana..

*Qual é a função retorna?
Essa função não tem retorno.
*/

    struct lista *aux;
    aux = pessoas;
    if(aux != NULL){
        if(2021 - aux->Info.AnoNascimento < 40 && aux->Info.Altura > mediana){
            (*qtd)++;
        }
        idade_40_altura_med(aux->Prox, mediana, qtd);
    }
}

//Menu do programa
int menu(){
    int op;
    printf("1 - Cadastrar Pessoas\n2 - Imprimir Pessoas\n3 - Pessoa mais velha\n4 - Menor e Maior Altura\n5 - Pessoas Com Altura Mediana\n6 - Idade < 40 e Altura > Media\n0 - Sair\n");
    scanf("%d", &op);
    
    return op;
}

int main(){

    struct lista *pessoas, *pessoas_end, *No, *aux;

    pessoas = pessoas_end = NULL;

    int escolha, id, altura, ano, continuar, maior=0, menor, qtd=0, mediana=0, velha=0, i;
    char nome[100], leitura_nome[100], nomes[100][100];


    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            // insere pessoa(as) na lista
            do{
                printf("id: ");
                scanf("%d", &id);
                printf("nome: ");
                scanf("%s", leitura_nome);
                printf("ano de nascimento: ");
                scanf("%d", &ano);
                printf("altura: ");
                scanf("%d", &altura);
                setbuf(stdin, NULL);
                No = aloca_lista();
                No->Info.Id = id;
                strcpy(No->Info.Nome, leitura_nome);
                No->Info.AnoNascimento = ano;
                No->Info.Altura = altura;

                insere(&pessoas, &pessoas_end, No);

                
                printf("Deseja adicionar mais? (1 - SIM || 0 - NAO)");
                scanf("%d", &continuar);
                setbuf(stdin, NULL);
            }while(continuar != 0); 
            break;
        //imprime a lista de pessoas
        case 2:
            imprimir(pessoas); 
            break;
        
        case 3:
//(a) Uma função recursiva que devolva o nome da pessoa mais velha da lista, caso exista mais de uma 
//devolva um vetor com os nomes
            qtd = 0;
            velha = 2021 - pessoas->Info.AnoNascimento;// a idade da pessoa mais velha inicia com a idade da primeira pessoa da lista
            mais_velha(pessoas, &velha);
            qtd = qtd_mais_velhas(pessoas, velha);

            //se tiver apenas uma pessoa mais velhar
            if(qtd == 1){
                nome_velha(pessoas, velha, nome);
                printf("Nome da Pessoa Mais Velha: %s\n", nome);
            // se houver varias pessoas mais velhas
            }else{
                i=0;
                mais_velhas(pessoas, nomes, velha, &i);
                for(int y=0; y < qtd; y++){
                    printf("%s\n", nomes[y]);
                }
            }
            break;
//(b) Uma função recursiva que devolva a menor e a maior altura.
        case 4:
            maior = menor = pessoas->Info.Altura;
            maior_menor_altura(pessoas->Prox, &menor, &maior);
            printf("Maior Altura: %d\nMenor Altura: %d\n\n", maior, menor);
            break;
        
//(c) Uma função recursiva que devolva o número de pessoas com a altura mediana
        case 5:
            //pega primeiro a maior e menor altura
            menor = menor = pessoas->Info.Altura;
            maior_menor_altura(pessoas->Prox, &menor, &maior);
            //retorna por parametro a quantidade pessoas com altura mediana
            qtd_mediana(pessoas, maior, menor, &qtd);
            printf("Quantidade de Pessoas com Altura Mediana: %d\n", qtd);
            break;
//d) Uma função recursiva que devolva o número de pessoas abaixo de 40 anos com a altura maior do que a altura mediana. 
        case 6:
            qtd = 0;
            menor = menor = pessoas->Info.Altura;
            maior_menor_altura(pessoas->Prox, &menor, &maior);
            mediana = (maior + menor)/2;
            idade_40_altura_med(pessoas, mediana, &qtd);
            printf("Quantidade de Pessoas com Altura Maior que a Mediana e idade menor que 40: %d\n", qtd);
            break;
        default:
            if(escolha != 0){
                printf("Valor invalido!\n");
            }
            break;  
        }
    } while (escolha != 0);

    return 0;
}

