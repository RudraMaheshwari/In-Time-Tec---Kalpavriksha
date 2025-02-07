#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 10

Node *hashTable[TABLE_SIZE];

int hash(int key){
    return key % TABLE_SIZE;
}

void insert(int key, int value){
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    if(hashTable[index] == NULL){
        hashTable[index] = newNode;
    } else{
        Node* current = hashTable[index];
        while(current != NULL){
            if(current->key == key){
                current->value = value;
                free(newNode);
                return;
            }
            current = current->next;
        }
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int search(int key){
    int index = hash(key);
    Node* current = hashTable[index];
    while(current != NULL){
        if(current->key == key){
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void delete(int key){
    int index = hash(key);
    Node* current = hashTable[index];
    Node* prev = NULL;
    while(current != NULL){
        if(current->key == key){
            if(prev == NULL){
                hashTable[index] = current->next;
            } else{
                prev->next = current->next;
            }
            free(current);
            printf("Key %d Deleted.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Key not found: %d\n", key);
}

void display(){
    printf("Hash Table:\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        Node* current = hashTable[i];
        if(current != NULL){
            printf("Index %d: ", i);
            while(current != NULL){
                printf("(%d, %d)", current->key, current->value);
                if(current->next != NULL){
                    printf(" -> ");
                }
                current = current->next;
            }
            printf(" -> NULL\n");
        }
    }
}

int main(){
    int choice, key, value;
    while(1){
        printf("\nMenu:\n");
        printf("1. Insert(Put)\n");
        printf("2. Search(Get)\n");
        printf("3. Delete(Remove)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(key, value);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                value = search(key);
                if(value != -1){
                    printf("Value: %d\n",value);
                } else{
                    printf("Key %d not found\n", key);
                }
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                delete(key);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
