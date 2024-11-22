#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int nota1, nota2,nota3,nota4;
    float media;

    printf("Digite quatro notas: ");
        scanf("%d%d%d%d",&nota1,&nota2,&nota3,&nota4);

    media = (nota1+nota2+nota3+nota4)/4;

    if(media>= 5){
        printf("Aluno aprovado com nota = %.2f",media);
    }else{
        printf("Aluno reprovado com nota = %.2f",media);

    }

    return 0;
}
