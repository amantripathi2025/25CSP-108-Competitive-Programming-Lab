#include <stdio.h>
#include<stdlib.h>
 int main() {
    int q[100], n, front = -1, rear = -1;
    int choice, x, i;
    printf("Enter queue size: ");
    scanf("%d", &n);
    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // Enqueue
                if(rear == n - 1)
                    printf("Queue Overflow");
                else {
                    if(front == -1) front = 0;
                    printf("Enter element: ");
                    scanf("%d", &x);
                    q[++rear] = x;
                }
                break;
             case 2: // Dequeue
                if(front == -1 || front > rear)
                    printf("Queue Underflow");
                else {
                    printf("Deleted: %d", q[front++]);
                }
                break;
 
            case 3: // Display
                if(front == -1 || front > rear)
                    printf("Queue is empty");
                else {
                    printf("Queue elements: ");
                    for(i = front; i <= rear; i++)
                        printf("%d ", q[i]);
                }
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice");
        }    } while(choice != 4);
     return 0;
    }
