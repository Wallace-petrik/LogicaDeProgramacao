#include <stdio.h>
#include <stdlib.h>



void imprimeNumeros (int a, int b, int c){

    if(a<b && a<c){
        if(b<c){
            printf(" %d %d %d",a,b,c);
        }else{
            printf(" %d %d %d",a,c,b);
        }

    }else if(b<c && b<a){
        if(a<c){
            printf("%d %d %d",b,a,c);
        }else{
            printf("%d %d %d",b,c,a);
        }

    }else if(c<a && c<b){
        if(a<b){
            printf("%d %d %d",c,a,b);
        }else{
            printf("%d %d %d",c,b,a);
        }
    }

}
int main(){

    int a = 0,b = 0,c  = 0;

    do{
        printf("Digite três números diferentes: ");
            scanf("%d%d%d",&a,&b,&c);

        if(a==b || b==c || a==c){
            printf("Algum número digitado é igual á um outro \n");
            printf("Tente novamente\n\n");;
            system("pause");
        }

    }while(a==b || b==c || a==c);

    imprimeNumeros(a,b,c);

    return 0;
}
