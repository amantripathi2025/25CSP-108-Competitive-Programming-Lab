#include <stdio.h>
int main() {
    int a[100], stack[100], nge[100];
    int n, i, top = -1;
    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = n - 1; i >= 0; i--) {
        while(top != -1 && stack[top] <= a[i])
         top--;
        if(top == -1)
            nge[i] = -1;
        else
            nge[i] = stack[top];
        stack[++top] = a[i];    }
    printf("\nElement -> Next Greater Element\n");
    for(i = 0; i < n; i++)
        printf("%d -> %d\n", a[i], nge[i]);
   return 0;}
