#include <stdio.h>

int main(void) {
	int n;
	int arr[1000];
	int freq[1000];
	int i;
	int j;

	printf("Enter size of array: ");
	if (scanf("%d", &n) != 1 || n <= 0 || n > 1000) {
		return 0;
	}

	printf("Enter %d elements: ", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		freq[i] = -1;
	}

	for (i = 0; i < n; i++) {
		int count = 1;
		if (freq[i] != -1) {
			continue;
		}
		for (j = i + 1; j < n; j++) {
			if (arr[i] == arr[j]) {
				count++;
				freq[j] = 0;
			}
		}
		freq[i] = count;
	}

	printf("Frequencies:\n");
	for (i = 0; i < n; i++) {
		if (freq[i] > 0) {
			printf("%d -> %d\n", arr[i], freq[i]);
		}
	}

	printf("Duplicates:\n");
	for (i = 0; i < n; i++) {
		if (freq[i] > 1) {
			printf("%d\n", arr[i]);
		}
	}

	return 0;
}
