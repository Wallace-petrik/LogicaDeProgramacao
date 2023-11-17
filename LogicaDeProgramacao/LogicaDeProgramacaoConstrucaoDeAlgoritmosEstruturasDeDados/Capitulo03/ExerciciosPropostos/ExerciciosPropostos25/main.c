#include <stdio.h>
#include <locale.h>
#include<math.h>

int main(){
    setlocale(LC_ALL,"");

    float H;
    int i = -1,j = 0;

    while((i+=2)<=100 && (j++)<=50){

    printf("%d/%d = \n",i,j);


    }

    return 0;
}
