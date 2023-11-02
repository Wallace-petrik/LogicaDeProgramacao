#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int number,maior,menor;
    int i;

    maior = number;
    menor = number;

    while(++i<=20){
        printf("\nEntre com o %dº número: ",i);
            scanf("%d",&number);

            if(i==1){
                maior = number;
                menor = number;
            }else{
                if(number>maior){
                    maior=number;
                }else{
                    if(number<menor){
                        menor=number;
                    }
                }
            }


    }

    printf("\nO maior número = %d.\nO menor número = %d.\n",maior,menor);
    return 0;
}
