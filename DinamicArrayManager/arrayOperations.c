#include <stdio.h>
#include <stdlib.h>

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *array, size_t length) {
    for(size_t i = 0; i < length; i++) {
        printf("%d ", *array++);
    }
}

void loadArray(int *array, size_t length) {
    for (size_t i = 0; i < length; i++) {
        *array++ = (rand() % 101) - 30;
    }
}

void sortArray(int *array, size_t length) {
    for (size_t i = 0; i < length - 1; i++) {
        for(size_t j = 0; j < length - i - 1; j++) {
            if(* (array + j) > * (array + (j + 1))) {
                swap(array + j, array + (j + 1));
            }
        }
    }
}

int deleteElement(int **arrayPtr, size_t length, int element) {
    
    int cpyArray[length - 1];
    int *tempAddress = *arrayPtr;
    size_t j = 0;

    for (size_t i = 0; i < length; *arrayPtr += 1, i++) {
        if (*(*arrayPtr) != element) {
            cpyArray[j] = *(*arrayPtr);
            j++;
        }
    }

    puts("");
    
    free(tempAddress);
    *arrayPtr = (int *) malloc(j * sizeof(int));

    size_t i;

    for (i = 0; i < j; *arrayPtr += 1, i++) {
        *(*arrayPtr) = cpyArray[i];
    } 

    *arrayPtr = *arrayPtr - i;

    return j; 

}

int searchElement(int **arrayPtr, size_t length, int element) {

    int present = 0;
    size_t i;
    
    for (i = 0; i < length; *arrayPtr += 1, i++) {
        if (element == *(*arrayPtr)) {
            present = 1;
            break;
        }
    }

    *arrayPtr = *arrayPtr - i;
    
    return present ? deleteElement(arrayPtr, length, element) : length;


}