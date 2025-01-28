#include<stdio.h>
#include<stdlib.h>

void swap(int *first, int *second){
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

void selection_sort(int *array, int array_size){
    for(int row_index =0;row_index<array_size -1;row_index++){
        int minimum = row_index;
        for(int column_index = row_index+1; column_index<array_size;column_index++){
            if(array[column_index]< array[minimum]){
                minimum = column_index;
            }
        }
        if(minimum != row_index){
            swap(&array[row_index], &array[minimum]);
        }
    }
}

int main(){
    int array_size;
    printf("Enter Array Size:\n");
    scanf("%d",&array_size);
    int *array = (int *)malloc(array_size * sizeof(int));
    if(!array){
        return 1;
    }
    printf("Enter Array Elements:\n");
    for(int index =0;index<array_size;index++){
        scanf("%d",&array[index]);
    }
    selection_sort(array,array_size);
    printf("Array after sorting:\n");
    for(int index =0;index<array_size;index++){
        printf("%d ",array[index]);
    }
    free(array);
    return 0;
}