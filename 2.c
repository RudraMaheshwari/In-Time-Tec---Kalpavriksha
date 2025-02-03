#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

Node *create_node(int value){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void display(Node *head){
    Node *temp = head;
    if(temp != NULL){
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }
    printf("\n");
}

Node *parse_input(char *input_string){
    Node *head = NULL, *temp = NULL;
    int index = 0;
    while(input_string[index] != '\0'){
        if((input_string[index] >= '0' && input_string[index] <= '9') || input_string[index] == '-'){
            int number = 0, is_negative = 1;
            if(input_string[index] == '-'){
                is_negative = -1;
                index++;
            }
            while(input_string[index] >= '0' && input_string[index] <= '9'){
                number = number * 10 + (input_string[index] - '0');
                index++;
            }
            Node *new_node = create_node(number * is_negative);
            if(head == NULL){
                head = temp = new_node;
            } else{
                temp->next = new_node;
                temp = temp->next;
            }
        } else{
            index++;
        }
    }
    if(temp != NULL){
        temp->next = head; 
    }
    return head;
}

void to_array(Node *head, int **array, int *size){
    Node *temp = head;
    *size = 0;
    if(head != NULL){
        do{
            (*size)++;
            temp = temp->next;
        }while(temp != head);
    }
    
    *array = (int *)malloc(*size * sizeof(int));
    
    temp = head;
    for(int i = 0; i < *size; i++){
        (*array)[i] = temp->data;
        temp = temp->next;
    }
}

int find_index(int *arr, int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

void sort_array(int *arr, int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int find_target_index(Node *head, int target) {
    int *arr = NULL;
    int size = 0;
    to_array(head, &arr, &size);
    sort_array(arr, size);
    int index = find_index(arr, size, target);
    free(arr);
    return index;
}

int main(){
    char *input_list = (char *)malloc(1024 * sizeof(char));
    if(!input_list){
        return 1;
    }
    scanf("%[^\n]s", input_list);
    getchar();
    
    int target;
    scanf("%d", &target);
    Node *linked_list = parse_input(input_list);
    int index = find_target_index(linked_list, target);
    printf("%d\n", index);
    free(input_list);
    
    return 0;
}
