#include <stdio.h>

int main(int argc, char *argv[]) {
    int unsortedList[] = {10, 2, 30, 4, 5, 6, -1, 40, -2 , 1, 1000, -50, 7};
    int len = sizeof(unsortedList) / sizeof(unsortedList[0]); 
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d", unsortedList[i]);
        if (i + 1 < len)
            printf(",");
    }
    printf("]\n");
    return 0;
}