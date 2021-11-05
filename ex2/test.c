#include <stdio.h>
#include <stdlib.h>

int main () {
   int i = 0;
   char c[] = "44"; 
   while (i < 2)
   {
      int a = c[i] - 48; 
      printf("%d", a);
      i++; 
   }
   printf("\n"); 
   
   return(0);
}