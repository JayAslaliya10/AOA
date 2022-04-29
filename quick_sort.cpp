// #include <bits/stdc++.h>

// using namespace std;

// int partition(int A[], int l, int h, int len)
// {
//     int pivot = A[h];
//     int i = (l - 1);

//     // do
//     // {
//     //     do
//     //     {
//     //         i++;
//     //     } while (A[i] < pivot);
//     //     do
//     //     {
//     //         j--;
//     //     } while (A[j] > pivot);

//     //     if (i < j)
//     //         std::swap(A[i], A[j]);
//     // } while (i < j);

//     for (int j = l; j < len; j++)
//     {
//         if (A[j] < pivot)
//         {
//             i++;
//             swap(A[i], A[j]);
//         }
//     }
//     swap(A[i + 1], A[h]);

//     for (int k = 0; k < len; k++)
//     {
//         printf("%d \t", A[k]);
//     }
//     printf("\n");

//     return (i + 1);
// }

// void QuickSort(int A[], int l, int h, int len)
// {
//     if (l < h)
//     {
//         int j = partition(A, l, h, len);
//         QuickSort(A, l, j - 1, len);
//         QuickSort(A, j + 1, h, len);
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

//     QuickSort(A, 0, n - 1, n);

//     cout << "Array after sorting : " << endl;
//     for (int i = 0; i < n; i++)
//         cout << A[i] << "\t";

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int len;

int Partition(int A[], int l, int h)
{
    int pivot = A[h];
    int i = (l - 1);

    for (int j = l; j < len; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
        swap(A[i + 1], A[h]);
    }

    for (int k = 0; k < len; k++)
        cout << A[k] << "\t";
    cout << endl;

    return (i + 1);
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = Partition(A, l, h);
        QuickSort(A, l, j - 1);
        QuickSort(A, j + 1, h);
    }
}

int main()
{
    cout << "Enter the numbeer of elements : ";
    cin >> len;
    int A[len];

    cout << "Enter the elements : " << endl;
    for (int i = 0; i < len; i++)
        cin >> A[i];

    cout << "Length = " << len << endl;

    QuickSort(A, 0, len - 1);

    cout << "Array after sorting : " << endl;
    for (int i = 0; i < len; i++)
        cout << A[i] << "\t";

    return 0;
}