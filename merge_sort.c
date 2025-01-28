#include<stdio.h>
#include<stdlib.h>

void merge(int *array, int lower_bound, int mid, int upper_bound){
    int start = lower_bound, new_pointer = lower_bound, end = mid+1;
    int result[1000];
    while(start <= mid && end <= upper_bound){
        if(array[start] <= array[end] ){
            result[new_pointer] = array[start];
            start++;
        } else{
            result[new_pointer] = array[end];
            end++;
        }
        new_pointer++;
    }
    if(start>mid){
        while(end <= upper_bound){
            result[new_pointer] = array[end];
            end++;
            new_pointer++;
        }
    } else{
        while(start <= mid){
            result[new_pointer] = array[start];
            start++;
            new_pointer++;
        }
    }
    for(int index =lower_bound;index<= upper_bound;index++){
        array[index] = result[index];
    }
}

void merge_sort(int *array, int lower_bound, int upper_bound){
    if(lower_bound < upper_bound){
        int mid = (lower_bound+ upper_bound)/2;
        merge_sort(array, lower_bound, mid);
        merge_sort(array,mid+1,upper_bound);
        merge(array,lower_bound,mid,upper_bound);
    }
}

int main(){
    int array_size, lower_bound = 0, upper_bound;
    printf("Enter Array Size:\n");
    scanf("%d",&array_size);
    int *array = (int *)malloc(array_size * sizeof(int));
    if(!array){
        return 1;
    }
    printf("Enter Array Elements:\n");
    for(int index =0;index < array_size;index++){
        scanf("%d", &array[index]);
    }
    upper_bound = array_size-1;
    merge_sort(array,lower_bound,upper_bound);
    printf("Array after sorting:\n");
    for(int index =0;index < array_size;index++){
        printf("%d ", array[index]);
    }
    free(array);
    return 0;
}