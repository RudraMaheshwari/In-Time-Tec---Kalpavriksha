#include<stdio.h>
#include<stdlib.h>

void swap(int *first, int *second){
    int temporary = *first;
    *first= *second;
    *second = temporary;
}

void bubble_sort(int *array,int array_size){
    for(int row_index =0 ; row_index<array_size ; row_index++){
        for(int column_index=0 ; column_index<array_size - row_index - 1;column_index++){
            if(array[column_index]>array[column_index+1]){
                swap(&array[column_index],&array[column_index+1]);
            }
        }
    }
}

void print_array(int *array,int array_size){
    for(int index =0;index<array_size;index++){
        printf("%d ",array[index]);
    }
    printf("\n");
}

void generate_subsets(int *array, int array_size,int target,int *subset_array,int start_index,int subset_size){
    int sum =0;
    for(int index =0;index<subset_size;index++){
        sum = sum + subset_array[index];
    }

    if(target == sum){
        print_array(subset_array,subset_size);
    }
    
    if(start_index == array_size){
        return;
    }
    for(int index = start_index ; index<array_size;index++){
        if(index> start_index && array[index] == array[index - 1]){
            continue;
        }
        subset_array[subset_size] = array[index];
        generate_subsets(array,array_size,target,subset_array,index+1,subset_size+1);
    }
}

void create_subsets(int *array,int array_size,int target){
    int *subset_array = (int *)malloc(array_size* sizeof(subset_array));
    if(!subset_array){
        return;
    }
    generate_subsets(array,array_size,target,subset_array,0,0);
    free(subset_array);
}

int main(){
    int array_size, target;
    printf("Enter array size:\n");
    scanf("%d",&array_size);
    int *integer_array = (int *)malloc(array_size * sizeof(int));
    if(!integer_array){
        return 1;
    }
    printf("Enter Array Elements:\n");
    for(int index = 0;index<array_size;index++){
        scanf("%d",&integer_array[index]);
    }
    bubble_sort(integer_array,array_size);
    printf("Array Elements are:\n");
    for(int index = 0;index<array_size;index++){
        printf("%d ", integer_array[index]);
    }
    printf("\nEnter target sum:\n");
    scanf("%d",&target);
    printf("Subsets are:\n");
    create_subsets(integer_array,array_size,target);
    free(integer_array);
    return 0;
}