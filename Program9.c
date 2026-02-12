#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int current_sum = arr[0];
    int max_sum = arr[0];

    for(int i = 1; i < n; i++) {

        // Decide whether to extend or restart
        if(current_sum + arr[i] > arr[i])
            current_sum = current_sum + arr[i];
        else
            current_sum = arr[i];

        // Update maximum
        if(current_sum > max_sum)
            max_sum = current_sum;
    }

    printf("Maximum subarray sum is: %d\n", max_sum);

    return 0;
}
