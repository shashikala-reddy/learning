 //Write a C program to get lowest set bit of a number.

#include <stdio.h>
#define INT_SIZE sizeof(int) * 8 /* Integer size in bits */

int main()
{
    int num, order, i;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Initially set the order to max size of integer */
    order = INT_SIZE - 1;

    /* Iterate through each bit of integer */
    for(i=0; i<INT_SIZE; i++)
    {
        /* If current bit is set */
        if((num>>i) & 1)
        {
            order = i;

            /* Terminate the loop */
            break;
        }
    }

    printf("Lowest order set bit in %d is %d", num, order);

    return 0;
}
