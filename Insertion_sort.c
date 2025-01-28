#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int *array,int array_size){
    for(int index =1; index<array_size;index++){
        int temporary = array[index];
        int iterator_2 = index - 1;
        while(iterator_2>= 0 && array[iterator_2] > temporary){
            array[iterator_2+1] = array[iterator_2];
            iterator_2--;
        }
        array[iterator_2 + 1] = temporary;
    }
}

int main(){
    int array_size;
    printf("Enter array size:\n");
    scanf("%d",&array_size);
    int *array = (int *)malloc(array_size * sizeof(int));
    if(!array){
        return 1;
    }
    printf("Enter array elements:\n");
    for(int index = 0;index<array_size;index++){
        scanf("%d",&array[index]);
    }
    insertion_sort(array,array_size);
    printf("Array after sorting:\n");
    for(int index = 0;index<array_size;index++){
        printf("%d ",array[index]);
    }
    free(array);
    return 0;
}