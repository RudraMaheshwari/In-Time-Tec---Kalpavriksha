#include<stdio.h>
#include<stdlib.h>

int valid_ip_address(char *input_address){
    int index=0;
    int number_count=0;
    int dot_count =0;
    while(input_address[index] != '\0'){
        int number=0;
        int digit_count=0;
        int leading_zero = (input_address[index] =='0');
        while((input_address[index]>='0' && input_address[index]<='9')){
            number = number*10 + (input_address[index]-'0');
            digit_count++;
            index++;
        }
        if(leading_zero && digit_count>0){
            return 0;
        }
        if(digit_count==0 || digit_count>3 || number < 0 || number > 255){
            return 0;
        }
        number_count++;
        if(input_address[index]=='.'){
            dot_count++;
            index++;
        }else if(input_address[index] !='\0'){
            return 0;
        }
    }
    return (dot_count==3 && number_count==4);
}

int main(){
    char *input_address =(char *)malloc(16 * sizeof(char));
    if(!input_address){
        return 1;
    }
    printf("Enter IPV4 Address: \n");
    scanf("%[^\n]s",input_address);
    
    if(valid_ip_address(input_address)){
        printf("Valid IP Address.\n");
    }
    else{
        printf("Invalid Ip Address.\n");
    }
    free(input_address);
    return 0;
}