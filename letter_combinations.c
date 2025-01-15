#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* digit_to_letters[] = {
   "","","abc","def","ghi", "jkl","mno","pqrs","tuv","wxyz"
};

int total_combinations(const char* digits) {
   int total = 1;
   for (int index = 0; digits[index]; index++) {
       int digit = digits[index] - '0';
       if (digit < 2 || digit > 9) continue;
       total *= strlen(digit_to_letters[digit]);
   }
   return total;
}

void generate_combinations(const char* digits, char** result, char* current, int index, int position, int* resultIndex) {
   if (index == strlen(digits)) {
       current[position] = '\0';
       result[(*resultIndex)++] = strdup(current);
       return;
   }
   int digit = digits[index] - '0';
   if (digit < 2 || digit > 9) {
       generate_combinations(digits, result, current, index + 1, position, resultIndex);
       return;
   }
   const char* letters = digit_to_letters[digit];
   for (int itr = 0; letters[itr]; itr++) {
       current[position] = letters[itr];
       generate_combinations(digits, result, current, index + 1, position + 1, resultIndex);
   }
}

char** letter_combinations(const char* digits, int* returnSize) {
   if (strlen(digits) == 0) {
       *returnSize = 0;
       return NULL;
   }
   int combinaions = total_combinations(digits);
   char** result = (char**)malloc(combinaions * sizeof(char*));
   char* current = (char*)malloc((strlen(digits) + 1) * sizeof(char));
   int resultIndex = 0;
   generate_combinations(digits, result, current, 0, 0, &resultIndex);
   *returnSize = resultIndex;
   free(current);
   return result;
}

int main() {
   char *input_digit = (char *)malloc(5*sizeof(char));
   int returnSize ;
   if(!input_digit){
    return 1;
   }
   scanf("%s",input_digit);
   char** result1 = letter_combinations(input_digit, &returnSize);
   printf("Combinations:\n");
   for (int index = 0; index < returnSize; index++) {
       printf("%s ", result1[index]);
       free(result1[index]);
   }
   free(result1);
   return 0;
}