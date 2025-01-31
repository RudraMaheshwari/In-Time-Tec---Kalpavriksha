#include<stdio.h>
#include<stdlib.h>

void enqueue(int value, int *rear, int *front, int *queue, int *queue_size){
    if(*rear == (*queue_size) -1){
        printf("Queue Overflow.\n");
        return;
    } else if(*front == -1 && *rear == -1){
        *front = *rear = 0;
        queue[*rear] = value;
    } else{
        (*rear)++;
        queue[*rear] = value;
    }
    printf("Element inserted in Queue.\n");
}

void dequeue(int *rear, int *front, int *queue){
    if(*front == -1 && *rear == -1){
        printf("Queue Underflow.\n");
        return;
    } else if(*front == *rear){
        *front = *rear =-1;
    } else{
        printf("%d is deleted.\n",queue[*front]);
        (*front)++;
    }
}

void peek_in_queue(int *rear, int *front, int *queue){
    if(*front == -1 && *rear == -1){
        printf("Queue is Empty.\n");
        return;
    } else{
        printf("Element at front is : %d\n",queue[*front]);
    }
}

void is_empty(int *rear, int *front){
    if(*front == -1 && *rear == -1){
        printf("Queue is Empty.\n");
        return;
    } else{
        printf("Queue is not Empty.\n");
    }
}

void size_of_queue(int *rear, int *front, int *queue){
    int count =0;
    if(*front == -1 && *rear == -1){
        printf("Queue is Empty.\n");
        return;
    }
    for(int index = *front ; index < (*rear) +1 ; index++){
        printf("%d ",queue[index]);
        count++;
    }
    printf("\nSize of Queue is: %d\n",count);
}

int main(){
    int choice, data_value, queue_size, *queue, front =-1,rear = -1;
    printf("Enter Queue Size:\n");
    scanf("%d",&queue_size);
    queue = (int *)malloc(queue_size * sizeof(int));
    if(!queue){
        return 1;
    }
    while(1){
        printf("Queue Operations using array:\n");
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
                enqueue(data_value, &rear, &front, queue, &queue_size);
                break;
            
            case 2:
                dequeue(&rear, &front, queue);
                break;

            case 3:
                peek_in_queue(&rear, &front, queue);
                break;

            case 4:
                is_empty(&rear, &front);
                break;

            case 5:
                size_of_queue(&rear, &front, queue);
                break;

            case 6:
                free(queue);
                printf("Program Exited.\n");
                return 0;

            default:
                printf("Invalid Choice..!\n");
        }
    }
    return 0;
}