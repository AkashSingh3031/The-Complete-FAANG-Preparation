#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,c,d;
    
    scanf("%d", &a);
    scanf("%d", &b);
    c=a+b;
    d=a-b;
    printf("%d\n",c);
    if(d<0){
        d=-1*d;
        printf("%d",d);
    }
    else
      printf("%d",d);

    return 0;
}

