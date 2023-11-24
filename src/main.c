#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.c"

#define MAX_SIZE 100

int main()
{
    char arr[MAX_SIZE][MAX_SIZE];
    int freq[MAX_SIZE];

    int i = 0;
    while (i < MAX_SIZE)
    {
        printf("%d:", i+1);
        printf("Data was built SUCCESSFULLY! \nPlease enter text to represent a data: ");
        scanf("%s", arr[i]);
        printf("Please enter number to input a data: ");
        scanf("%d", &freq[i]);
        printf("\n");

        char scanner;
        int check;
        printf("If you want to build another data, then continue (Y/n): ");
        scanf(" %c", &scanner);

        if (scanner != 'Y' && scanner != 'y'){
            break;
        }
        i++;
        printf("--------------------------------------------------------\n");
    }

    int size = i + 1;

    HuffmanCodes((char **)arr, freq, size);
    return 0;
}
