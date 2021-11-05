#include <stdio.h>


void print_char_occurence(FILE *file);


int main()
{
	FILE* file;
    print_contents(file); 
}

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
