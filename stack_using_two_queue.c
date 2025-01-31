#include<stdio.h>
#include<stdlib.h>

void swap(int *first, int *second){
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

void enqueue_in_queue1(int value, int *queue_1, int *front_1, int *rear_1, int stack_size){
    if(*rear_1 == stack_size - 1){
        printf("Overflow.\n");
    } else if(*front_1 == -1 && *rear_1 == -1){
        *front_1 = *rear_1 = 0;
        queue_1[*rear_1] = value;
    } else{
        (*rear_1)++;
        queue_1[*rear_1] = value;
    }
}

void enqueue_in_queue2(int value, int *queue_2, int *front_2, int *rear_2, int stack_size){
    if(*rear_2 == stack_size - 1){
        printf("Overflow.\n");
    } else if(*front_2 == -1 && *rear_2 == -1){
        *front_2 = *rear_2 = 0;
        queue_2[*rear_2] = value;
    } else{
        (*rear_2)++;
        queue_2[*rear_2] = value;
    }
}

int dequeue_in_queue1(int *queue_1, int *front_1){
    return queue_1[(*front_1)++];
}

int dequeue_in_queue2(int *queue_2, int *front_2){
    return queue_2[(*front_2)++];
}

void push_to_stack(int value, int *queue_1, int *front_1, int *rear_1, int stack_size, int *count){
    enqueue_in_queue1(value, queue_1, front_1, rear_1, stack_size);
    (*count)++;
    printf("Element pushed to stack.\n");
}

void pop_in_stack(int *queue_1, int *queue_2, int *front_1, int *rear_1, int *front_2, int *rear_2, int *count){
    if(*front_1 == -1){
        printf("Stack is Empty.\n");
        return;
    }
    while(*front_1 != *rear_1){
        enqueue_in_queue2(dequeue_in_queue1(queue_1, front_1), queue_2, front_2, rear_2, *count);
    }
    printf("Deleted element is: %d\n", dequeue_in_queue1(queue_1, front_1));
    (*count)--;
    swap(front_1, front_2);
    swap(rear_1, rear_2);
}

void peek_in_stack(int *queue_1, int *queue_2, int *front_1, int *rear_1, int *front_2, int *rear_2){
    if(*front_1 == -1){
        printf("Stack is Empty.\n");
        return;
    }
    while(*front_1 != *rear_1){
        enqueue_in_queue2(dequeue_in_queue1(queue_1, front_1), queue_2, front_2, rear_2, *rear_1);
    }
    printf("Element at top is: %d\n", queue_1[*front_1]);
}

void is_empty(int *count){
    if(*count == 0){
        printf("Stack is Empty.\n");
    } else{
        printf("Stack is not empty.\n");
    }
}

void size_of_stack(int *queue_1, int *front_1, int *rear_1, int *count){
    if(*count == 0){
        printf("Stack is Empty.\n");
        return;
    }
    printf("Stack is: ");
    for(int index = *rear_1; index >= *front_1; index--){
        printf("%d ",queue_1[index]);
    }
    printf("\nSize of stack is : %d\n",*count);
}

int main() {
    int stack_size, *queue_1, *queue_2, front_1 = -1, rear_1 = -1, front_2 = -1, rear_2 = -1, count = 0;
    int choice, data_value;
    printf("Enter Stack Size:\n");
    scanf("%d", &stack_size);
    queue_1 = (int *)malloc(stack_size * sizeof(int));
    if(!queue_1){
        return 1;
    }
    queue_2 = (int *)malloc(stack_size * sizeof(int));
    if(!queue_2){
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
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data want to be inserted in stack:\n");
                scanf("%d", &data_value);
                push_to_stack(data_value, queue_1, &front_1, &rear_1, stack_size, &count);
                break;

            case 2:
                pop_in_stack(queue_1, queue_2, &front_1, &rear_1, &front_2, &rear_2, &count);
                break;

            case 3:
                peek_in_stack(queue_1, queue_2, &front_1, &rear_1, &front_2, &rear_2);
                break;

            case 4:
                is_empty(&count);
                break;

            case 5:
                size_of_stack(queue_1, &front_1, &rear_1, &count);
                break;

            case 6:
                free(queue_1);
                free(queue_2);
                printf("Program Exited.\n");
                return 0;

            default:
                printf("Invalid Choice..!\n");
        }
    }
    return 0;
}