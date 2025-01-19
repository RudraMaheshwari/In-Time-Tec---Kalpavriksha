#include<stdio.h>
#include<stdlib.h>

struct node{
    int data_value;
    struct node *address_of_next;
};

struct node *head_pointer = NULL;
struct node *temporary_pointer=NULL;

int get_data_input() {
    int number;
    while(1){
        scanf("%d", &number);
        if(number >=-1000 && number <= 1000){
            return number;
        }else{
            printf("Invalid data value, Enter value again.\n");
        }
    }
}

int count_nodes(){
    int count=0;
    temporary_pointer=head_pointer;
    while(temporary_pointer != NULL){
        temporary_pointer=temporary_pointer->address_of_next;
        count++;
    }
    return count;
}

int check_empty(const char *message){
    if(!head_pointer){
        if(message){
            printf("%s\n",message);
        }
        return 1;
    }
    return 0;
}

struct node *create_new_node(int value){
    struct node *temporary_pointer = (struct node*)malloc(sizeof(struct node));
    temporary_pointer->data_value =value ;
    temporary_pointer->address_of_next = NULL;
    return temporary_pointer;
}

void insert_at_begining(int value){
    struct node *new_node = create_new_node(value);
    new_node->address_of_next = head_pointer;
    head_pointer=new_node;
}

void insert_at_end(int value){
    struct node *new_node = create_new_node(value);
    if(check_empty(NULL)){
        head_pointer =new_node;
        return;
    } else{
        struct node *temporary_pointer =head_pointer;
        while(temporary_pointer->address_of_next != NULL){
            temporary_pointer = temporary_pointer->address_of_next;
        }
        temporary_pointer->address_of_next =new_node;
    }
}

void insert_at_position(int value,int position){
    if(check_empty("Empty Linked List.")){
        return;
    }
    int index=1, count= count_nodes();
    struct node *new_node=create_new_node(value);
    temporary_pointer=head_pointer;
    if(position > count+1 || position< 1){
        printf("Invalid Position.\n");
        return;
    }
    else if(position == 1){
        new_node->address_of_next = head_pointer;
        head_pointer=new_node;
    }
    else{
        while(index < position - 1){
            temporary_pointer  = temporary_pointer->address_of_next;
            index++;
        }
        new_node->address_of_next = temporary_pointer->address_of_next;
        temporary_pointer->address_of_next=new_node;
    }
}

void display(){
    temporary_pointer =head_pointer;
    if(check_empty("Empty Linked List.")){
        return;
    }
    while(temporary_pointer != NULL){
        printf("%d ",temporary_pointer->data_value);
        temporary_pointer=temporary_pointer->address_of_next;
    }
    printf("\n");
}

void update_at_position(int position, int value){
    if(check_empty("Empty Linked List.")){
        return;
    }
    int count=count_nodes(),index=1;
    temporary_pointer=head_pointer;
    if(position>count || position<1){
        printf("Invalid Position.\n");
        return;
    }
    while(index < position){
        temporary_pointer  = temporary_pointer->address_of_next;
        index++;
    }
    temporary_pointer->data_value = value;
}

void delete_at_first(){
    if(check_empty("Empty Linked List.")){
        return;
    }
    temporary_pointer = head_pointer;
    head_pointer = head_pointer->address_of_next;
    free(temporary_pointer);
}

void delete_at_end(){
    if(check_empty("Empty Linked List.")){
        return;
    }
    temporary_pointer =head_pointer;
    while(temporary_pointer->address_of_next->address_of_next != NULL){
        temporary_pointer = temporary_pointer->address_of_next;
    }
    free(temporary_pointer->address_of_next);
    temporary_pointer->address_of_next = NULL;
}

void delete_at_position(int position){
    if(check_empty("Empty Linked List.")){
        return;
    }
    int count=count_nodes(),index=1;
    struct node *next_node=NULL;
    temporary_pointer=head_pointer;
    if(position > count || position<1){
        printf("Invalid Position.\n");
        return;
    }
    else if(position == 1){
         head_pointer = head_pointer->address_of_next;
         free(temporary_pointer);
    }
    else{
        while(index < position -1){
            temporary_pointer  = temporary_pointer->address_of_next;
            index++;
        }
        next_node = temporary_pointer->address_of_next;
        temporary_pointer->address_of_next = next_node->address_of_next;
        free(next_node);
    }
}

int main(){
    int choice, data_value, position, no_of_operations;
    while(1){
        scanf("%d",&no_of_operations);
        if(no_of_operations >0 && no_of_operations <= 100){
            break;
        } else{
            printf("Invalid Number of operations,Enter again.\n");
        }
    }
    for(int index=1;index<no_of_operations+1;index++){
        scanf("%d",&choice);
        switch(choice){
            case 1:
            data_value = get_data_input();
            insert_at_begining(data_value);
            break;

            case 2:
            data_value = get_data_input();
            insert_at_end(data_value);
            break;

            case 3:           
            position = get_data_input();
            data_value = get_data_input();
            insert_at_position(data_value,position);
            break;
                            
            case 4:
            display();
            break;

            case 5:
            position = get_data_input();
            data_value = get_data_input();
            update_at_position(position,data_value);
            break;

            case 6:
            delete_at_first();
            break;

            case 7:
            delete_at_end();
            break;

            case 8:
            position = get_data_input();
            delete_at_position(position); 
            break;

            default:
            printf("Invalid Choice.\n");
            break;
            }   
    }
    return 0;
}