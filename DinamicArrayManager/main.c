#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrayOperations.c"

int main() {
   
    srand(time(NULL));

    size_t len;

    system("clear || cls");
    printf("How many elements? ");
    scanf("%lu", &len);
    system("clear || cls");

    int *arr = (int *) malloc(len * sizeof(int));

    loadArray(arr, len);
    printf("Array before sorting\n");
    printArray(arr, len);
    printf("\n\nArray after sorting\n");
    sortArray(arr, len);
    printArray(arr, len);
    printf("\n\n");

    int ch;

    do{
        
        printf("0 - Exit\n");
        printf("1 - Search an element\n");
        printf("2 - Print array\n");
        scanf("%d", &ch);

        switch (ch) {
            
            case 1:{
                int el;
                system("clear || cls");
                printf("Insert the element: ");
                scanf("%d", &el);
                int **arrPtr = &arr;
                len = searchElement(arrPtr, len, el);
                break;
            }
            case 2:{
                system("clear || cls");
                printArray(arr, len);
                break;
            }

        }

        puts("");


    }while (ch != 0 && len > 0);

    puts("");










}
