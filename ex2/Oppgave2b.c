#include <stdio.h>


int main()
{
	FILE* file = fopen("encoded_text.txt", "r");
    char array[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    
    /*if (file != NULL)
    {
        while ((buff = fgetc(file)) != EOF) 
        {
            putchar(buff);
        }
    } */

    int i, j, len = sizeof(array); 
    for (i = 0; i < len; i++)
    {
        int counter = 0; 
        for (j = 0; j < len; j++)
        {
            if (array[j] == array[i])
            {
                counter++;         
            }
        } 
        printf("%c occured: %d times\n", array[i], counter); 
    }
}