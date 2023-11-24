#include <stdio.h>
#include <stdlib.h>
#include "huffman.c"

// Driver code
int main()
{

    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {20, 23, 11, 24, 9};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}
