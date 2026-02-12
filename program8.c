#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter target sum: ");
    scanf("%d", &target);

    int left = 0;
    int right = n - 1;
    int found = 0;

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(sum == target) {
            printf("Pair found: %d and %d\n", arr[left], arr[right]);
            found = 1;
            break;
        }
        else if(sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    if(!found) {
        printf("No pair found.\n");
    }

    return 0;
}
