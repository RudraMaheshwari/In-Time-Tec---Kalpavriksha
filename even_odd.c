#include <stdio.h>
#include <stdlib.h>
 
typedef struct node{
    int data;
    struct node *next;
} Node;
 
Node *initialize_node(int data){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
 
void add_node(Node **head, int data){
    Node *node = initialize_node(data);
    if(*head == NULL){
        *head = node;
        return;
    }
    Node *temporary = *head;
    while(temporary->next){
        temporary = temporary->next;
    }
    temporary->next = node;
}
 
void display(Node *head, char *string){
    printf("%s\n", string);
    while (head){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
 
void create_Node(Node **head){
    int data;
    printf("Enter Node elements: ");
    while(scanf("%d", &data) == 1){
        add_node(head, data);
        if (getchar() == '\n')
            break;
    }
}
 
void split(Node **head){
    Node *even = initialize_node(-1);
    Node *odd = initialize_node(-1);
    Node *traversal = *head;
    while(traversal){
        Node *position;
        if(traversal->data & 1){
            position = odd;
            while(position->next && position->next->data > traversal->data){
                position = position->next;
            }
        } else{
            position = even;
            while (position->next && position->next->data < traversal->data){
                position = position->next;
            }
        }
        Node *next = traversal->next;
        traversal->next = position->next;
        position->next = traversal;
        traversal = next;
    }
 
    if(even->next == NULL){
        *head = odd->next;
    }else {
        *head = even->next;
        while (even->next) {
            even = even->next;
        }
        even->next = odd->next;
    }
}
 
void free_Node(Node *head){
    while(head){
        Node *to_delete = head;
        head = head->next;
        free(to_delete);
    }
}
 
int main(){
    Node *head = NULL;
    create_Node(&head);
    display(head, "Input Node:");
    split(&head);
    display(head, "Node after transformation:");
    free_Node(head);
    return 0;
}