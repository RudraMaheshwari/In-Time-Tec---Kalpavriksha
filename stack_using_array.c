#include<stdio.h>
#include<stdlib.h>

void push_to_stack(int *stack, int *stack_size, int *top){
    int data_value;
    printf("Enter data value:\n");
    scanf("%d",&data_value);
    if(*top == *stack_size -1){
        printf("Stack is Overflow.\n");
        return;
    } else{
        (*top)++;
        stack[*top] = data_value;
    }
    printf("Pushed to Stack.\n");
}

void pop_in_stack(int *stack, int *top){
    int data_value;
    if(*top == -1){
        printf("Stack is underflow.\n");
        return;
    }
    data_value = stack[*top];
    (*top)--;
    printf("%d is deleted.\n",data_value);
}

void peek_in_stack(int *stack, int *top){
    if(*top == -1){
        printf("Stack is underflow.\n");
        return;
    }
    printf("Top of Stack is: %d\n",stack[*top]);
}

void size_of_stack(int *stack, int *top){
    int count = 0 , index;
    if(*top == -1){
        printf("Stack is underflow.\n");
        return;
    } else{
        for(index = *top; index>=0;index--){
            printf("%d ",stack[index]);
            count++;
        }
    }
    printf("\nSize of Stack is: %d\n",count);
}

void is_empty(int *top){
    if(*top == -1){
        printf("Stack is Empty.");
        return;
    } else{
        printf("Stack is not empty.\n");
    }
}

int main(){
    int choice, *stack, top = -1, stack_size;
    printf("Enter Stack Size:\n");
    scanf("%d",&stack_size);
    stack = (int *)malloc(stack_size * sizeof(int));
    if(!stack){
        return 1;
    }
    while(1){
        printf("Stack Operations using array:\n");
        printf("1. Push to Stack.\n");
        printf("2. Pop in Stack.\n");
        printf("3. Peek in Stack.\n");
        printf("4. Check Empty Stack.\n");
        printf("5. Display and size of Stack.\n");
        printf("6. Exit program.\n");
        printf("Enter a Choice.\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push_to_stack(stack, &stack_size, &top);
                break;
            
            case 2:
                pop_in_stack(stack, &top);
                break;

            case 3:
                peek_in_stack(stack, &top);
                break;

            case 4:
                is_empty(&top);
                break;

            case 5:
                size_of_stack(stack,&top);
                break;

            case 6:
                free(stack);
                printf("Program Exited.\n");
                return 0;

            default:
                printf("Invalid Choice..!\n");
        }
    }
    return 0;
}