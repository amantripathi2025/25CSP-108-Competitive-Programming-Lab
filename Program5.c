#include <stdio.h>

int reverse_array(int arr[], int n) {
	int i = 0;
	int j = n - 1;
	while (i < j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
	}
	return 0;
}

int rotate_left(int arr[], int n, int k) {
	int i;
	int temp[1000];
	if (n <= 0) {
		return 0;
	}
	k = k % n;
	for (i = 0; i < n; i++) {
		temp[i] = arr[(i + k) % n];
	}
	for (i = 0; i < n; i++) {
		arr[i] = temp[i];
	}
	return 0;
}

int rotate_right(int arr[], int n, int k) {
	int i;
	int temp[1000];
	if (n <= 0) {
		return 0;
	}
	k = k % n;
	for (i = 0; i < n; i++) {
		temp[i] = arr[(i - k + n) % n];
	}
	for (i = 0; i < n; i++) {
		arr[i] = temp[i];
	}
	return 0;
}

int print_array(const int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	printf("\n");
	return 0;
}

int main(void) {
	int n;
	int k;
	char dir;
	int arr[1000];
	int i;

	printf("Enter size of array: ");
	if (scanf("%d", &n) != 1 || n <= 0 || n > 1000) {
		return 0;
	}

	printf("Enter %d elements: ", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	reverse_array(arr, n);
	printf("Reversed array: ");
	print_array(arr, n);

	printf("Enter rotation direction (L/R): ");
	scanf(" %c", &dir);
	printf("Enter rotation count: ");
	if (scanf("%d", &k) != 1) {
		return 0;
	}

	if (dir == 'L' || dir == 'l') {
		rotate_left(arr, n, k);
	} else {
		rotate_right(arr, n, k);
	}

	printf("Rotated array: ");
	print_array(arr, n);

	return 0;
}