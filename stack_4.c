#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_total_sub_array(int *array,int array_size,int k){
    if(k==0){
        return 1;
    }
    int left =0,count =0;
    int max;
    for(int i=0;i<array_size;i++){
        max = array[i];
        if(array[i]>max){
            max = array[i];
        }
    }
    int *frequecy_array = (int *)calloc((max+1) , sizeof(int));
    if(!frequecy_array){
        return 0;
    }
    for(int right =0;right<array_size;right++){
        if(frequecy_array[array[right]] ==0){
            k--;
        }
        frequecy_array[array[right]]++;
        while(k<0){
            frequecy_array[array[left]]--;
            if(frequecy_array[array[left]] == 0){
                k++;
            }
            left++;
        }
        count = count + (right - left + 1);
    }
    return count;
}

int main(){
    int array_size;
    scanf("%d",&array_size);
    int *array = (int *)malloc(array_size * sizeof(int));
    if(!array){
        return 1;
    }
    for(int i =0;i<array_size;i++){
        scanf("%d",&array[i]);
    }
    int k;
    scanf("%d",&k);
    
    if(k==0){
        return 0;
    }
    int result = count_total_sub_array(array,array_size,k)-count_total_sub_array(array,array_size,k-1);
    printf("%d\n",result);
    return 0;
}

