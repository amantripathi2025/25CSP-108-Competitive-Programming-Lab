#include<stdio.h>
#include<stdlib.h>

int stack[100], MAX = 5, top = -1;

void push(){
    int data;

    printf("Enter your data: \n");
    scanf("%d", &data);

    if(top == MAX - 1){
        printf("Overflow\n");
    }
    else{
        top = top + 1;
        stack[top] = data;
    }
}

void pop(){
    int data;
    if(top == -1){
        printf("Underflow\n");
    }
    else{
        data = stack[top];
        top--;
        printf("Deleted %d\n", data);
    }
}

void trav(){
    int i;

    if(top == -1){
        printf("Stack empty\n");
    }
    else{
        for(i = top; i >= 0; i--){
            printf("%d\n", stack[i]);
        }
    }
}

int main(){
    int c;
    printf("Enter 1 to push: \n");
    printf("Enter 2 to pop: \n");
    printf("Enter 3 to traverse: \n");
    printf("Enter 4 to exit: \n");

    while(1){
        printf("Enter your choice: \n");
        scanf("%d",&c);
        switch(c){
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
            printf("Enter valid choice");
        }
    }
    return 0;
}