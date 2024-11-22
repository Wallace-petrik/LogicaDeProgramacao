#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    float nota1, nota2, nota3, nota4, media;

    printf("Entre com quatro notas: ");
        scanf("%f%f%f%f",&nota1,&nota2,&nota3,&nota4);

    media = (nota1+nota2+nota3+nota4)/4;

    if(media>=7){
        printf("Aluno aprovado com, nota %.2f",media);
    }else if(media<7){
        float exame;
        printf("Digite valor do exame: ");
            scanf("%f",&exame);
        media = (media+exame)/2;
        if(media>5){
            printf("Aluno aprovado em exame com média = %.2f",media);
        }else{
            printf("Aluno reprovado com média = %.2f",media);
        }
    }

    return 0;
}
