#include <stdio.h>
#include <locale.h>
#include<math.h>

int main(){
    setlocale(LC_ALL,"");

    int contador = 0,contadorF = 0, diferenca;
    float altura,maiorAltura = 0,menorAltura = 0,mediaF;
    char sexo;

    while(contador++<4){

        printf("\nDigite a altura da pessoa: ");
            scanf("%f",&altura);
        printf("\nDigite o sexo, F /p Feminino e M/p Masculino: ");
            scanf(" %c",&sexo);

        if(contador==1){menorAltura=altura;}

        if(altura>=maiorAltura){
            maiorAltura = altura;
        }else if(altura<=menorAltura){
            menorAltura = altura;
        }

        if(sexo=='f'||sexo=='F'){
            mediaF+=altura;
            contadorF++;
        }
    }

    printf("\nA maior altura: %.2f",maiorAltura);
    printf("\nA menor altura: %.2f",menorAltura);
    printf("\nMédia da altura das Mulheres: %.2f",mediaF/contadorF);
    printf("\nNúmero de Homens = %d",4-contadorF);

    diferenca = abs((4-contadorF)-contadorF);

    printf("\nDiferença em porcentual %.2f",(100*diferenca)/4);
    return 0;
}
