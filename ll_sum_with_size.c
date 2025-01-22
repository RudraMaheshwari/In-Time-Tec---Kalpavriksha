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

void add_to_list(int value,int *count,int window,int *sum){
    struct node *new_node = create_node(value);
    *sum = *sum + value;
    if(*count < window){
        new_node->next = head;
        head =new_node;
        (*count)++;
    }
    else if(window == 0){
        *sum =0;
        return;
    }
    else{
        struct node *temp = head;
        struct node *prev = NULL;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        *sum = *sum - (temp->data);
        free(temp);
        if (prev != NULL) {
            prev->next = NULL;
        }
        new_node->next = head;
        head = new_node;
    }
}

int main()
{
    int n,window_size,array[100];
    printf("Enter No of operations:\n");
    scanf("%d",&n);
    printf("Enter window size:\n");
    scanf("%d",&window_size);
    int sum = 0, count = 0, count_sum=0;

    for(int index = 0; index < n; index++) {
        char character;
        int data_value;
        printf("Enter choice and value:\n");
        scanf(" %c", &character);

        if(character == 'A' || character=='a') {
            scanf("%d", &data_value);
            add_to_list(data_value,&count,window_size,&sum);
            printf("Value Added.\n");
        } else if(character == 'S' || character =='s') {
            array[count_sum++]=sum;
        }
    }
    for(int index=0; index < count_sum; index++){
        printf("Sum is: %d\n",array[index]);
    }
    return 0;
}


