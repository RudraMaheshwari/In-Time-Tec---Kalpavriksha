#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int id;
    char *level;
    struct node *next;
} Node;

Node *create_node(int id, char * severity_level){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->id = id;
    new_node->level = (char *)malloc(20 * sizeof(char));
    new_node->level = severity_level;
    new_node->next = NULL;
    return new_node;
}

int get_index(char* severityLevel, char* levels[]){
    for(int index=0; index<3; index++){
        if(!strcmp(severityLevel, levels[index])){
            return index;
        }
    }
    return -1;
}

void display(Node *head){    
    Node *temp = head;
    while(temp != NULL){
        printf("%d %s\n",temp->id,temp->level);
        temp = temp->next;
    }
    printf("\n");
}

Node *merge(Node *left, Node *right, char *levels[]){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    Node *answer = create_node(-1,"dummy");
    Node *temp = answer;
    while(left != NULL && right != NULL){
        if(get_index(left->level,levels) <= get_index(right->level,levels)){
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

Node *merge_sort(Node *head, char *levels[]){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *mid = find_mid(head);
    Node* left = merge_sort(head,levels);
    Node* right = merge_sort(mid,levels);
    Node *result = merge(left,right,levels);
    return result;
}

int id_present(Node *head, int id){
    Node *temp = head;
    while(temp != NULL){
        if(temp->id == id){
            printf("Id already Exist.\n");
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){
    int no_of_patients,id;
    Node *head = NULL;
    scanf("%d",&no_of_patients);
    char* levels[3] = {"Critical", "Serious", "Stable"};
    while(no_of_patients){
        char *severity_level= (char *)malloc(20 * sizeof(char));
        scanf("%d %s",&id,severity_level);
        if(get_index(severity_level, levels) == -1 || id_present(head,id)){
            printf("Invalid Input\n");
            continue;
        }
        Node *new_node = create_node(id,severity_level);
        if(!head){
            head = new_node;
        } else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new_node;
        }
        no_of_patients--;
    }
    Node *linked_list_sorted = merge_sort(head, levels);
    printf("\n");
    display(linked_list_sorted);
    return 0;
}