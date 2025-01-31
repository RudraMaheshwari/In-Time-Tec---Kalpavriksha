#include<stdio.h>
#include<stdlib.h>

void push_in_stack1(int value, int *Queue_size, int *stack_1, int *top_1){
    if((*top_1) == (*Queue_size) -1){
        printf("Overflow.\n");
        return;
    }else{
        (*top_1)++;
        stack_1[*top_1] = value;
    }
}

void push_in_stack2(int value, int *Queue_size, int *stack_2, int *top_2){
    if((*top_2) == (*Queue_size) -1){
        printf("Overflow.\n");
        return;
    }else{
        (*top_2)++;
        stack_2[*top_2] = value;
    }
}

int pop_in_stack1(int *stack_1, int *top_1){
    return stack_1[(*top_1)--];
}

int pop_in_stack2(int *stack_2, int *top_2){
    return stack_2[(*top_2)--];
}

void enqueue(int value, int *Queue_size , int *stack_1, int *top_1, int *count){
    push_in_stack1(value, Queue_size, stack_1,top_1);
    (*count)++;
    printf("Element inserted in queue.\n");
}

void dequeue(int *Queue_size , int *stack_1, int *stack_2, int *top_1, int *top_2, int *count){
    int data,stack2_data;
    if(*top_1 == -1 && *top_2 == -1){
        printf("Queue is Empty.\n");
        return;
    } else{
        for(int index =0;index<*count;index++){
            data = pop_in_stack1(stack_1,top_1);
            push_in_stack2(data,Queue_size,stack_2,top_2);
        }
        stack2_data = pop_in_stack2(stack_2,top_2);
        printf("Data deleted is : %d\n",stack2_data);
        (*count)--;
        for(int index =0;index<(*count);index++){
            data = pop_in_stack2(stack_2,top_2);
            push_in_stack1(data,Queue_size,stack_1,top_1);
        }
    }
}

void size_of_queue(int *stack_1, int *top_1, int *count){
    if(*count == 0){
        printf("Queue is Empty.\n");
    }
    printf("Queue is: ");
    for(int index =0;index<= *top_1;index++){
        printf("%d ",stack_1[index]);
    }
    printf("\nSize of Queue is: %d\n",(*count));
}

void peek_in_queue(int *Queue_size , int *stack_1, int *stack_2, int *top_1, int *top_2, int *count){
    int data,stack2_data;
    if(*top_1 == -1 && *top_2 == -1){
        printf("Queue is Empty.\n");
    } else{
        for(int index =0;index<(*count);index++){
            data = pop_in_stack1(stack_1,top_1);
            push_in_stack2(data, Queue_size, stack_2, top_2);
        }
        printf("Front element in queue is: %d\n",stack_2[*top_2]);
    }
}

void is_empty(int *top_1, int *top_2){
    if(*top_1 == -1 && *top_2 == -1){
        printf("Queue is Empty.\n");
    } else{
        printf("Queue is not Empty.\n");
    }
}

int main(){
    int choice, data_value, Queue_size, *stack_1, *stack_2, top_1 = -1, top_2 = -1, count=0;;
    printf("Enter Queue Size:\n");
    scanf("%d",&Queue_size);
    stack_1 = (int *)malloc(Queue_size * sizeof(int));
    if(!stack_1){
        return 1;
    }
    stack_2 = (int *)malloc(Queue_size * sizeof(int));
    if(!stack_2){
        return 1;
    }
    while(1){
        printf("Queue Operations using two stack:\n");
        printf("1. Enqueue(Insertion).\n");
        printf("2. Dequeue(Deletion).\n");
        printf("3. Peek in Queue(Identify Front).\n");
        printf("4. Check Empty Queue.\n");
        printf("5. Display and size of Queue.\n");
        printf("6. Exit program.\n");
        printf("Enter a Choice.\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted in queue:\n");
                scanf("%d",&data_value);
                enqueue(data_value, &Queue_size, stack_1,&top_1,&count);
                break;
            
            case 2:
                dequeue(&Queue_size, stack_1, stack_2, &top_1, &top_2, &count);
                break;

            case 3:
                peek_in_queue(&Queue_size, stack_1,stack_2,&top_1,&top_2,&count);
                break;

            case 4:
                is_empty(&top_1, &top_2);
                break;

            case 5:
                size_of_queue(stack_1, &top_1, &count);
                break;

            case 6:
                free(stack_1);
                free(stack_2);
                printf("Program Exited.\n");
                return 0;

            default:
                printf("Invalid Choice..!\n");
        }
    }
    return 0;
}