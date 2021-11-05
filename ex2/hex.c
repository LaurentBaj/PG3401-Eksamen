#include <stdio.h>
#include <stdlib.h>


int getDec(int x)
{
    int val = 0;
    if(x>='0' && x<='9')
    {
        val = x - 48;
    }
    else if(x>='a' && x<='f')
    {
        val = x - 97 + 10;
    }
    else if(x>='A' && x<='F')
    {
        val = x - 65 + 10;
    }
    return val; 
}

int main()
{
    FILE *f; 
    char c[2]; 

    f = fopen("hex.txt", "r");
    while (!feof(f))
    {
        c[0] = fgetc(f);
        c[1] = fgetc(f);
        int left = getDec(c[0]) * 16; 
        int right = getDec(c[1]); 
        printf("%c", left + right);
    }
    fclose(f); 
}