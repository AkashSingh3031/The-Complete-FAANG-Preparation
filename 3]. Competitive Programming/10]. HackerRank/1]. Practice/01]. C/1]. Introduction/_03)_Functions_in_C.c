#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int main() 
{
    int a, b, c, d,y;
    scanf("%d\n",&a);
     scanf("%d\n",&b);
      scanf("%d\n",&c);
     scanf("%d",&d);
     
     if (a>b && a>c && a>d){
      if (b<c && b<d){
        y = b;
      }
      else if (c<b && c<d){
        y = c;
      }
      else if (d<b && d<c){
        y = d;
      }

      printf("%d\n", a);
      
    }
    else if (b>a && b>c && b>d) {
      if (a<c && a<d){
        y = a;
      }
      else if(c<a && c<d){
        y = c;
      }
      else if(d<a && d<c){
        y = d;
      }

      printf("%d\n", b);
    }
    else if (c>a && c>b && c>d)
    {
      if (a<b && a<d){
        y = a;
      }
      else if(b<a && b<d){
        y = b;
      }
      else if(d<a && d<b){
        y = d;
      }

      printf("%d\n", c);
     
    }
    else if (d>a && d>b && d>c) {
      if (a<b && a<c){
        y = a;
      }
    else if(b<a && b<c){
      y = b;
    }
    else if(c<a && c<b){
      y = c;
    }

    printf("%d\n", d);
   
  }

  return 0; 
}

