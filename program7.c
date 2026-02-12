#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], prefix[n];

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Compute Prefix Sum
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int l, r;
    printf("Enter left and right index: ");
    scanf("%d %d", &l, &r);

    int sum;

    if(l == 0)
        sum = prefix[r];
    else
        sum = prefix[r] - prefix[l - 1];

    printf("Subarray sum from index %d to %d is: %d\n", l, r, sum);

    return 0;
}
