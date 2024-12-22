#include<stdio.h>
#include<stdlib.h>

void evaluate_expression(char *expression);
int perform_operation(int arr_num[], int *index_num, char arr_op[], int *index_op, char operation);
int final_evaluation(int arr_num[], int index_num, char arr_op[], int index_op);

int main()
{
    char *expression = NULL;
    int capacity = 1;
    int length = 0;
    expression = (char *)malloc(capacity * sizeof(char));
    if (expression == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    printf("Enter the expression for evaluation: ");
    char c;
    while (scanf("%c", &c) == 1 && c != '\n') {
        if (length + 1 >= capacity) {
            capacity *= 2;
            char *new_expression = (char *)realloc(expression, capacity * sizeof(char));
            if (new_expression == NULL) {
                printf("Error: Memory reallocation failed.\n");
                free(expression);
                return 1;
            }
            expression = new_expression;
        }
        expression[length++] = c;
    }
    expression[length] = '\0';
    evaluate_expression(expression);
    free(expression);
    return 0;
}

void evaluate_expression(char *expression)
{
    int arr_num[100],index_num=0,index_op=0,digit=0,index;
    char arr_op[100];
    for(index = 0 ; expression[index] != '\0' ; index++){
        char ch = expression[index];
        if(ch == ' '){
            continue;
        }
        if(ch >= '0' && ch <= '9'){
            digit = digit * 10 + (ch - '0');
        } else {
            arr_num[index_num++] = digit;
            digit=0;
            if(ch == '+' || ch == '-' || ch == '/' || ch== '*'){
                arr_op[index_op++] = ch;
            } else {
                printf("Error: Invalid expression.\n");
                return;
            }
        }
    }
    arr_num[index_num++]=digit;
    if (!perform_operation(arr_num, &index_num, arr_op, &index_op, '/')) {
        return;
    }
    perform_operation(arr_num, &index_num, arr_op, &index_op, '*');
    int result = final_evaluation(arr_num, index_num, arr_op, index_op);
    printf("Result: %d\n", result);
}


int final_evaluation(int arr_num[],int index_num,char arr_op[], int index_op)
{
    int result = arr_num[0];
    int index;
    for(index=0; index< index_op; index++)
    {
        if(arr_op[index]=='+'){
            result += arr_num[index+1];
        } else if(arr_op[index] == '-'){
            result -= arr_num[index+1];
        }
    }
    return result;
}

int perform_operation(int arr_num[],int *index_num,char arr_op[], int *index_op, char operation)
{
    int num_row, num_col, num_depth;
    for(num_row=0; num_row< *index_op; num_row++){
        if(arr_op[num_row] == operation){
            if(operation == '/' && arr_num[num_row + 1] == 0){
                printf("Error: Division by zero.\n");
                return 0;
            }
            arr_num[num_row] = (operation == '/') ? arr_num[num_row] / arr_num[num_row + 1] : arr_num[num_row] * arr_num[num_row + 1];
            for(num_col = num_row + 1 ; num_col < *index_num - 1 ; num_col++){
                arr_num[num_col] = arr_num[num_col + 1];
            }
            for(num_depth = num_row ; num_depth < *index_op - 1 ; num_depth++){
                arr_op[num_depth] = arr_op[num_depth + 1];
            }
            (*index_num)--;
            (*index_op)--;
            num_row--;
        }
    }
    return 1;
}