#include <stdio.h>
int main() {
    int q[10], n = 10;
    int front = -1, rear = -1;
    int ch, x, i;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 1) {   // Enqueue
            if (rear == n - 1) {
                printf("Queue Overflow");
            } else {
                printf("Enter element: ");
                scanf("%d", &x);
                if (front == -1) front = 0;
                rear++;
                q[rear] = x;
            }}
        else if (ch == 2) {   // Dequeue
            if (front == -1 || front > rear) {
                printf("Queue Underflow");
            } else {
                printf("Deleted element: %d", q[front]);
                front++;
            }  }
        else if (ch == 3) {   // Display
            if (front == -1 || front > rear) {
                printf("Queue is Empty");
} else {
                printf("Queue elements: ");
                for (i = front; i <= rear; i++)
                    printf("%d ", q[i]);
            }
        }
        else if (ch == 4) {
            break;
        }
        else {
            printf("Invalid choice");
        }}
    return 0;
} 
