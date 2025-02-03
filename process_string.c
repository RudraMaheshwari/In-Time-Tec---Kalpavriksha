#include <stdio.h>
#include <string.h>

void process_string(char *string, char *result){
    int index = 0; 
    for(int iterator = 0; string[iterator] != '\0'; iterator++){
        if(string[iterator] == '#'){
            if(index > 0){
                index--; 
            }
        } else{
            result[index++] = string[iterator]; 
        }
    }
    result[index] = '\0'; 
}

int main(){
    char seq_1[201], seq_2[201];
    char s_result[201], t_result[201];
    scanf("%s", seq_1);
    scanf("%s", seq_2);
    process_string(seq_1, s_result);
    process_string(t, t_result);
    if(strcmp(s_result, t_result) == 0){
        printf("true\n");
    } else{
        printf("false\n");
    }

    return 0;
}
