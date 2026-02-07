#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0], min = arr[0];
    int secondLargest = INT_MIN;
    //int secondLargest = -99999;

    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            secondLargest = max;
            max = arr[i];
        } 
        else if(arr[i] > secondLargest && arr[i] != max) {
            secondLargest = arr[i];
        }

        if(arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
    printf("Second Largest = %d\n", secondLargest);

    return 0;
}
