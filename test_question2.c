#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_compare(char *string1, char *string2){
    int i =0;
    while(string1[i] != '\0' && string2[i] != '\0'){
        char c1 = string1[i];
        char c2= string2[i];
        if(c1 >= 'A' && c1<='Z'){
            c1 += ('a'-'A');
        }
        if(c2 >= 'A' && c2<='Z'){
            c2 += ('a'-'A');
        }
        if(c1 != c2){
            return 0;
        }
        i++;
    }
    return (string1[i] == '\0' && string2[i] == '\0');
}

void string_copy(char dest[], char src[]){
    int index=0;
    while (src[index] != '\0')
    {
        dest[index]=src[index];
        index++;
    }
    dest[index]='\0';   
}
 
typedef struct {
    char character[100];
    int count;
} hash_map;
 
int map_search(hash_map map[], char *ch, int map_size) {
    for (int index = 0; index < map_size; index++) {
        if (string_compare(map[index].character, ch) == 1) {
            return index;
        }
    }
    return -1;
}
 
int main() {
    char *input_string = (char *)malloc(1024 * sizeof(char));
    if (!input_string) {
        return 1;
    }
    scanf("%[^\n]s", input_string);
    printf("Input String is: %s\n", input_string);
    getchar();
    char character;
    printf("Enter replacing character:\n");
    scanf(" %c",&character);

    hash_map map[256] = {0};
    int map_size = 0;
 
    for (int iterator = 0; input_string[iterator] != '\0'; iterator++) {
        if(input_string[iterator] == ' '){
            continue;
        }
        char ch[2] = {input_string[iterator], '\0'};
        int index = map_search(map, ch, map_size);
        if (index == -1) {
            string_copy(map[map_size].character, ch);
            map[map_size].count = 1;
            map_size++;
        } else {
            map[index].count++;
        }
    }
 
    for (int iterator = 0; iterator < map_size; iterator++) {
        if(map[iterator].count == 1){
            printf("Non repeating character is :%s\n", map[iterator].character);
            for(int index=0;input_string[index] != '\0';index++){
                if(input_string[index] == map[iterator].character[0])
                {
                    input_string[index] = character;
                    break;
                }
            }
            break;
        }
    }
    printf("Modified String: %s",input_string);
    free(input_string);
    return 0;
}