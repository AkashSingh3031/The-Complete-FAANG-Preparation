#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,rem=0,sum=0;
    scanf("%d", &n);	
    while(n!=0){
        rem=n%10;
        sum=sum+rem;
        n=n/10;
    }
    printf("%d",sum);
  return 0;
}

