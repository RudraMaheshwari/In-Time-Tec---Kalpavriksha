#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter size:\n");
    scanf("%d", &size);

    int **array = (int **)malloc(size * sizeof(int *));
    for (int index = 0; index < size; index++)
    {
        array[index] = (int *)malloc(size * sizeof(int));
    }
    printf("Enter Matrix Element:\n");
    for(int row_index = 0; row_index < size; row_index++)
    {
        for(int column_index = 0; column_index < size; column_index++)
        {
            scanf("%d", &array[row_index][column_index]);
        }
    }
    printf("2D Array:\n");
    for(int row_index = 0; row_index < size; row_index++)
    {
        for(int column_index = 0; column_index < size; column_index++)
        {
            printf("%d ", array[row_index][column_index]);
        }
        printf("\n");
    }
    for(int row_index = 0; row_index < size; row_index++)
    {
        for(int column_index = 0; column_index < size; column_index++)
        {
            int temporary = array[row_index][column_index];
            array[row_index][column_index] = array[column_index][row_index];
            array[column_index][row_index] = temporary;
        }
    }
    printf("New array is:\n");
    for(int row_index = 0; row_index < size; row_index++)
    {
        for(int column_index = 0; column_index < size; column_index++)
        {
            printf("%d ", array[row_index][column_index]);
        }
        printf("\n");
    }
    for(int index = 0; index < size; index++)
    {
        free(array[index]);
    }
    free(array);
    return 0;
}
