#include<stdio.h>
#include<stdlib.h>

int diagonal_sum(int **input_array, int size){
    int sum =0;
    for(int index=0;index<size;index++){
        if(index == size-1-index)
        {
            sum += (input_array[index][index]);
        }
        else
        {
            sum += (input_array[index][index]+input_array[index][size-1-index]);
        }
    }
    return sum;
}

int main(){
    int size;
    printf("Enter size of Array:\n");
    scanf("%d", &size);

    int **input_array = (int **)malloc(size*sizeof(int *));
    printf("Enter 2D Array Elements:\n");
    for(int row_index =0; row_index< size;row_index++){
        input_array[row_index] = (int *)malloc(size*sizeof(int));
        for(int column_index =0; column_index<size;column_index++){
            scanf("%d", &input_array[row_index][column_index]);
        }
    }
    
    printf("2D Array Elements:\n");
    for(int row_index =0; row_index< size;row_index++){
        for(int column_index =0; column_index<size;column_index++){
            printf("%d ", input_array[row_index][column_index]);
        }
        printf("\n");
    }

    int sum_of_diagonals = diagonal_sum(input_array,size);
    printf("Sum of Diagonals is: %d\n",sum_of_diagonals);
    return 0;
}