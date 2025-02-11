#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char ch;
    int count;
}hash_map;

int map_search(hash_map *map, char ch,int map_size){
    for(int i=0;i<map_size;i++){
        if(map[i].ch == ch){
            return i;
        }
    }
    return -1;
}

void enqueue(char *queue, int *front, int *rear, char ch){
    queue[*rear] = ch;
    (*rear)++;
}

char dequeue(char *queue, int *front, int *rear){
    if(*front == *rear){
        return '\0';
    }
    char ch = queue[*front];
    (*front)++;
    return ch;
}

int main(){
    hash_map *map = (hash_map *)malloc(sizeof(hash_map));
    if(!map){
        return 1;
    }
    char *input = (char *)malloc(100000 * sizeof(char));
    if(!input){
        free(map);
        return 1;
    }
    char *result = (char *)malloc(10000 * sizeof(char));
    scanf("%[^\n]",input);
    int i =0, map_size =0,front =0,rear =0,result_index =0;
    char *queue = (char *)malloc(100000 * sizeof(char));
    while(input[i] != '\0'){
        char ch = input[i];
        int index = map_search(map,ch,map_size);
        if(index == -1){
            map[map_size].ch = ch;
            map[map_size].count = 1;
            map_size++;
        } else{
            map[index].count++;
        }
        enqueue(queue, &front, &rear, ch);

        while(front != rear && map[map_search(map, queue[front], map_size)].count > 1){
            dequeue(queue, &front, &rear);
        }

        if(front == rear){
            result[result_index++] = '-';
            result[result_index++] = '1';
        } else{
            result[result_index++] = queue[front];
        }
        i++;
    }
    result[result_index] = '\0';
    printf("%s\n", result);
    free(map);
    free(input);
    free(queue);
    free(result);
    return 0;
}
