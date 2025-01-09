#include <stdio.h>
#include <stdlib.h>
#define MAXIMUM_STRING_LENGTH 51
#define MAXIMUM_MAP_SIZE 100

typedef struct{
    char *name;
    int count;
}Map;

int compare_strings(char *string1, char *string2) {
    int index = 0;
    while (string1[index] != '\0' && string2[index] != '\0') {
        char c1 = string1[index];
        char c2 = string2[index];
        
        if (c1 >= 'A' && c1 <= 'Z') 
            c1 += ('a' - 'A');
        if (c2 >= 'A' && c2 <= 'Z') 
            c2 += ('a' - 'A');
        if (c1 != c2) {
            return 0;
        }
        index++;
    }
    return (string1[index] == '\0' && string2[index] == '\0'); 
}

void copy_string(char *destination, char *source) {
    int index = 0;
    while (source[index] != '\0') {
        destination[index] = source[index];
        index++;
    }
    destination[index] = '\0'; 
}

void read_input(int rows, int columns, char (*fruit_array)[columns][MAXIMUM_STRING_LENGTH + 1]) {
    for (int row_index = 0; row_index < rows; row_index++) {
        for (int column_index = 0; column_index < columns; column_index++) {
            scanf("%s", fruit_array[row_index][column_index]);
        }
    }
}

void print_array(int rows, int columns, char (*fruit_array)[columns][MAXIMUM_STRING_LENGTH + 1]) {
    for (int row_index = 0; row_index < rows; row_index++) {
        for (int column_index = 0; column_index < columns; column_index++) {
            printf("%s ", fruit_array[row_index][column_index]);
        }
        printf("\n");
    }
}

int searching_map(Map map[] , char *name, int map_size){
    for(int index=0; index<map_size; index++){
        if(compare_strings(map[index].name,name)==1){
            return index;
        }
    }
    return -1;
}

int process_map(int rows, int columns, char (*fruit_array)[columns][MAXIMUM_STRING_LENGTH + 1], Map *map, int *map_size) {
    for (int row_index = 0; row_index < rows; row_index++) {
        for (int column_index = 0; column_index < columns; column_index++) {
            int index = searching_map(map, fruit_array[row_index][column_index], *map_size);
            if (index == -1) {
                map[*map_size].name = (char *)malloc((MAXIMUM_STRING_LENGTH + 1) * sizeof(char));
                if (map[*map_size].name == NULL) {
                    for (int map_traverse = 0; map_traverse < *map_size; map_traverse++) {
                        free(map[map_traverse].name);
                    }
                    free(map);
                    free(fruit_array);
                    return 1;
                }
                copy_string(map[*map_size].name, fruit_array[row_index][column_index]);
                map[*map_size].count = 1;
                (*map_size)++;
            } else {
                map[index].count++;
            }
        }
    }
    return 0;
}

int main()
{
    int rows, columns, row_index, column_index,map_size=0;
    Map *map = (Map *)malloc(MAXIMUM_MAP_SIZE * sizeof(Map));
    if (map == NULL) {
        return 1;
    }
    
    scanf("%d %d",&rows, &columns);
    char (*fruit_array)[columns][MAXIMUM_STRING_LENGTH + 1]= malloc(rows * sizeof(*fruit_array)); 
    if(fruit_array == NULL){
        free(map);
        return 1;
    }
    
    read_input(rows, columns, fruit_array);
    print_array(rows, columns, fruit_array);
    if (process_map(rows, columns, fruit_array, map, &map_size) == 1) {
        return 1;
    }

    int found=0;
    for(row_index=0;row_index<map_size;row_index++){
        if(map[row_index].count > 1){
            printf("%s : %d\n", map[row_index].name , map[row_index].count);
            found=1;
        }
        free(map[row_index].name);
    }

    if(!found){
        printf("No Duplicates Found");
    }
    
    free(map);
    free(fruit_array);
    return 0;
}