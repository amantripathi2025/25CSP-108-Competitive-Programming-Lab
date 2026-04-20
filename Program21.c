#include <stdio.h>
#define SIZE 5
 int main() {
    int cq[SIZE], front = -1, rear = -1;
    int choice, item, i;
    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
        case 1: // Enqueue
            if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
                printf("Circular Queue is Full\n");
            } else {
                printf("Enter element: ");
                scanf("%d", &item);
                if (front == -1) {
                    front = rear = 0;
                } else if (rear == SIZE - 1) {
                    rear = 0;
                } else {
                    rear++;
                }
                cq[rear] = item;
            }
            break;
        case 2: // Dequeue
            if (front == -1) {
                printf("Circular Queue is Empty\n");
} else {
                printf("Deleted element: %d\n", cq[front]);
               if (front == rear) {
                    front = rear = -1;
                } else if (front == SIZE - 1) {
                    front = 0;
                } else {
                    front++;
                }
            }
            break;
        case 3: // Display
            if (front == -1) {
                printf("Circular Queue is Empty\n");
            } else {
                printf("Queue elements: ");
                i = front;
                while (1) {
                    printf("%d ", cq[i]);
                    if (i == rear)
                        break;
                    i = (i + 1) % SIZE;
                }
            }
            break;
         case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");     }
    } while (choice != 4);
   return 0;
}
