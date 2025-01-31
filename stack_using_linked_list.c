#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data_value;
    struct node *next;
} Node;

Node *create_node(int value, Node *top){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data_value = value;
    new_node->next = top;
    return new_node;
}

void push_to_stack(int value, Node **top){
    Node *new_node = create_node(value, *top);
    *top = new_node;
    printf("Pushed to stack.\n");
}

void pop_in_stack(Node **top){
    if(!*top){
        printf("Stack is Underflow.\n");
    } else{
        Node *temporary = *top;
        *top = (*top)->next;
        printf("%d is Deleted from stack.\n",temporary->data_value);
        free(temporary);
    }
}

void is_empty(Node *top){
    if(!top){
        printf("Stack is Empty.\n");
    } else{
        printf("Stack is not Empty.\n");
    }
}

void peek_in_stack(Node *top){
    if(!top){
        printf("Stack is Underflow.\n");
    } else{
        printf("Top of Stack is: %d\n",top->data_value);
    }
}

void size_of_stack(Node *top){
    if(top == NULL){
        printf("Stack is underflow.\n");
    }
    int count =0;
    Node *temporary  = top;
    while(temporary != NULL){
        printf("%d ",temporary->data_value);
        temporary = temporary->next;
        count++;
    }
    printf("\nSize of stack is: %d\n", count);
}

int main(){
    Node *top = NULL;
    int choice, data_value;
    while(1){
        printf("Stack Operations using Linked List:\n");
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
                printf("Enter data Value:\n");
                scanf("%d",&data_value);
                push_to_stack(data_value, &top);
                break;
            
            case 2:
                pop_in_stack(&top);
                break;

            case 3:
                peek_in_stack(top);
                break;

            case 4:
                is_empty(top);
                break;

            case 5:
                size_of_stack(top);
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