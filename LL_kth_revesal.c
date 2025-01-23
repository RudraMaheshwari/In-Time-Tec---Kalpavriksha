#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *create_node(int value){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

Node *create_list(char *string){
    Node *head = NULL;
    int index =0;
    while(string[index] != '\0'){
        if((string[index] >= '0' && string[index] <= '9') || string[index] == '-'){
            int number =0,is_negative =1;
            if(string[index] == '-'){
                is_negative = -1;
                index++;
            }
            while(string[index] >= '0' && string[index] <= '9'){
                number = number *10 + (string[index]-'0');
                index++;
            }
            Node *new_node = create_node(number *is_negative);
            if(!head){
                head = new_node;
            }
            else{
                Node *temporary = head;
                while(temporary->next != NULL){
                    temporary = temporary->next;
                }
                temporary->next = new_node;
            }
        } else{
            index++;
        }
    }
    return head;
}


Node *reverse_alternate_elements(Node *head, int kth_elements){
    Node *temporary = head , *previous = NULL, *next = head, *start=NULL , *end =NULL;

    while(temporary != NULL){
        start = temporary;
        int count =0;
        while(temporary != NULL && count<kth_elements){
            next = temporary->next;
            temporary->next = previous;
            previous = temporary;
            temporary = next;
            count++;
        }
        if(end != NULL){
            end->next = previous;
        } else{
            head = previous;
        }

        start->next= temporary;
        end =start;

        count =0;
        while(temporary != NULL && count <kth_elements){
            end = temporary;
            temporary = temporary->next;
            count++;
        }
    }
    return head;
}

void display(Node *head){
    Node *temporary = head;
    while(temporary != NULL){
        printf("%d ",temporary->data);
        temporary = temporary->next;
    }
    printf("\n");
}

int main(){
    int kth_reversal;
    char *input_list = (char *)malloc(1024 * sizeof(char));
    if(!input_list){
        return 1;
    }
    scanf("%[^\n]s", input_list);
    getchar();
    scanf("%d",&kth_reversal);

    Node *list = create_list(input_list);
    display(list);
    Node *result = reverse_alternate_elements(list,kth_reversal);
    display(result);
    free(input_list);
    return 0;
}