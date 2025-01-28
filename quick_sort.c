#include<stdio.h>
#include<stdlib.h>

void swap(int *first, int *second){
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

int partition_of_array(int *array, int lower_bound, int upper_bound){
    int pivot = array[lower_bound], start = lower_bound, end = upper_bound;
    while(start<end){
        while(array[start] <= pivot){
            start++;
        }
        while(array[end] > pivot){
            end--;
        }
        if(start < end){
            swap(&array[start], &array[end]);
        }
    }
    swap(&array[lower_bound],&array[end]);
    return end;
}

void quick_sort(int *array, int lower_bound, int upper_bound){
    if(lower_bound < upper_bound){
        int location = partition_of_array(array, lower_bound, upper_bound);
        quick_sort(array,lower_bound,location-1);
        quick_sort(array,location+1,upper_bound);
    }
}

int main(){
    int array_size, lower_bound, upper_bound;
    printf("Enter array size:\n");
    scanf("%d",&array_size);
    int *array = (int *)malloc(array_size * sizeof(int));
    if(!array){
        return 1;
    }
    printf("Enter Array elements:\n");
    for(int index =0 ;index < array_size;index++){
        scanf("%d" , &array[index]);
    }
    lower_bound = 0;
    upper_bound = array_size-1;
    quick_sort(array,lower_bound,upper_bound);
    printf("Array after sorting:\n");
    for(int index =0 ;index < array_size;index++){
        printf("%d " , array[index]);
    }
    free(array);
    return 0;
}