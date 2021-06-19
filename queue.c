#include<stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
};
struct Queue *start;

// Adding data to the Queue
void enQueue(int value){
struct Queue *temp;
temp = (struct Queue *)malloc(sizeof(struct Queue));

temp->next = NULL;
temp->data = value;

if(start == NULL){
    start = temp;
}else{
    struct Queue *curr = start;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
}

}


// deQueue is for removing the first in element from the list

void deQueue(){
    struct Queue *temp = start;
    printf("%d is removed from the queue\n New Queue\n", temp->data);
    temp = start;
    start = start->next;
    free(temp);
}


void printNodes(){
    if(start == NULL){
        printf("The List is empty");
    }else{
        struct Queue *curr = start;
        while(curr != NULL){
            printf("%d \n", curr ->data);
            curr = curr ->next;

        }
    }
}


// Queue is First In First Out
void main(){
    enQueue(141);
    enQueue(302);
    enQueue(164);
    enQueue(530);
    enQueue(474);

    printNodes();
    deQueue();
    printNodes();
}