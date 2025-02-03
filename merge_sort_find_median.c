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
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node *parse_input(char *input_string){
    Node *head=NULL;
    Node *temp = NULL;
    int index=0;
    while(input_string[index] != '\0'){
        if((input_string[index]>='0' && input_string[index] <='9') || input_string[index] == '-'){
            int number =0,is_negative =1;
            if(input_string[index] == '-'){
                is_negative = -1;
                index++;
            }
            while(input_string[index]>='0' && input_string[index] <='9'){
                number = number *10 + (input_string[index]-'0');
                index++;
            }
            Node* new_node=create_node(number * is_negative);
            if(head == NULL){
                head = temp=new_node;
            }else{
                temp->next = new_node;
                temp= temp->next;
            }
        }
        else{
            index++;
        }
    }
    return head;
}

Node *merge(Node *left, Node *right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    Node *answer = create_node(-1);
    Node *temp = answer;
    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            left = left->next;
            temp = temp->next;
        } else{
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
    }
    if(left!= NULL){
        temp->next = left;
    }
    if(right != NULL){
        temp->next = right;
    }
    answer = answer->next;
    return answer;
}

Node *find_mid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *previous =NULL;
    do
    {
        previous = slow;
        slow = slow->next;
        fast = fast->next->next;
    } while (fast && fast->next);
    previous->next = NULL;
    return slow;
}

Node *merge_sort(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *mid = find_mid(head);
    Node* left = merge_sort(head);
    Node* right = merge_sort(mid);
    Node *result = merge(left,right);
    return result;
}

int count_nodes(Node *head){
    Node *temp = head;
    int count =0;
    while(temp != NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

double calculate_median(Node *head){
    int length = count_nodes(head);
    if(length == 0){
        return 0;
    }
    Node *mid = find_mid(head);
    if(length % 2 ==0){
        return ((mid->data)+ (mid->data-1))/2.0;
    } else{
        return mid->data;
    }
}

int main(){
    char *input_list = (char *)malloc(1024 * sizeof(char));
    if(!input_list){
        return 1;
    }
    scanf("%[^\n]s",input_list);
    getchar();
    char *input_list2 = (char *)malloc(1024 * sizeof(char));
    if(!input_list2){
        return 1;
    }
    scanf("%[^\n]s",input_list2);
    getchar();
    Node * linked_list = parse_input(input_list);
    Node * linked_list2 = parse_input(input_list2);
    Node *linked_list3 = merge(linked_list,linked_list2);
    Node *linked_list4 = merge_sort(linked_list3);
    display(linked_list4);
    double median = calculate_median(linked_list4);
    printf("Median is : %f\n",median);
    return 0;
}