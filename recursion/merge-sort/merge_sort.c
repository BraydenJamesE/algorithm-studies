#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int*  merge(int* arrOne, int* arrTwo, int sizeOne, int sizeTwo) {
    int* mergedArr = malloc((sizeOne + sizeTwo) * sizeof(int));
    int l = 0;
    int r = 0;
    for (int i = 0; i < sizeOne + sizeTwo; i++) {
        if (l >= sizeOne) 
            mergedArr[i] = arrTwo[r++];
        else if (r >= sizeTwo) 
            mergedArr[i] = arrOne[l++];
        else if (arrOne[l] <= arrTwo[r]) 
            mergedArr[i] = arrOne[l++];   
        else   
            mergedArr[i] = arrTwo[r++];
    }
    return mergedArr;
}

int* mergeSort(int* arr, int size) {
    if (size > 1) {
        int midPoint = size / 2;
        int* arrOne = malloc(midPoint * sizeof(int));
        int* arrTwo = malloc((size - midPoint) * sizeof(int));
        memcpy(arrOne, arr, (midPoint) * sizeof(int)); 
        memcpy(arrTwo, arr + midPoint, (size - midPoint) * sizeof(int));

        int* sortedOne = mergeSort(arrOne, midPoint);
        int* sortedTwo = mergeSort(arrTwo, size - midPoint); 
        int* mergedArr = merge(sortedOne, sortedTwo, midPoint, size - midPoint);

        if (arrOne != sortedOne)
            free(arrOne);
        if (arrTwo != sortedTwo)
            free(arrTwo);
        free(sortedOne);
        free(sortedTwo);

        return mergedArr;
    }
    return arr;
}

int main(int argc, char* argv[]) {
    int unsortedList[] = {10, 2, 30, 4, 5, 6, -1, 40, -2 , 1, 1000, -50, 7};
    int size = sizeof(unsortedList) / sizeof(unsortedList[0]); 
    int* newList = mergeSort(unsortedList, size);
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", newList[i]);
        if (i + 1 < size)
            printf(",");
    }
    printf("]\n");
    free(newList);
    return 0;
}