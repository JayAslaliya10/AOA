#include <bits/stdc++.h>
#include <cstring>
#include <math.h>

using namespace std;

#define d 256

void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j, p = 0, t = 0, h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            bool flag = true;
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            }

            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    string text;
    string pattern;

    cout << "Enter the text : ";
    getline(cin, text);
    cout << "Enter the pattern : ";
    getline(cin, pattern);

    char txt[text.length() + 1];
    char pat[pattern.length() + 1];

    strcpy(txt, text.c_str());
    strcpy(pat, pattern.c_str());

    int q = 101;

    search(pat, txt, q);
    return 0;
}