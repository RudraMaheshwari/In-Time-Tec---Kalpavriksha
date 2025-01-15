#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_length_of_non_repeating_string(char *input_string){
    int max_length =0, current_length=0, last_visited[256];
    memset(last_visited,-1,sizeof(last_visited));
    int start =0;
    for(int index =0; input_string[index]!= '\0';index++){
        char ch = input_string[index];
        if(last_visited[(int)ch]>= start){
            start = last_visited[(unsigned char)ch]+1;
        }
        last_visited[(int)ch]=index;
        current_length = index -start +1;
        if(current_length>max_length){
            max_length=current_length;
        }
    }
    return max_length;
}

int main(){
    char *input_string = (char *)malloc(1024 * sizeof(char));
    if(!input_string){
        return 1;
    }
    scanf("%[^\n]s",input_string);
    int count_length = count_length_of_non_repeating_string(input_string);
    printf("Count of Longest non repeating string is: %d\n", count_length);
    return 0;
}
