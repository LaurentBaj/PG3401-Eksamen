#include <stdio.h>


int main()
{
    FILE* file1 = fopen("encoded_text.txt", "r");
    FILE* file2 = fopen("decoded_text.txt", "w");
    char c; 

   if (file1 != NULL)
	{
		file2 = fopen ("decoded_text.txt", "w");
		while (!feof(file1))
		{
			if (fscanf(file1, "%c", &c) == 1)
			{
				fwrite (&c, sizeof(char), 1, file2); 
			}
		}
		fclose (file2); 
	}	
	fclose (file1); 
}