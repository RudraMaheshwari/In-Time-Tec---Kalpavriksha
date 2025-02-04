#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum passenger{
    VIP,
    SENIOR_CITIZEN,
    GENERAL,
};

typedef struct{
    int passenger_id;
    enum passenger Passenger_type;
    char name[50];
} Passenger;

enum passenger check_passenger(char *type) {
    if(strcmp(type, "VIP") == 0){
        return VIP;
    } else if(strcmp(type, "SENIOR_CITIZEN") == 0){
        return SENIOR_CITIZEN;
    } else if(strcmp(type, "GENERAL") == 0){
        return GENERAL;
    } else{
        return -1;
    }
}

char *covert_string(enum passenger type) {
    if(type == VIP){
        return "VIP";
    } else if(type == SENIOR_CITIZEN){
        return "SENIOR_CITIZEN";
    } else if(type == GENERAL){
        return "GENERAL";
    } else{
        return "NULL";
    }
}

void bubble_sort(Passenger *queue, int queue_size){
    if(queue_size <= 1){
        return;
    }
    for(int i=0;i<queue_size;i++){
        for(int j=0;j<queue_size-1-i;j++){
            if(queue[j].Passenger_type > queue[j+1].Passenger_type){
                Passenger temp = queue[j];
                queue[j] = queue[j+1];
                queue[j+1] = temp;
            }
        }
    }
}

void enqueue(Passenger *passenger,Passenger *queue, int *rear, int *front, int *queue_size){
    if(*rear == (*queue_size) -1){
        printf("Queue Overflow.\n");
        return;
    } else if(*front == -1 && *rear == -1){
        *front = *rear = 0;
        queue[*rear] = *passenger;
    } else{
        (*rear)++;
        queue[*rear] = *passenger;
    }
    bubble_sort(queue,(*rear)- (*front) +1);
    printf("Element inserted in Queue.\n");
}

void dequeue(Passenger *queue,int *rear, int *front){
    if(*front == -1 && *rear == -1){
        printf("Queue Underflow.\n");
        return;
    } else if(*front == *rear){
        printf("ID : %d, Passenger Type: %s, Passenger Name: %s.\n",queue[*front].passenger_id,covert_string(queue[*front].Passenger_type),queue[*front].name);
        *front = *rear =-1;
    } else{
        printf("Serving Passenger:\n");
        printf("ID : %d, Passenger Type: %s, Passenger Name: %s.\n",queue[*front].passenger_id,covert_string(queue[*front].Passenger_type),queue[*front].name);
        (*front)++;
    }
}

void display(Passenger *queue,int *rear, int *front){
    if(*front == -1 && *rear == -1){
        return;
    }
    printf("Waiting Passenger:\n");
    for(int index = *front; index < *rear +1;index++){
        printf("ID : %d, Passenger Type: %s, Passenger Name: %s.\n",queue[index].passenger_id,covert_string(queue[index].Passenger_type),queue[index].name);
    }
}

int main(){ 
    int choice,front =-1,rear =-1, no_of_operations,queue_size;
    char *type= (char *)malloc(20 * sizeof(char));
    printf("Enter No.of Operations:\n");
    scanf("%d",&no_of_operations);
    Passenger *queue = (Passenger *)malloc(no_of_operations * sizeof(Passenger));
    if(!queue){
        return 1;
    }
    Passenger passenger;
    while(no_of_operations){
        scanf("%d",&choice);
        switch(choice){
            case 1: 
            scanf(",%d,%[^,],\"%[^\"]\";",&passenger.passenger_id,type,passenger.name);
            passenger.Passenger_type = check_passenger(type);
            enqueue(&passenger,queue,&rear,&front,&no_of_operations);
            break;
            case 2:
            dequeue(queue,&rear,&front);
            break;
            case 3:
            display(queue,&rear,&front);
            break;
            default:
            printf("Invalid Choice..!");
            return 1;
        }
        no_of_operations--;
    }
    free(queue);
    return 0;
}



