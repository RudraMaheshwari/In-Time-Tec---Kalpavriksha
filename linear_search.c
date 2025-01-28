#include<stdio.h>
#include<stdlib.h>

void linear_search(int *array,int array_size,int target_value){
    int found= 0;
    for(int index = 0 ; index<array_size;index++){
        if(array[index] == target_value){
            printf("Element found at %d.\n",index+1);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Element not present.\n");
    }
}

int main(){
    int array_size,target_value;
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
    printf("Enter element you want to find:\n");
    scanf("%d",&target_value);
    linear_search(array,array_size,target_value);
    free(array);
    return 0;
}