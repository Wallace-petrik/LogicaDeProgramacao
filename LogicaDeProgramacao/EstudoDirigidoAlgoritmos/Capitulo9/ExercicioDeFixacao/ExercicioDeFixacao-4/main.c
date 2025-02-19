#include <stdio.h>
#include <locale.h>
#include <string.h>

#define elem 1

struct{

    int mat;
    float sal;
    char nome[30];

}typedef Empregado;

int main(){

    setlocale(LC_ALL,"");

    Empregado empregado[elem];

    int opcao = 0;


    do{
        system("cls");
        printf("1 para cadastra empregados\n");
        printf("2 para casificar por matrícula\n");
        printf("3 para pesquisar empregado\n");
        printf("4 para listar empregados com salário > 1000\n");
        printf("5 para listar empregados com salário < 1000\n");
        printf("6 para listar empregados com salário = 1000\n");
        printf("0 para sair\n:");
            scanf("%d%*c",&opcao);

        switch(opcao){

            case 0:{
                printf("\n Até logo\n");
                getchar();

            break;}

            case 1:{
                for(int i = 0; i < elem; i++){
                    system("cls");
                    printf("Digite a matrícula do empregado: ");
                        scanf("%d%*c",&empregado[i].mat);
                    printf("Entre com o nome do empregado: ");
                    fgets(empregado[i].nome,50,stdin);
                    empregado[i].nome[strcspn(empregado[i].nome,"\n")] = '\0';
                    printf("Entre com o salário: ");
                        scanf("%f%*c",&empregado[i].sal);
                }

            break;}

            case 2:{
            int continua;
            int fim = elem;
            Empregado aux;
            system("cls");
            do{
                continua = 0;
                for(int i = 0; i < elem-1; i++){
                    if(empregado[i].mat>empregado[i+1].mat){
                        aux = empregado[i];
                        empregado[i] = empregado[i+1];
                        empregado[i+1] =  aux;

                        continua = i;
                    }
                }
               fim--;
            }while(continua != 0);

            printf("\n\tCassificação\n\n");

            for(int i = 0; i < elem; i++){
                printf("Mat: %d\tNome: %s\n",empregado[i].mat, empregado[i].nome);
            }
            getchar();
            break;}

            case 3:{

            int achou = 0;
            int indexe;
            int mat;

            system("cls");
            printf("Digite a matrícula do empregado: ");
                    scanf("%d%*c",&mat);

            for(int i = 0; i < elem; i ++){


                if(mat==empregado[i].mat){
                    achou = 1;
                    indexe = i;
                    break;
                }
            }

            if(achou == 1){
                printf("Enpregado encontrado\nNome: %s\tSalário: %.2f",empregado[indexe].nome,empregado[indexe].sal);
            }else printf("Empregado não encontrado !!!");

            getchar();

            break;}

            case 4:{
                system("cls");
                int fim = elem;
                int continua;
                int achou = 0;
                Empregado auxEmpregado;

                do{
                    continua = 0;
                    for(int i = 0; i< elem-1; i++){
                        if(empregado[i].mat>empregado[i].mat){
                            auxEmpregado = empregado[i];
                            empregado[i] = empregado[i+1];
                            empregado[i+1] = auxEmpregado;
                            continua = i;
                        }
                    }
                    fim--;
                }while(continua != 0);

                for(int i = 0; i < elem; i++){
                    if(empregado[i].sal>1000){
                        printf("\nMat: %d\tNome: %s\tSalário: %.2f",empregado[i].mat,empregado[i].nome,empregado[i].sal);
                        achou = 1;
                    }
                }
                if(achou == 0){
                    printf("\nEmpregado não encontrado !!!");
                }
                getchar();
            break;}

            case 5:{

            break;}

            case 6:{

            break;}

            default:{
                printf("\nOpção invalida !!!\n");
                getchar();
                system("cls");
            break;}

        }
    }while(opcao!=0);

    return 0;
}
