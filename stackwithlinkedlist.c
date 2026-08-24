#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node *link;
} NODE;

NODE *top = NULL;

void push() {
    NODE *newNode;
    int data;

    printf("Enter the data: \n");
    scanf("%d", &data);
    newNode = (NODE *)malloc(sizeof(NODE));
    newNode->info = data;
    newNode->link = NULL;
    if (top == NULL) {
        top = newNode;
    }
    else {
        newNode->link = top;
        top = newNode;
    }
}

void pop() {
    // NODE *temp = top;
    int data;

    if (top == NULL) {
        printf("Stack Underflow\n");
    }
    else {
        data = top->info;
        top = top->link;
        printf("Deleted data = %d\n", data);
    }
}

void trav() {
    NODE *ptr;
    if (top == NULL) {
        printf("Stack is empty\n");
    }
    else {
        ptr = top;
        while (ptr != NULL) {
            printf("%d\n", ptr->info);
            ptr  = ptr->link;
        }
    }
}

int main() {
    int c;
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Traverse");
        printf("\n4. Exit");
       
        while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                trav();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}