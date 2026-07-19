#include <stdio.h>

int main()
{
    int r1, c1, r2, c2;
    int i, j, k;
    printf("Enter rows and columns of First Matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of Second Matrix: ");
    scanf("%d%d", &r2, &c2);
    int A[r1][c1], B[r2][c2];
    int Sum[r1][c1];
    int Product[r1][c2];
    printf("\nEnter elements of First Matrix:\n");
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c1; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Second Matrix:\n");
    for(i = 0; i < r2; i++)
    {
        for(j = 0; j < c2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    if(r1 == r2 && c1 == c2)
    {
        printf("\nMatrix Addition:\n");

        for(i = 0; i < r1; i++)
        {
            for(j = 0; j < c1; j++)
            {
                Sum[i][j] = A[i][j] + B[i][j];
                printf("%d ", Sum[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nMatrix Addition is Not Possible.\n");
    }
    if(c1 == r2)
    {
        printf("\nMatrix Multiplication:\n");

        for(i = 0; i < r1; i++)
        {
            for(j = 0; j < c2; j++)
            {
                Product[i][j] = 0;

                for(k = 0; k < c1; k++)
                {
                    Product[i][j] += A[i][k] * B[k][j];
                }

                printf("%d ", Product[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nMatrix Multiplication is Not Possible.\n");
    }

    return 0;
}