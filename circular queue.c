#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head,*tail;



void enqueue(int value){

    struct Node *newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL){
        head = tail = newnode;
    }else{

        // while( curr->next != tail ){
        //     curr = curr->next;
        // }
        
        tail->next = newnode;
        tail = newnode;

    }
        tail->next = head;

}

void printNodes(){
    if(head == NULL){
        printf("The List is empty");
    }else{
        struct Node *curr = tail->next;

        while(curr->next != tail->next){
            printf("%d \n", curr ->data);
            curr = curr ->next;

        }
        printf("%d", curr->data);
        printf("\n head is %d\n", tail->next->data);
    }
}

void dequeue(){
    
    struct Node *curr = head;
    tail->next = head->next;
    head = head->next;

    free(curr);
}


void main(){
    enqueue(141);
    enqueue(302);
    enqueue(164);
    enqueue(530);
    enqueue(474);

    dequeue();
    printNodes();
    dequeue();
    printNodes();
}