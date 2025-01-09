#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL,"");

    int i = 0;

    do{
        i++;
        if(i%4==0){
            printf("%d\n",i);
        }
    }while(i<=20);

    return 0;
}
