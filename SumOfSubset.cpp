#include <bits/stdc++.h>

using namespace std;

int x[100] = {0}, m, w[100], n, cnt = 0, nosolns = 0;

void displaySubset(int x[], int k, int num)
{
    printf("Subset %d : {", num);
    for (int i = 0; i <= k; i++)
        if (x[i] == 1)
            cout << " " << w[i] << " ";
    printf("}\n------------------------------------------");
}

void display(int x[], int k)
{
    nosolns += 1;
    printf("\n\nSolution %d : {", nosolns);
    for (int i = 0; i <= k; i++)
        cout << " " << x[i] << " ";
    if (k < n)
        for (int i = k + 1; i < n; i++)
            cout << " 0 ";
    printf("}\n");

    displaySubset(x, k, nosolns);
}

void SumOfSubset(int s, int r, int k)
{
    cnt += 1;
    x[k] = 1;

    if (s + w[k] == m)
        display(x, k);

    else if (s + w[k] + w[k + 1] <= m)
        SumOfSubset(s + w[k], r - w[k], k + 1);

    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0;
        SumOfSubset(s, r - w[k], k + 1);
    }
}

int main()
{
    cout << "Enter the total sum required : ";
    cin >> m;
    cout << "Enter the number of items : ";
    cin >> n;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        r += w[i];
    }

    SumOfSubset(0, r, 0);

    cout << "\nNumber of Nodes : " << cnt << endl;

    return 0;
}