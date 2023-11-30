#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.c"

int main() {
    char input[MAX_TREE_HT];
    printf("Text: ");
    scanf("%s", input);

    int frequencyTable[256] = {0};

    int len = strlen(input);
    for (int i = 0; i < len; ++i)
        ++frequencyTable[input[i]];

    int size = 0;
    for (int i = 0; i < 256; ++i) {
        if (frequencyTable[i] > 0)
            size++;
    }

    char data[size];
    int frequency[size];
    int j = 0;

    for (int i = 0; i < 256; ++i) {
        if (frequencyTable[i] > 0) {
            data[j] = i;
            frequency[j] = frequencyTable[i];
            j++;
        }
    }

    HuffmanCodes(data, frequency, size);

    return 0;
}
