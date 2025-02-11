#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int is_common(char* word1, char* word2){
    int letters[26] = {0};
    for(int i = 0; word1[i] != '\0'; i++){
        letters[word1[i] - 'a'] = 1;
    }
    for(int i = 0; word2[i] != '\0'; i++){
        if(letters[word2[i] - 'a']){
            return 1;
        }
    }
    return 0;
}

int main(){
    char *input = (char *)malloc(10000 * sizeof(char));
    fgets(input, 10000, stdin);
    int inp_index = 0, string_index = 0, array_index = 0;
    char string[MAX];
    char array[MAX][MAX];
    while(input[inp_index] != '\0'){
        if(input[inp_index] != ' ' && input[inp_index] != '\n'){
            string[string_index++] = input[inp_index];
        } else if(string_index > 0){
            string[string_index] = '\0';
            strcpy(array[array_index++], string);
            string_index = 0;
        }
        inp_index++;
    }
    int max_multiply = 0;
    for(int i = 0; i < array_index; i++){
        for(int j = i + 1; j < array_index; j++){
            if(!is_common(array[i], array[j])){
                int product = strlen(array[i]) * strlen(array[j]);
                if(product > max_multiply){
                    max_multiply = product;
                }
            }
        }
    }
    printf("%d\n", max_multiply);
    free(input);
    return 0;
}
