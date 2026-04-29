#include <stdio.h>
int main() {
    int q, type, x;
    int queue[100000], front = 0, rear = 0;
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d", &x);
            queue[rear++] = x; 
        }
        else if(type == 2)
         {
            front++;  
        
        }
        else if(type == 3)
        {
            printf("%d\n", queue[front]);
        }  
      }
    return 0;
}
