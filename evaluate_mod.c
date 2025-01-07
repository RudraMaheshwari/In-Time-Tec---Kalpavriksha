#include<stdio.h>
#include<stdlib.h>

long long calculate_mod(long long base_value, long long exponent_value, long long modulus_value){
    long long result_value = 1;
    base_value = base_value % modulus_value;

    while(exponent_value > 0){
        if(exponent_value % 2 == 1){
            result_value = (result_value * base_value) % modulus_value;
        }

        base_value = (base_value * base_value) % modulus_value;
        exponent_value = exponent_value / 2; 
    }
    return result_value;
}


long long validate_input(const char *warning, long long min_value) {
    long long value;
    int input_status;
    
    while (1) {
        input_status = scanf("%lld", &value);

        if (input_status == 1 && value >= min_value) {
            return value;
        } else {
            printf("Invalid input, %s\n", warning);
            while (getchar() != '\n');
        }
    }
}

int main(){
    long long base_value, exponent_value, modulus_value, result_value;

    printf("Enter Base value:\n");
    base_value = validate_input(" Please enter a non-negative integer.\nEnter Base value: ", 0);
    printf("Enter Exponent value:\n");
    exponent_value = validate_input(" Please enter a non-negative integer.\nEnter Exponent value:", 0);
    printf("Enter Modulus value:\n");
    modulus_value = validate_input(" Please enter a valid integer greater than 1.\nEnter Modulus value:", 2);

    result_value = calculate_mod(base_value, exponent_value, modulus_value);

    printf("Result is : %lld\n",result_value);
    return 0;
}
