#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 26

typedef struct {
    char character;
    int frequency;
} char_freq;

char* rearrange_string(char* s) {
    int n = strlen(s);
    char_freq hashmap[MAX_CHAR] = {0};
    for (int iterator = 0; iterator < n; iterator++) {
        int index = s[iterator] - 'a';
        hashmap[index].character = s[iterator];
        hashmap[index].frequency++;
    }
    for (int row_index = 0; row_index < MAX_CHAR - 1; row_index++) {
        for (int column_index = row_index + 1; column_index < MAX_CHAR; column_index++) {
            if (hashmap[row_index].frequency < hashmap[column_index].frequency) {
                char_freq temp = hashmap[row_index];
                hashmap[row_index] = hashmap[column_index];
                hashmap[column_index] = temp;
            }
        }
    }
    if (hashmap[0].frequency > (n + 1) / 2) {
        return "";
    }
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0'; 
    int index = 0;
    for (int iterator = 0; iterator < MAX_CHAR && hashmap[iterator].frequency > 0; iterator++) {
        while (hashmap[iterator].frequency > 0) {
            if (index >= n) {
                index = 1;
            }
            result[index] = hashmap[iterator].character;
            index += 2;
            hashmap[iterator].frequency--;
        }
    }
    return result;
}

int main() {
    char *input_string = (char *)malloc(1024 * sizeof(char));
    if(!input_string){
        return 1;
    }
    printf("Enter String: ");
    scanf("%[^\n]s",input_string);
    char* result = rearrange_string(input_string);
    printf("Rearranged String: %s", result[0] ? result : "");
    free(result);
    return 0;
} 