#include <stdio.h>
#include<stdlib.h>

int string_length(char string[]){
    int index=0;
    while(string[index] != '\0'){
        index++;
    }
    return index;
}

void compress_string(char *input_string){
    
    int length =string_length(input_string);
    int output_length=0;
    for(int iterator =0; iterator < length-1 ;iterator++){
        char current_char = input_string[iterator];
        int count=1;
        
        while(iterator+1 <length && input_string[iterator]==input_string[iterator+1]){
            count++;
            iterator++;
        }
        
        printf("%c",current_char);
        output_length++;
        if(count>1){
            printf("%d",count);
            int temp=count;
            while(temp>0){
                output_length++;
                temp/=10;
            }
        }
        
    }
    printf("\nReturned characters(size of output array):%d",output_length);
    printf("\n");
}

int main()
{
    char *input_string=(char *)malloc(1024 * sizeof(char));
    if(!input_string){
        return 1;
    }
    printf("Enter the string:\n");
    fgets(input_string,1024,stdin);
    
    compress_string(input_string);
    free(input_string);
    return 0;
}
