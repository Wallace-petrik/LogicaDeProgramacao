#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    float altura;
    char sexo;

    printf("\nQual o seu sexo? ");
        scanf("%c",&sexo);
    printf("\nQual sua altura? ");
        scanf("%f",&altura);

        if(sexo=='m' || sexo == 'M'){
            printf("\nO seu peso ideal é = %.1f",(72.7*altura)-58);
        }else if(sexo=='f' || sexo == 'F'){
            printf("\nO seu peso ideal é = %.1f",(62.1*altura)-44.7);
        }else{
            printf("\nDados invalidos, verifique o sexo;\n M/m para Masculino\n F/f para Feminino");
        }
    return 0;
}
