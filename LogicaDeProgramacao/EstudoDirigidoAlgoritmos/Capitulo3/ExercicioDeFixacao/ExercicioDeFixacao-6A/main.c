#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");

    int a,b,c,d;

    printf("Entre com quatro números interios: ");
        scanf("%d%d%d%d",&a,&b,&c,&d);

    printf("%d + %d = %d\n",a,b,a+b);
    printf("%d + %d = %d\n",a,c,a+c);
    printf("%d + %d = %d\n",a,d,a+d);
    printf("%d + %d = %d\n",b,c,b+c);
    printf("%d + %d = %d\n",b,d,b+d);
    printf("%d + %d = %d\n\n\n",c,d,c+d);

    printf("%d * %d = %d\n",a,b,a*b);
    printf("%d * %d = %d\n",a,c,a*c);
    printf("%d * %d = %d\n",a,d,a*d);
    printf("%d * %d = %d\n",b,c,b*c);
    printf("%d * %d = %d\n",b,d,b*d);
    printf("%d * %d = %d\n",c,d,c*d);

    return 0;
}
