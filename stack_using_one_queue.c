#include <stdio.h>
#include <stdlib.h>

void enqueue(int *queue, int *front, int *rear, int size, int value){
    if(*rear == size - 1){
        printf("Stack Overflow.\n");
        return;
    }
    if(*front == -1) {
        *front = *rear = 0;
    } else {
        (*rear)++;
    }
    queue[*rear] = value;
}

int dequeue(int *queue, int *front, int *rear){
    if(*front == -1){
        printf("Stack Underflow.\n");
        return -1;
    }
    int value = queue[*front];
    if(*front == *rear){
        *front = *rear = -1;
    } else{
        (*front)++;
    }
    return value;
}

void push_in_stack(int *queue, int *front, int *rear, int size, int value){
    enqueue(queue, front, rear, size, value);
    for (int i = 0; i < (*rear - *front); i++){
        enqueue(queue, front, rear, size, dequeue(queue, front, rear));
    }
    printf("Element pushed to stack.\n");
}

void pop_in_stack(int *queue, int *front, int *rear){
    printf("Deleted element is: %d\n",dequeue(queue, front, rear));
}

void peek_in_stack(int *queue, int front){
    if(front == -1){
        printf("Stack is Empty.\n");
        return;
    }
    printf("Element at top is: %d\n",queue[front]);
}

void is_empty(int front){
    if(front == -1){
        printf("Stack is Empty.\n");
    } else{
        printf("Stack is not Empty.\n");
    }
}

void display(int *queue, int front, int rear){
    if(front == -1){
        printf("Stack is Empty.\n");
        return;
    }
    printf("Stack elements: ");
    for(int index = front; index <= rear; index++){
        printf("%d ", queue[i]);
    }
    printf("\nSize of stack: %d\n", (rear - front + 1));
}

int main(){
    int stack_size, *queue, front = -1, rear = -1, choice, value;
    printf("Enter stack size: ");
    scanf("%d", &stack_size);
    queue = (int *)malloc(stack_size * sizeof(int));
    if(!queue){
        return 1;
    }
    while(1){
        printf("Stack Operations using One Queue:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Peek Stack\n");
        printf("4. Check is_empty\n");
        printf("5. Display and Size of Stack\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push_in_stack(queue, &front, &rear, stack_size, value);
                break;

            case 2:
                pop_in_stack(queue, &front, &rear);
                break;

            case 3:
                peek_in_stack(queue, front);
                break;

            case 4:
                is_empty(front);
                break;

            case 5:
                display(queue, front, rear);
                break;

            case 6:
                free(queue);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}