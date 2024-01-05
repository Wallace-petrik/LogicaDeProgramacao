#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define tam 5
int main(){
    setlocale(LC_ALL,"");
    srand(time(NULL));

    int controle;
    int matriz[tam][tam];

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            matriz[i][j] = rand() % 10;
        }
    }

    do{
        printf("\n 1/Para escreva a diagonal Principal.");
        printf("\n 2/Para escreva o triangulo superior à diagonal Principal.");
        printf("\n 3/Para escreva o triangulo inferior à diagonal Principal.");
        printf("\n 4/Para escreva o tudo exceto diagonal Principal.");
        printf("\n 5/Para escreva a diagonal Secundaria.");
        printf("\n 6/Para escreva o triangulo superior à diagonal Secundaria.");
        printf("\n 7/Para escreva o triangulo inferior à diagonal Secundaria.");
        printf("\n 8/Para escreva o tudo exceto diagonal Secundaria.");
        printf("\n 9/Para sair.\n");

        printf("\nEscolha uma opção: ");
            scanf("%d",&controle);
            printf("\n");

        switch(controle){
            case 1 :
                for(int i = 0; i < tam; i++){
                    for(int j = 0; j < tam; j++){
                        if(i==j){
                            printf("[%2d]",matriz[i][j]);
                        }else{
                            printf("[--]");
                        }
                    }
                    printf("\n");
                }
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                getchar();
            break;
            case 2 :
               for(int i = 0; i < tam; i++){
                    for(int j = 0; j < tam; j++){
                        if(i<j){
                            printf("[%2d]",matriz[i][j]);
                        }else{
                            printf("[--]");
                        }
                    }
                    printf("\n");
                }
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                getchar();
            break;
            case 3 :
                for(int i = 0; i < tam; i++){
                    for(int j = 0; j < tam; j++){
                        if(i>j){
                            printf("[%2d]",matriz[i][j]);
                        }else{
                            printf("[--]");
                        }
                    }
                    printf("\n");
                }
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                getchar();
            break;
            case 4 :
                for(int i = 0; i < tam; i++){
                    for(int j = 0; j < tam; j++){
                        if(i!=j){
                            printf("[%2d]",matriz[i][j]);
                        }else{
                            printf("[--]");
                        }
                    }
                    printf("\n");
                }
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                getchar();
            break;
            case 5 :
                for(int i = 0; i < tam; i++){
                    for(int j = 0; j < tam; j++){
                        if(i+j==4){
                            printf("[%2d]",matriz[i][j]);
                        }else{
                            printf("[--]");
                        }
                    }
                    printf("\n");
                }
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                getchar();
            break;
            case 6 :
                for(int i = 0; i < tam; i++){
                    for(int j = 0; j < tam; j++){
                        if(i+j<=3){
                            printf("[%2d]",matriz[i][j]);
                        }else{
                            printf("[--]");
                        }
                    }
                    printf("\n");
                }
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                getchar();
            break;
            case 7 :
                for(int i = 0; i < tam; i++){
                    for(int j = 0; j < tam; j++){
                        if(i+j>4){
                            printf("[%2d]",matriz[i][j]);
                        }else{
                            printf("[--]");
                        }
                    }
                    printf("\n");
                }
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                getchar();
            break;
            case 8 :
                for(int i = 0; i < tam; i++){
                    for(int j = 0; j < tam; j++){
                        if(i+j!=4){
                            printf("[%2d]",matriz[i][j]);
                        }else{
                            printf("[--]");
                        }
                    }
                    printf("\n");
                }
                printf("\nPressione qualquer tecla para continuar.");
                getchar();
                getchar();
            break;
            case 9 :
                printf("Até logo.");
            break;
            default:
                printf("\nOpção invalida");
                printf("\nTente novamente.\n");
            break;
        }
    }while(controle != 9);

    return 0;
}
