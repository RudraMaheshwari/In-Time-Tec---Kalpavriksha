#include<stdio.h>
#include<stdlib.h>

void swap(int *first, int *second){
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

void bubble_sort(int *array, int array_size){
    for(int row_index =0;row_index<array_size-1;row_index++){
        for(int column_index =0;column_index <array_size-1-row_index;column_index++){
            if(array[column_index] > array[column_index+1]){
                swap(&array[column_index], &array[column_index+1]);
            }
        }
    }
}

void two_pointer_technique(int *array, int array_size, int target){
    int left =0, right = array_size- 1,found =0;
    while(left < right){
        if(array[left] == target || array[right] == target){
            printf("Element Found.\n");
            found =1;
            break;
        } else{
            left++;
            right--;
        }
    }
    if(!found){
        printf("Element not present.\n");
    }
}

int main(){
    int array_size,target;
    printf("Enter array size:\n");
    scanf("%d", &array_size);
    int *array = (int *)malloc(array_size * sizeof(int));
    if(!array){
        return 1;
    }
    printf("Enter Array Elements:\n");
    for(int index =0;index< array_size ; index++){
        scanf("%d",&array[index]);
    }
    printf("Enter target value:\n");
    scanf("%d",&target);
    bubble_sort(array,array_size);
    two_pointer_technique(array,array_size,target);
    free(array);
    return 0;
}