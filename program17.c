#include <stdio.h>
int main() {    int t;
    scanf("%d", &t);
    while(t--) {      int n, m, maxSum;
        scanf("%d %d %d", &n, &m, &maxSum);
        int a[1000], b[1000];
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < m; i++) scanf("%d", &b[i]);
        int sum = 0, i = 0, j = 0, maxCount = 0;
        while(i < n && sum + a[i] <= maxSum) {       sum += a[i];
            i++;        }
        maxCount = i;
        while(j < m) {    sum += b[j];
            j++;
            while(sum > maxSum && i > 0) {
                i--;
                sum -= a[i];      }
            if(sum <= maxSum && i + j > maxCount)
                maxCount = i + j;
        }
        printf("%d\n", maxCount);}
    return 0;}
