#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_node(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* partition(Node* head, Node* end, Node** new_head, Node** new_end) {
    Node* pivot = head;
    Node* prev = NULL, *cur = head->next, *tail = pivot;
    *new_head = pivot;
    *new_end = pivot;
    while (cur != end->next) {
        if (cur->data < pivot->data) {
            if (*new_head == pivot) {
                *new_head = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) {
                prev->next = cur->next;
            }
            Node* temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    *new_end = tail;
    return pivot;
}

Node* quick_sort_kth(Node* head, Node* end, int k) {
    if (!head || head == end) {
        return head;
    }
    Node *new_head = NULL, *new_end = NULL;
    Node* pivot = partition(head, end, &new_head, &new_end);
    int count = 0;
    Node* temp = new_head;
    while (temp != pivot) {
        count++;
        temp = temp->next;
    }
    if (count == k - 1) {
        return pivot;
    }
    if (count > k - 1) {
        return quick_sort_kth(new_head, pivot, k);
    } 
    return quick_sort_kth(pivot->next, new_end, k - count - 1);
}

int find_kth_smallest(Node* head, int k) {
    Node* end = head;
    while (end->next != NULL) {
        end = end->next;
    }
    Node* result = quick_sort_kth(head, end, k);
    return result->data;
}

int main() {
    Node *head = NULL;
    Node *temp = NULL;
    int array_size, kth_element;
    printf("Enter Array Size:\n");
    scanf("%d", &array_size);
    int *array = (int *)malloc(array_size * sizeof(int));
    if (!array) {
        return 1;
    }
    printf("Enter Array Elements:\n");
    for (int index = 0; index < array_size; index++) {
        scanf("%d", &array[index]);
    }
    for (int index = 0; index < array_size; index++) {
        Node *new_node = create_node(array[index]);
        if (!head) {
            head = new_node;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    printf("\nLinked List is:\n");
    display(head);

    printf("Enter kth (smallest element) you want to find:\n");
    scanf("%d", &kth_element);

    int kth_smallest = find_kth_smallest(head, kth_element);
    printf("The %dth smallest element is %d\n", kth_element, kth_smallest);
    free(array);
    return 0;
}
