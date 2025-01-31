
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data_value;
    struct node *next;
}Node;

Node *create_node(int value){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data_value = value;
    new_node->next = NULL;
    return new_node;
}

void enqueue(int value, Node **front, Node **rear){
    Node *new_node = create_node(value);
    if(*front == NULL && *rear == NULL){
        *front = *rear = new_node;
    } else{
        (*rear)->next = new_node;
        *rear = new_node;
    }
    printf("Element inserted in queue.\n");
}

void dequeue(Node **front, Node **rear){
    if(*front == NULL){
        printf("Queue Underflow.\n");
        return;
    } else{
        Node *temporary = *front;
        printf("%d is deleted.\n", (*front)->data_value);
        *front = (*front)->next;
        if(*front == NULL){
            *rear = NULL;
        }
        free(temporary);
    }
}

void size_of_queue(Node *front){
    int count = 0;
    Node *temporary = front;
    if(front == NULL){
        printf("Queue is Empty.\n");
    } else{
        while(temporary != NULL){
            printf("%d ", temporary->data_value);
            temporary = temporary->next;
            count++;
        }
        printf("\nSize of Queue is: %d\n", count);
    }
}

void peek_in_queue(Node *front){
    if(front == NULL){
        printf("Queue is empty.\n");
    } else{
        printf("Front element is: %d\n", front->data_value);
    }
}

void is_empty(Node *front) {
    if(front == NULL){
        printf("Queue is empty.\n");
    } else{
        printf("Queue is not empty.\n");
    }
}

int main() {
    Node *front = NULL, *rear = NULL;
    int choice, data_value;
    while(1){
        printf("Queue Operations using Linked List:\n");
        printf("1. Enqueue(Insertion).\n");
        printf("2. Dequeue(Deletion).\n");
        printf("3. Peek in Queue(Identify Front).\n");
        printf("4. Check Empty Queue.\n");
        printf("5. Display and size of Queue.\n");
        printf("6. Exit program.\n");
        printf("Enter a Choice.\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted in queue:\n");
                scanf("%d", &data_value);
                enqueue(data_value, &front, &rear);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                peek_in_queue(front);
                break;
            case 4:
                is_empty(front);
                break;
            case 5:
                size_of_queue(front);
                break;
            case 6:
                printf("Program Exited.\n");
                return 0;
            default:
                printf("Invalid Choice..!\n");
        }
    }
    return 0;
}