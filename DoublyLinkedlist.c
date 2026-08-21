#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *back;
    int info;
    struct node *forw;
};

struct node *start = NULL;
typedef struct node Node;

void insfirst();
void inslast();
void delfirst();
void dellast(); 
void forTrav();
void backTrav();

int main(){
    int c;
    menu: printf("Enter 1 for insert first: \n");
    printf("Enter 2 for insert at last: \n");
    printf("Enter 3 for delete at first: \n");
    printf("Enter 4 for delete at last: \n");
    printf("Enter 5 for traverse at forward: \n");
    printf("Enter 6 for traverse at back: \n");
    printf("Enter 7 for exit: \n");

    while(1){
        printf("Enter your choice: \n");
        scanf("%d", &c);

        switch(c)
        {
            case 1: 
             insfirst();
             break;

             case 2:
              inslast();
              break;

            case 3:
              delfirst();
              break;
            
            case 4:
              dellast();
              break;
            
            case 5:
              forTrav();
              break;
            
            case 6:
             backTrav();
             break;

            case 7:
              exit(0);

            default:
                printf("!!!!! WRONG CHOICE !!!!!\n");
        }
          
    }
}

void insfirst(){
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &newNode->info);
    
    newNode->back = NULL;
    newNode->forw = start;
    
    if (start != NULL) {
        start->back = newNode;
    }
    start = newNode;
}

void inslast(){
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d", &newNode->info);
    newNode->forw = NULL;
    
    if (start == NULL) {
        newNode->back = NULL;
        start = newNode;
    } else {
        Node *last = start;
        while (last->forw != NULL) {
            last = last->forw;
        }
        newNode->back = last;
        last->forw = newNode;
    }
}

void delfirst(){
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    
    
    Node *ptr = start;
    
    if (start->forw != NULL) {
        start->forw->back = NULL; 
    }
    
    start = start->forw;
    printf("First node deleted\n");
    printf("Deleted node: %d\n",ptr->info);
    free(ptr); 
    
}

void dellast(){
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    
    
    Node *ptr = start;
    
    
    while (ptr->forw != NULL) {
        ptr = ptr->forw;
    }
    
    if (ptr->back != NULL) {
        ptr->back->forw = NULL; 
    } else {
        start = NULL; 
    
    printf("Node Deleted at last\n");
    printf("Deleted node : %d\n", ptr->info); 
    free(ptr);
 }
}

void forTrav(){
    Node *ptr = start;
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->forw;
    }
    printf("\n");
}

void backTrav(){
    Node *ptr = start;
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    
   
    while (ptr->forw != NULL) {
        ptr = ptr->forw;
    }
    
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->back;
    }
    printf("\n");
}