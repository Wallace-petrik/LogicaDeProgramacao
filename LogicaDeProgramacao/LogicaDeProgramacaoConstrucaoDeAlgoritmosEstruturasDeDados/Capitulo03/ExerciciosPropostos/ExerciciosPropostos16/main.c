#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int x,y,cont = 0,resp = 1;

   printf("\nDigite  o valor de X e Y para calcular a exponencição x^y: ");
        scanf("%d%d",&x,&y);

    do{

        resp *= x;

    }while(++cont< y);

   if(y==0){
        resp = 1;
   }

    printf("\n %d^%d = %d\n",x,y,resp);
    return 0;
}
