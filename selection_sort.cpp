#include <stdio.h>
#include <stdlib.h>

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int A[], int n)
{
    int i, j;

    for (int i = 0; i < n; i++)
    {
        int smallest = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (A[j] < A[smallest])
                smallest = j;
        }
        Swap(&A[i], &A[smallest]);

        for (int k = 0; k < n; k++)
        {
            printf("%d \t", A[k]);
        }
        printf("\n");
    }
}

int main()
{

    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    int A[n];

    printf("Enter the elements : \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    SelectionSort(A, n);

    printf("Sorted Array : \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d \t", A[i]);
    }

    return 0;
}