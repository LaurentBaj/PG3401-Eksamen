#include <stdio.h>


void print_char_occurence(FILE *file)
{
    char arrayS[] = "abcdefghijklmnopqrstuvwxyzæøå"; 
    char arrayB[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ"; 
    int i, counter;
    char a; 
 
    file = fopen("fasit.txt", "r"); 
    if (file != NULL)
    { 
        for (i = 0; i < sizeof(arrayB) - 7; i++)
        {
            counter = 0; 
            while ((a = getc(file)) != EOF)
            {
                if (a == arrayB[i] || a == arrayS[i]) 
                {
                    counter++;
                }      
            }

            printf("The letters: %c%c: appeared %d times\n", arrayB[i], arrayS[i], counter); 
            rewind(file);
        }   
    }
    fclose(file); 
}


// Function that converts hex value to a decimal
// Function is adapted from: https://codescracker.com/c/program/c-program-convert-hexadecimal-to-decimal.htm
int toDecimal(char x)
{
    if(x>='0' && x<='9') return x-'0';
    else if(x>='A' && x<='Z') return x-'A'+10;
    else if(x>='a' && x<='z') return x-'a'+10;
}