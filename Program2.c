#include <stdio.h>

#define MAX_SIZE 100

void insert(int arr[], int *n, int pos, int val, int max_size) {
    if (*n >= max_size) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    if (*n == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void printArray(int arr[], int n) {
    printf("Array: {");
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(", ");
        printf("%d", arr[i]);
    }
    printf("}\n");
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int choice, pos, val;

    printf("Enter initial array size (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    if (n > MAX_SIZE) n = MAX_SIZE;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position and value to insert: ");
                scanf("%d %d", &pos, &val);
                insert(arr, &n, pos, val, MAX_SIZE);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 3:
                printArray(arr, n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
