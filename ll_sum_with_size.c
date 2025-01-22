#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head= NULL;
struct node *create_node(int value){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void add_to_list(int value,int *count_nodes,int window,int *sum){
    struct node *new_node = create_node(value);
    *sum = *sum + value;
    if(*count_nodes < window){
        new_node->next = head;
        head =new_node;
        (*count_nodes)++;
    }
    else if(window == 0){
        *sum =0;
        return;
    }
    else{
        struct node *temporary = head;
        struct node *previous = NULL;
        while(temporary->next != NULL){
            previous = temporary;
            temporary = temporary->next;
        }
        *sum = *sum - (temporary->data);
        free(temporary);
        if (previous != NULL) {
            previous->next = NULL;
        }
        new_node->next = head;
        head = new_node;
    }
}

void display(){
    struct node *temporary = head;
    while(temporary != NULL){
        printf("%d ",temporary->data);
        temporary = temporary->next;
    }
}

int main()
{
    int operations,window_size,result_array[100];
    printf("Enter No of operations:\n");
    scanf("%d",&operations);
    printf("Enter window size:\n");
    scanf("%d",&window_size);
    int sum = 0, count_nodes = 0, count_sum=0;

    for(int index = 0; index < operations; index++) {
        char character;
        int data_value;
        printf("Enter choice and value:\n");
        scanf(" %c", &character);

        if(character == 'A' || character=='a') {
            scanf("%d", &data_value);
            add_to_list(data_value,&count_nodes,window_size,&sum);
            printf("Value Added.\n");
        } else if(character == 'S' || character =='s') {
            result_array[count_sum++]=sum;
        }
    }
    for(int index=0; index < count_sum; index++){
        printf("Sum is: %d\n",result_array[index]);
    }
    return 0;
}
