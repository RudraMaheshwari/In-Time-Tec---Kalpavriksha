#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int size, int value){
    if(*top==size-1){
        printf("Queue Overflow.\n");
        return;
    }
    stack[++(*top)]=value;
}

void dequeue_recursive(int *stack, int *top, int *front){
    if(*top==-1){
        printf("Queue Underflow.\n");
        *front=-1;
        return;
    }
    int value=stack[(*top)--];
    if(*top==-1){
        *front=value;
        return;
    }
    dequeue_recursive(stack,top,front);
    push(stack,top,*top+2,value);
}

void enqueue(int *stack, int *top, int size, int value){
    push(stack,top,size,value);
    printf("Element inserted into queue: %d\n",value);
}

void dequeue(int *stack, int *top){
    int front;
    dequeue_recursive(stack,top,&front);
    if(front!=-1){
     printf("Deleted element is: %d\n",front);
    } 
}

void peek_recursive(int *stack, int *top, int *front){
    if(*top==-1){
        printf("Queue is Empty.\n");
        *front=-1;
        return;
    }
    int value=stack[(*top)--];
    if(*top==-1){
        *front=value;
    } else{
        peek_recursive(stack,top,front);
    } 
    push(stack,top,*top+2,value);
}

void peek(int *stack, int *top){
    int front;
    peek_recursive(stack,top,&front);
    if(front!=-1){
        printf("Element at front is: %d\n",front);
    } 
}

void is_empty(int top){
    if(top==-1){
        printf("Queue is Empty.\n");
    } 
    else{
        printf("Queue is not Empty.\n");
    } 
}

void display_recursive(int *stack, int top){
    if(top==-1){
        return;
    } 
    int value=stack[top];
    display_recursive(stack,top-1);
    printf("%d ",value);
}

void display(int *stack, int top){
    if(top==-1){
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue elements: ");
    display_recursive(stack,top);
    printf("\nSize of queue: %d\n",top+1);
}

int main(){
    int queue_size,*stack,top=-1,choice,value;
    printf("Enter queue size: ");
    scanf("%d",&queue_size);
    stack=(int*)malloc(queue_size*sizeof(int));
    if(!stack){
        return 1;
    }
    while(1){
        printf("Queue Operations using One Stack:\n");
        printf("1. Enqueue to Queue\n");
        printf("2. Dequeue from Queue\n");
        printf("3. Peek Queue\n");
        printf("4. Check is_empty\n");
        printf("5. Display and Size of Queue\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d",&value);
                enqueue(stack,&top,queue_size,value);
                break;

            case 2:
                dequeue(stack,&top);
                break;

            case 3:
                peek(stack,&top);
                break;

            case 4:
                is_empty(top);
                break;

            case 5:
                display(stack,top);
                break;

            case 6:
                free(stack);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}