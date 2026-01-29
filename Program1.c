



#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of the array; ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Array of the elements are: {");
    for(int i=0; i<n; i++){
        if(i>0){
            printf(", ");
        }
        printf("%d", arr[i]);
    }
    printf("}");
    return 0;
}