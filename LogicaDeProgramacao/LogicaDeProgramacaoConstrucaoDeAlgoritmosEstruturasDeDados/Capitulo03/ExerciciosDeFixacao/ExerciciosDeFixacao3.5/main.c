#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int ant,atual,prox;
    int num,fat = 1;

    printf("\nEntre com um número\npara calcular o Fatorial: ");
        scanf("%d",&num);

    if(num<0){
        printf("\nEntre com um número positivo.");
    }else{
        if(num==0){
            printf("\n0! = 1");
        }else{
            for(int i = 1; i<=num; i++){
                fat *= i;
            }
            printf("\n%d! = %d",num,fat);
        }
    }
    return 0;
}
