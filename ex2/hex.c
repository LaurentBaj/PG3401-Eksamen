#include <stdio.h>
#include <stdlib.h>

// Function that converts a hex to a decimal
// Function is adapted from: https://codescracker.com/c/program/c-program-convert-hexadecimal-to-decimal.htm
int toDecimal(char x)
{
    if(x>='0' && x<='9') return x-'0';
    else if(x>='A' && x<='Z') return x-'A'+10;
    else if(x>='a' && x<='z') return x-'a'+10;
}

int main()
{
    FILE *encoded_file, *decoded_file; 
    char c1, c2, buffer; 
    int left, right, result;

    // Open hex.txt for reading, decoded_file.txt for writing
    encoded_file = fopen("hex.txt", "r");
    decoded_file = fopen("decoded_file.txt", "w"); 

     
    //  1. Go through hex.txt
    //  2. For each iteration: 
    //    - Convert each hex pair to a decimal
    //    - Convert decimal to char + write to file 
    if (encoded_file != NULL)
    {
        while (!feof(encoded_file))
        {   
            // Get pair of hex from hex.txt     
            c1 = fgetc(encoded_file); // left
            c2 = fgetc(encoded_file); // right
            left = toDecimal(c1) * 16; // Account for base of left digit
            right = toDecimal(c2);
            
            result = left + right; 
		    fprintf(decoded_file, "%c", result);
        }
    }
    
    // Close both streams 
    fclose(encoded_file); 
    fclose(decoded_file); 
    return 0; 
}