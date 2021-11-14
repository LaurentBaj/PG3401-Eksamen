#include <stdio.h>
#include <stdlib.h>
#include "../includes/tools.h"

int main()
{
    FILE *encoded_file, *decoded_file;
    char c1, c2, buffer;
    int left, right, result;

    // Open hex.txt for reading, decoded_file.txt for writing
    encoded_file = fopen("../text/hex.txt", "r");
    decoded_file = fopen("../text/decoded_file.txt", "w");

    //  1. Go through hex.txt
    //  2. For each iteration:
    //    - Get pair of hex-values
    //    - Convert each hex pair into a decimal
    //    - Convert decimal to char + write to file
    if (encoded_file != NULL)
    {
        while (!feof(encoded_file))
        {
            c1 = fgetc(encoded_file);  // left
            c2 = fgetc(encoded_file);  // right
            left = toDecimal(c1) * 16; // account for base
            right = toDecimal(c2);

            result = left + right;
            fprintf(decoded_file, "%c", result); // write to file
        }
    }

    // Close streams
    fclose(encoded_file);
    fclose(decoded_file);
    return 0;
}
