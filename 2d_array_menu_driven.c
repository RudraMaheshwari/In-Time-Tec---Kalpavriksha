#include<stdio.h>
#include<stdlib.h>

void swap(int *first_element, int *second_variable){
    int temporary_element;
    temporary_element=*first_element;
    *first_element=*second_variable;
    *second_variable=temporary_element;
}

void matrix_level_rotation(int **matrix,int array_size){
    for(int row_index=0; row_index < array_size; row_index++){
        for(int column_index=row_index+1;column_index< array_size;column_index++){
            swap(&matrix[row_index][column_index],&matrix[column_index][row_index]);
        }
    }
    for(int row_index=0; row_index < array_size; row_index++){
        for(int column_index=0;column_index< array_size/2;column_index++){
            swap(&matrix[row_index][column_index],&matrix[row_index][array_size - 1 - column_index]);
        }
    }
}

void row_wise_left(int **matrix, int array_size, int no_of_times) {
   no_of_times %= array_size;
   for (int row_index = 0; row_index < array_size; row_index++) {
       for (int traverse = 0; traverse < no_of_times; traverse++) {
           int first_element = matrix[row_index][0];
           for (int column_index = 0; column_index < array_size - 1; column_index++) {
               matrix[row_index][column_index] = matrix[row_index][column_index + 1];
           }
           matrix[row_index][array_size - 1] = first_element;
       }
   }
}

void row_wise_right(int **matrix, int array_size, int no_of_times) {
   no_of_times %= array_size;
   for (int row_index = 0; row_index < array_size; row_index++) {
       for (int traverse = 0; traverse < no_of_times; traverse++) {
           int last_element = matrix[row_index][array_size - 1];
           for (int column_index = array_size - 1; column_index > 0; column_index--) {
               matrix[row_index][column_index] = matrix[row_index][column_index - 1];
           }
           matrix[row_index][0] = last_element;
       }
   }
}

void column_wise_up(int **matrix, int array_size, int no_of_times) {
   no_of_times %= array_size;
   for (int column_index = 0; column_index < array_size; column_index++) {
       for (int traverse = 0; traverse < no_of_times; traverse++) {
           int first_element = matrix[0][column_index];
           for (int row_index = 0; row_index < array_size - 1; row_index++) {
               matrix[row_index][column_index] = matrix[row_index + 1][column_index];
           }
           matrix[array_size - 1][column_index] = first_element;
       }
   }
}


void column_wise_down(int **matrix, int array_size, int no_of_times) {
   no_of_times %= array_size;
   for (int column_index = 0; column_index < array_size; column_index++) {
       for (int traverse = 0; traverse < no_of_times; traverse++) {
           int last_element = matrix[array_size - 1][column_index];
           for (int row_index = array_size - 1; row_index > 0; row_index--) {
               matrix[row_index][column_index] = matrix[row_index - 1][column_index];
           }
           matrix[0][column_index] = last_element;
       }
   }
}


void display_matrix(int **matrix, int array_size){
    int row_index, column_index;
    for( row_index=0; row_index < array_size; row_index++){
        for(column_index=0;column_index< array_size;column_index++){
            printf("%d ", matrix[row_index][column_index]);
        }
        printf("\n");
    }
}

int main(){
    int array_size, row_index, column_index, choice, steps;
    printf("Enter the size of array [size * size]:\n");
    scanf("%d", &array_size);
    int **matrix = (int **)malloc(array_size * sizeof(int *));
    for (int index=0;index<array_size;index++)
    {
        matrix[index]=(int *)malloc(array_size * sizeof(int));
    }
    printf("Enter Array Elements:\n");
    for( row_index=0; row_index < array_size; row_index++){
        for(column_index=0;column_index< array_size;column_index++){
            scanf("%d", &matrix[row_index][column_index]);
        }
    }

    printf("2D Array is: \n");
    display_matrix(matrix,array_size);

    while(1){
        printf("********Array Rotation Program********\n");
        printf("1.Matrix-Level Rotation(90 degree clockwise.).\n");
        printf("2.Row-Wise Rotation (Left).\n");
        printf("3.Row-Wise Rotation (Right).\n");
        printf("4.Column-Wise Rotation (Up).\n");
        printf("5.Column-Wise Rotation (Down).\n");
        printf("6.Exit the program.\n");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
               matrix_level_rotation(matrix, array_size);
               printf("Matrix after 90-degree rotation:\n");
               display_matrix(matrix, array_size);
               break;
            case 2:
               printf("Enter the no. of steps to rotate left(rows): ");
               scanf("%d", &steps);
               row_wise_left(matrix, array_size, steps);
               printf("Matrix after row-wise left rotation:\n");
               display_matrix(matrix, array_size);
               break;
            case 3:
               printf("Enter the no. of steps to rotate rigth(rows): ");
               scanf("%d", &steps);
               row_wise_right(matrix, array_size, steps);
               printf("Matrix after row-wise right rotation:\n");
               display_matrix(matrix, array_size);
               break;
            case 4:
               printf("Enter the no. of steps to rotate up(column): ");
               scanf("%d", &steps);
               column_wise_up(matrix, array_size, steps);
               printf("Matrix after column wise up rotation:\n");
               display_matrix(matrix, array_size);
               break;
            case 5:
               printf("Enter the no. of steps to rotate down(column): ");
               scanf("%d", &steps);
               column_wise_down(matrix, array_size, steps);
               printf("Matrix after column wise Down rotation:\n");
               display_matrix(matrix, array_size);
               break;
            case 6: 
               for (int i = 0; i < array_size; i++) {
                free(matrix[i]);
               }
               free(matrix);
               printf("Program Exited.\n");
               return 0;
            default: printf("Invalid Choice\n\n");
        }
    }
    return 0;    
}
