#include <stdio.h>

int main ()
{
    FILE* ft = NULL;  
    int num = 0; 
    char c[2];

    ft = fopen ("text_d.txt", "r");
	if (ft != NULL)
	{
		while (!feof(ft))
        {
            c[0] = fgetc(ft); 
            c[1] = fgetc(ft);
            printf("%s\n", c); 
        }
	}	    
	fclose (ft); 

    printf("\n"); 
}

