#include<stdio.h>
#include<stdlib.h>

void swap(int *first, int *second){
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

void bubble_sort(int *array, int array_size){
    for(int row_index = 0; row_index < array_size-1 ; row_index++){
        int flag_to_avoid = 0;
        for(int column_index =0;column_index < array_size - 1 - row_index; column_index++){
            if(array[column_index] > array[column_index + 1]){
                swap(&array[column_index], &array[column_index +1]);
                flag_to_avoid =1;
            }
        }
        if(!flag_to_avoid){
            break;
        }
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
    printf("Enter Array Elements:\n");
    for(int index =0;index < array_size;index ++){
        scanf("%d",&array[index]);
    }
    bubble_sort(array,array_size);
    printf("Array after sorting:\n");
    for(int index =0;index < array_size;index ++){
        printf("%d ",array[index]);
    }
    free(array);
    return 0;
}