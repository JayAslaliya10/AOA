// #include <stdio.h>
// #include <stdlib.h>

// void Swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// void InsertionSort(int A[], int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int j = i - 1;
//         int x = A[i];

//         while (j > -1 && A[j] > x)
//         {
//             A[j + 1] = A[j];
//             j--;
//         }
//         A[j + 1] = x;

//         for (int k = 0; k < n; k++)
//         {
//             printf("%d\t", A[k]);
//         }
//         printf("\n");
//     }
// }

// int main()
// {

//     int n;
//     printf("Enter the number of elements : ");
//     scanf("%d", &n);

//     int A[n];

//     printf("Enter the elements : \n");

//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &A[i]);
//     }

//     InsertionSort(A, n);

//     printf("Sorted Array : \n");

//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\t", A[i]);
//     }

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

void InsertionSort(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = A[i];
        int j = i - 1;

        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;

        for (int k = 0; k < n; k++)
        {
            cout << A[k] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    int A[n];
    cout << "Enter the elememts : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    InsertionSort(A, n);

    cout << "Sorted Array :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "\t";
    }
    cout << endl;

    return 0;
}