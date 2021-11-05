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
    FILE *encoded_file, *decoded_file; 
    char c[2], buffer; 

    // Open hex.txt for reading - decoded_file.txt for writing
    encoded_file = fopen("hex.txt", "r");
    decoded_file = fopen("decoded_file.txt", "w"); 

    if (encoded_file != NULL)
    {
        /*
            Go through hex.txt
            For each iteration: 
                - Convert each hex pair to a decimal
                - Convert decimal to char + write to file 
        */
        while (!feof(encoded_file))
        {        
            
            c[0] = fgetc(encoded_file);
            c[1] = fgetc(encoded_file);
            int left = getDec(c[0]) * 16; 
            int right = getDec(c[1]);

            buffer = left + right; 
            //printf("%c", buffer); 
		    fwrite (&buffer, sizeof(char), 1, decoded_file);
        }
    }
    fclose(encoded_file); 
    fclose(decoded_file); 
}