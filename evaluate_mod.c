#include<stdio.h>
#include<stdlib.h>

long long calculate_mod(long long Base, long long Exponent, long long Modulus){
    long long result = 1;
    Base = Base % Modulus;

    while(Exponent > 0){
        if(Exponent % 2 == 1){
            result = (result * Base) % Modulus;
        }

        Base = (Base * Base) % Modulus;
        Exponent = Exponent / 2; 
    }
    return result;
}

void validate_base(long long Base) {
    if (Base < 0) {
        printf("Error: Base (B) must be a positive integer.");
        exit(1);
    }
}

void validate_exponent(long long Exponent) {
    if (Exponent < 0) {
        printf("Error: Exponent (N) cannot be negative.");
        exit(1);
    }
}

void validate_modulus(long long Modulus) {
    if (Modulus <= 1) {
        printf("Error: Modulus (M) must be greater than 1.");
        exit(1);
    }
}

void validate_input(int result, const char *warning) {
    if (result != 1) {
        printf("%s\n", warning);
        exit(1);
    }
}

int main(){
    long long Base, Exponent, Modulus, result;

    printf("Enter Base:\n");
    validate_input(scanf("%lld", &Base)," Please enter a valid integer.");
    printf("Enter Exponent:\n");
    validate_input(scanf("%lld", &Exponent)," Please enter a valid integer.");
    printf("Enter Modulus:\n");
    validate_input(scanf("%lld", &Modulus)," Please enter a valid integer.");

    validate_base(Base);
    validate_exponent(Exponent);
    validate_modulus(Modulus);

    result = calculate_mod(Base, Exponent, Modulus);

    printf("Result: %lld\n",result);
    return 0;
}
