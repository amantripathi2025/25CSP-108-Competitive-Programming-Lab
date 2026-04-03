#include <stdio.h>
#include <string.h>
int main() {
    char str[100], stack[100];
    int top = -1, i;
    printf("Enter a string: ");
    gets(str);
    /* Push characters onto stack */
    for(i = 0; str[i] != '\0'; i++) {
        top++;
        stack[top] = str[i];
    }
    /* Pop characters from stack to reverse string */
    for(i = 0; top >= 0; i++) {
        str[i] = stack[top];
        top--;
    }
    printf("Reversed string: %s", str);
    return 0;
} 
