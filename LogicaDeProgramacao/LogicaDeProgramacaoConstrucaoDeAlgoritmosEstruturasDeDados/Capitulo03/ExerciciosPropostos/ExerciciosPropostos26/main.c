#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    float s = 0;
    int i = 0;

    while(++i<=10){

        if(i%2==0){
            s = s -(float)i/(i*i);
        }else{
            s+= s +(float)i/(i*i);
        };

    }

    printf("\n%.2f",s);

    return 0;
}
