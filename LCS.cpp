// #include <bits/stdc++.h>

// using namespace std;

// int dp[1005][1005];

// int LongetsCommonSubsequence(char A[], char B[], int i, int j, int m, int n)
// {
//     // if (i == m || j == n)
//     //     return 0;

//     // if (dp[i][j] != -1)
//     //     return dp[i][j];

//     // else if (A[i] == B[j])
//     //     return 1 + LongetsCommonSubsequence(A, B, i + 1, j + 1, m, n);

//     // else
//     //     return max(LongetsCommonSubsequence(A, B, i + 1, j, m, n), LongetsCommonSubsequence(A, B, i, j + 1, m, n));

//     if (i == m || j == n)
//         return 0;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int ans = LongetsCommonSubsequence(A, B, i + 1, j, m, n);
//     ans = max(ans, LongetsCommonSubsequence(A, B, i, j + 1, m, n));
//     ans = max(ans, (LongetsCommonSubsequence(A, B, i + 1, j + 1, m, n) + (A[i] == B[j])));
//     return dp[i][j] = ans;
// }

// int LongetsCommonSubstring(char A[], char B[], int m, int n)
// {

//     int lcs[m + 1][n + 1];
//     int result = 0;

//     for (int i = 0; i <= m; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             if (i == 0 || j == 0)
//                 lcs[i][j] = 0;

//             else if (A[i - 1] == B[j - 1])
//             {
//                 lcs[i][j] = lcs[i - 1][j - 1] + 1;
//                 result = max(result, lcs[i][j]);
//             }
//             else
//                 lcs[i][j] = 0;
//         }
//     }
//     return result;
// }

// int main()
// {
//     string str1, str2;
//     memset(dp, -1, sizeof(dp));

//     cout << "Enter the first string : ";
//     getline(cin, str1);
//     cout << "Enter the second string : ";
//     getline(cin, str2);

//     int m = str1.length();
//     int n = str2.length();

//     char st1[m + 1];
//     char st2[n + 1];

//     strcpy(st1, str1.c_str());
//     strcpy(st2, str2.c_str());

//     cout << LongetsCommonSubsequence(st1, st2, 0, 0, m, n);
//     // abcdefghijklmnopqrstuvwxyz

//     // cout << LongetsCommonSubstring(st1, st2, m, n);

//     return 0;
// }

// =========================================================================================================================

#include <bits/stdc++.h>

using namespace std;

int b[1000][1000];

void print_LCS(int b[100][1000], char st1[], int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == 3)
    {
        print_LCS(b, st1, i - 1, j - 1);
        cout << st1[i - 1];
    }
    else if (b[i][j] == 1)
        print_LCS(b, st1, i - 1, j);
    else
        print_LCS(b, st1, i, j - 1);
}

void LCS(char st1[], char st2[])
{
    int m = strlen(st1);
    int n = strlen(st2);
    int c[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++)
        c[i][0] = 0;
    for (int i = 1; i < n + 1; i++)
        c[0][i] = 0;

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (st1[i - 1] == st2[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 3;
            }
            else if (c[i - 1][j] > c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2;
            }
        }
    }

    cout << "\nTotal length of characters : " << c[m][n] << endl;
    cout << "LCS string : ";
    print_LCS(b, st1, m, n);
    cout << endl;
}

int main()
{
    // string str1,str2;
    // memset(dp,-1,sizeof(dp));

    char str1[100], str2[1000];

    cout << "Enter the first string : ";
    cin >> str1;
    cout << "Enter the second string : ";
    cin >> str2;

    // int m=str1.length();
    // int n=str2.length();

    // char st1[m+1];
    // char st2[n+1];

    LCS(str1, str2);

    return 0;
}