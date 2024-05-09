#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define tam 10

void informacaoCoincidentesEntreDuasPosicoes(int p1, int p2);
void buscarPorNome(char nome[tam]);
typedef struct{

    int numeroDeIdentidade;
    char nome[tam];
    float altura;
    char sexo;
    int idade;

}Registro;

Registro vet[5];

int contador = 0;

int main(){

    setlocale(LC_ALL,"");

    int opcao = 0, controle = 0, p1 = 0, p2 = 0;

    char nome[tam];

    do{

        system("cls");
        printf("1 para cadastrar\n");
        printf("2 compara dados\n");
        printf("3 buscar por nome\n");

        printf("\n\nDigite uma opção: ");
            scanf("%d",&opcao);

        switch(opcao){

            case 0:

                system("cls");
                printf("\nAté logo!!!\n");
                system("pause");

            break;
            case 1:

                system("cls");
                fflush(stdin);
                printf("Nome: ");
                    scanf("%[^\n]",&vet[contador].nome);
                printf("Número de identidade: ");
                    scanf("%d",&vet[contador].numeroDeIdentidade);
                printf("Altura: ");
                    scanf("%f",&vet[contador].altura);
                    fflush(stdin);
                printf("Sexo: ");
                    scanf("%c",&vet[contador].sexo);
                printf("Idade: ");
                    scanf("%d",&vet[contador].idade);

                    contador++;

                printf("\nDados cadastrados com sucesso\n");
                system("pause");
            break;
            case 2:

                system("cls");
                printf("Digite duas posições: ");
                    scanf("%d%d",&p1,&p2);

                informacaoCoincidentesEntreDuasPosicoes(p1-1,p2-1);

            break;
            case 3:

                system("cls");
                printf("Nome: ");
                    fflush(stdin);
                    scanf("%[^\n]",&nome);

                buscarPorNome(nome);

            break;
            default:

                system("cls");
                printf("\nOpção invalida\n");
                system("pause");
        }

    }while(opcao  != 0);

    return 0;
}

void informacaoCoincidentesEntreDuasPosicoes(int p1, int p2){

    int controle = 0;

    if(p1 <= contador && p2 <= contador){
        if(strcmp(vet[p1].nome,vet[p2].nome)==0){
            printf("\nNome: %s",vet[p1].nome);
            controle = 1;
        }
        if(vet[p1].altura==vet[p2].altura){
            printf("\nAltura: %.2f",vet[p1].altura);
            controle = 1;
        }
        if(vet[p1].sexo==vet[p2].sexo){
            printf("\nSexo: %c",vet[p1].sexo);
            controle = 1;
        }
        if(vet[p1].idade==vet[p2].idade){
            printf("\nIdade: %d",vet[p1].idade);
            controle = 1;
        }
        if(controle = 0){
            printf("\nDados não são coincidentes\n");
        }
    }else{
        system("cls");
        printf("\nPosiçã2o invalida\n");
        system("pause");
    }
}

void buscarPorNome(char nome[]){
    int controle = 0;
    for(int i = 0; i < contador; i++){

        if((strcmp(vet[i].nome,nome))==0){

            printf("\nNome: %s",vet[i].nome);
            printf("\nAltura: %.2f",vet[i].altura);
            printf("\nSexo: %c",vet[i].sexo);
            printf("\nIdade: %d\n",vet[i].idade);
            controle = 1;

        }

    }

    if(controle == 0){

        printf("\nUsuário não encontrado");
        system("pause");

    }else{
        system("pause");
    }

}

