#include<stdio.h>
#include<stdlib.h>

void convert_zeroes(int** matrix, int *rows, int* columns) {
    int row = *rows, column = *columns,row_index,column_index, row_flag[row], column_flag[column];

    for (row_index =0; row_index<row;row_index++) {
        row_flag[row_index]=0;
    }

    for (column_index =0; column_index<column;column_index++) {
        column_flag[column_index]=0;
    }

    for(row_index =0; row_index<row;row_index++){
         for(column_index =0; column_index<column;column_index++){
            if (matrix[row_index][column_index] == 0) {
                row_flag[row_index]=1;
                column_flag[column_index]=1;
            }
        }
    }

    for(row_index =0; row_index<row;row_index++){
        if(row_flag[row_index]==1)
         for(column_index =0; column_index<column;column_index++){
                matrix[row_index][column_index] = 0;
        }
    }

    for(column_index =0; column_index<column;column_index++){
        if(column_flag[column_index]==1)
         for(row_index =0; row_index<row;row_index++){
                matrix[row_index][column_index] = 0;
        }
    }
}

void print_array(int** matrix, int rows, int columns) {
    for(int row_index =0; row_index<rows;row_index++){
         for(int column_index =0; column_index<columns;column_index++){
            printf("%d ", matrix[row_index][column_index]);
        }
        printf("\n");
    }
}

int main() {
    int rows,columns;
    printf("Enter rows and columns :\n");
    scanf("%d %d",&rows,&columns);    
    int **input_matrix= (int **)malloc(rows *sizeof(int *));
    for(int index=0;index<rows;index++){
        input_matrix[index] = (int *)malloc(columns*sizeof(int));
    }
    printf("Enter 2d array elements:\n");
    for(int row_index =0; row_index<rows;row_index++){
        for(int column_index =0; column_index<columns;column_index++){
            scanf("%d",&input_matrix[row_index][column_index]);
        }
    }
    printf("Matrix is:\n");
    print_array(input_matrix, rows, columns);
    convert_zeroes(input_matrix, &rows, &columns);
    printf("Output Matrix:\n");
    print_array(input_matrix, rows, columns);
    free(input_matrix);
    return 0;
}