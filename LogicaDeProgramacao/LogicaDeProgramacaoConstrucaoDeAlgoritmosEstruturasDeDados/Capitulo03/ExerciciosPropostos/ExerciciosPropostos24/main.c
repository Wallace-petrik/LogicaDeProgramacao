#include <stdio.h>
#include <locale.h>
#include<math.h>

int main(){
    setlocale(LC_ALL,"");

    int contador = 0,contadorF = 0,contadorM = 0, diferenca;
    float altura,maiorAltura = 0,menorAltura = 0,mediaF;
    char sexo;

    int const aux = 50;

    while(contador++<aux){

        printf("\nDigite a altura da pessoa: ");
            scanf("%f",&altura);
        printf("\nDigite o sexo, F /p Feminino e M/p Masculino: ");
            scanf(" %c",&sexo);

        if(sexo=='f'||sexo=='F'||sexo=='m'||sexo=='M'){
            if(contador==1){menorAltura=altura;}

            if(altura>=maiorAltura){
                maiorAltura = altura;
            }else if(altura<=menorAltura){
                menorAltura = altura;
            }

            if(sexo=='f'||sexo=='F'){
                mediaF+=altura;
                contadorF++;
            }else{
                contadorM++;
            }
        }else{
            printf("\nOpção invalida!");
        }
    }

    printf("\nA maior altura: %.2f",maiorAltura);
    printf("\nA menor altura: %.2f",menorAltura);
    printf("\nMédia da altura das Mulheres: %.2f",mediaF/contadorF);
    printf("\nNúmero de Homens = %d",aux-contadorF);

    diferenca = abs(contadorF-contadorM);

    printf("\nDiferença em porcentual é de %d%%\n",(100*diferenca)/aux);
    return 0;
}
