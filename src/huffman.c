#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MinHeap.c"

struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    while (!isSizeOne(minHeap)) {
        struct MinHeapNode *left = extractMin(minHeap);
        struct MinHeapNode *right = extractMin(minHeap);

        struct MinHeapNode *top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {
        printf("Data: %c | Frequency: %d | Huffman Encoding: ", root->data, root->frequency);
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printf("Huffman Coding:\n");
    printCodes(root, arr, top);
}

