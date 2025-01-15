#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int **array, int array_size){
    for(int row_index=0;row_index<array_size;row_index++){
        for(int column_index=0;column_index<array_size-1-row_index; column_index++){
            if(array[column_index][0]>array[column_index+1][0]){
                int temporary_start = array[column_index][0];
                int temporary_end = array[column_index][1];
                array[column_index][0]=array[column_index+1][0];
                array[column_index][1]=array[column_index+1][1];
                array[column_index+1][0]=temporary_start;
                array[column_index+1][1]=temporary_end;
            }
        }
    }
}

int merge_intervals(int **intervals, int intervals_size, int result[][2]) {
    bubble_sort(intervals, intervals_size);
    int index = 0;
    result[index][0] = intervals[0][0];
    result[index][1] = intervals[0][1];
    for (int iterator = 1; iterator < intervals_size; iterator++) {
        if (intervals[iterator][0] <= result[index][1]) {
            result[index][1] = (result[index][1] > intervals[iterator][1]) ? result[index][1] : intervals[iterator][1];
        } else {
            index++;
            result[index][0] = intervals[iterator][0];
            result[index][1] = intervals[iterator][1];
        }
    }
    return index + 1;
}

void print_intervals(int intervals[][2], int size) {
    for (int index = 0; index < size; index++) {
        printf("[%d, %d] ", intervals[index][0], intervals[index][1]);
    }
    printf("\n");
 }

int main() {
    int rows,columns=2;
    printf("Enter no of Row:\n");
    scanf("%d",&rows);
    int **intervals = (int **)malloc(rows * sizeof(int*));
    for(int index=0;index<rows;index++){
        intervals[index]= (int *)malloc(columns * sizeof(int));
    }
    printf("Enter 2D array elements:\n");
    for(int row_index=0;row_index<rows;row_index++){
        for(int column_index=0;column_index<columns;column_index++){
            scanf("%d",&intervals[row_index][column_index]);
        }
    }
    
    int intervals_size = rows;
    int merged_intervals[rows][columns];
    int return_size = merge_intervals(intervals, intervals_size, merged_intervals);
    printf("Merged Intervals: ");
    print_intervals(merged_intervals, return_size);
    free(intervals);
    return 0;
}