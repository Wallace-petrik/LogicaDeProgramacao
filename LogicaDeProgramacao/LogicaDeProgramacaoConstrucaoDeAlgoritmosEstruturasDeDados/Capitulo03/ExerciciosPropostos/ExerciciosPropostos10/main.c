#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int idade;

    printf("\nEntre com sua idade: ");
        scanf("%d",&idade);

    if(idade<16){
        printf("\nNão votante.");
    }else if(idade>=18 && idade<=65){
        printf("\nEleitor obrigatório");
    }else if((idade >= 16 && idade<18)|| (idade>65)){
        printf("\nEleitor facultativo.");
    }

    return 0;
}
