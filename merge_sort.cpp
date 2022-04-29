// #include <bits/stdc++.h>

// using namespace std;

// void Merge(int A[], int l, int mid, int h, int len)
// {
//     int i = l, j = mid + 1, k = l;
//     int B[len];

//     while (i <= mid && j <= h)
//     {
//         if (A[i] < A[j])
//             B[k++] = A[i++];
//         else
//             B[k++] = A[j++];
//     }
//     for (; i <= mid; i++)
//         B[k++] = A[i];
//     for (; j <= h; j++)
//         B[k++] = A[j];

//     for (i = l; i <= h; i++)
//         A[i] = B[i];

//     for (int k = 0; k < len; k++)
//     {
//         printf("%d \t", A[k]);
//     }
//     printf("\n");
// }

// void MergeSort(int A[], int l, int h, int len)
// {
//     int mid;
//     if (l < h)
//     {
//         mid = (l + h) / 2;
//         MergeSort(A, l, mid, len);
//         MergeSort(A, mid + 1, h, len);
//         Merge(A, l, mid, h, len);
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter the numbeer of elements : ";
//     cin >> n;
//     int A[n];

//     for (int i = 0; i < n; i++)
//         cin >> A[i];

//     MergeSort(A, 0, n - 1, n);
//     cout << "Array after sorting : " << endl;
//     for (int i = 0; i < n; i++)
//         cout << A[i] << "\t";

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int len;

void Merge(int A[], int l, int mid, int h)
{
    int B[len];
    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}

void MergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int main()
{
    cout << "Enter the number of elements : ";
    cin >> len;
    int A[len];

    cout << "Enter the elements :" << endl;
    for (int i = 0; i < len; i++)
        cin >> A[i];

    MergeSort(A, 0, len - 1);
    cout << "Array after sorting : " << endl;
    for (int i = 0; i < len; i++)
        cout << A[i] << "\t";

    return 0;
}