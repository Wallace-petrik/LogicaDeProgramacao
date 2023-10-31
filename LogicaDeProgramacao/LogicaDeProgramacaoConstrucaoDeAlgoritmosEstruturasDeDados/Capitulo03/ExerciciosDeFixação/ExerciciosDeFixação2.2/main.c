#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int a , b ,c;

    printf("Entre com 1º valor: ");
        scanf("%d",&a);
    printf("Entre com 2º valor: ");
        scanf("%d",&b);
    printf("Entre com 3º valor: ");
        scanf("%d",&c);

    if(a==b || b ==c){
        printf("Os numeros são iguais");
    }else{
        if(a>b && a>c){
            if(b>c){
                printf("\n\t %d\t %d\t %d",c,b,a);
            }else
                printf("\n\t %d\t %d\t %d",b,c,a);
        }else{
            if(b>a && b>c){
                if(a>c){
                    printf("\n\t %d\t %d\t %d",c,a,b);
                }else
                    printf("\n\t %d\t %d\t %d",a,c,b);
            }else{
                if(c>b && c>a){
                    if(a>b){
                        printf("\n\t %d\t %d\t %d",b,a,c);
                    }else
                        printf("\n\t %d\t %d\t %d",a,b,c);
                }
            }
        }
    }

    return 0;
}
