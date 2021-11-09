#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "includes/tools.h"

void welcome_msg();

int main()
{
    // Initialize shopping cart (dll)
    Node *tail = NULL;
    Node *head = NULL;
    init(&tail, &head, 0);

    // Buffers
    char buffer, *b_name;
    float b_price, sum;
    int b_count;

    welcome_msg();

    // Program
    do
    {
        printf("\nEnter action: ");
        scanf("%c", &buffer);

        if (buffer == 'a')
        {
            printf("\nEnter product name: ");
            scanf("%s", b_name);
            printf("Enter price: ");
            scanf("%f", &b_price);
            printf("Enter amount: ");
            scanf("%d", &b_count);

            append(&head, b_price, b_name, b_count);
            printf("%dx - %s has been added to list\n", b_count, b_name);
        }
        else if (buffer == 'r')
        {
            remove_last(&head);
        }
        /* 
        else if (buffer == 'x') 
        {
            remove_last(&head);
        }*/
    } while (buffer != 'q');

    // Create receipt + free heap
    print_dll(tail);
    deallocate(&tail, &head);
    return 0;
}

void welcome_msg()
{
    printf("Welcome to this emulated online store!\n");
    printf("Enter 'a' to add item to cart, 'r' to remove last added item\n");
    printf("Enter 'q' to get the receipt of purchase\n\n");
}