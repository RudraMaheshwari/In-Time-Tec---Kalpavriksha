#include<stdio.h>
#include<stdlib.h>

int binary_search(int *array, int array_size , int target){
    int left = 0, right = array_size -1;
    while(left<=right){
        int mid_element = (left + right)/2;
        if(target == array[mid_element]){
            return mid_element;
        } else if(target < array[mid_element]){
            right = mid_element -1;
        } else{
            left = mid_element+1;
        }
    }
    return -1;
}

int main(){
    int array_size,target_value;
    printf("Enter array size:\n");
    scanf("%d",&array_size);
    int *array = (int *)malloc(array_size * sizeof(int));
    if(!array){
        return 1;
    }
    printf("Enter Array elements:\n");
    for(int index =0;index<array_size;index++){
        scanf("%d",&array[index]);
    }
    getchar();
    printf("Enter data you want to find:\n");
    scanf("%d",&target_value);
    int result = binary_search(array,array_size,target_value);
    if(result != -1){
        printf("Element found.\n");
    } else{
        printf("Element not found.\n");
    }
    free(array);
    return 0;
}