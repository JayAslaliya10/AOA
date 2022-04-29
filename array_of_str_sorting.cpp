// #include <bits/stdc++.h>

// using namespace std;

// struct Node
// {
//     string data;
//     struct Node *next;
// } *first = NULL;

// void Create(string A[], int n)
// {
//     struct Node *t, *last;

//     first = new Node;
//     first->data = A[0];
//     first->next = NULL;
//     last = first;

//     for (int i = 1; i < n; i++)
//     {
//         t = new Node;
//         t->data = A[i];
//         t->next = NULL;
//         last->next = t;
//         last = t;
//     }
// }

// void Reverse(struct Node *head)
// {
//     struct Node *p = head;
//     struct Node *q = NULL, *r = NULL;

//     while (p != NULL)
//     {
//         r = q;
//         q = p;
//         p = p->next;
//         q->next = r;
//     }
//     first = q;
// }

// void Sort(string A[], int n)
// {
//     std::sort(A, A + n);
// }

// void Display(struct Node *p)
// {
//     while (p != NULL)
//     {
//         cout << p->data << "\t";
//         p = p->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     string arr[n];

//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     // Create(arr, n);
//     // Reverse(first);
//     // Display(first);

//     Sort(arr, n);
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << "\t";

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

string breakPalindrome(string str)
{
    if (str.length() <= 1)
        return "IMPOSSIBLE";

    if (str.length() % 2 == 0)
    {
        int i = 0;
        while (i < str.length() && str[i] == 'a')
        {
            i++;
        }
        if (i != str.length() && str[i] != 'a')
        {
            str[i] = 'a';
            return str;
        }
        else
            return "IMPOSSIBLE";
    }
    else
    {
        // odd
        int i = 0;
        while (i < str.length() / 2 && str[i] == 'a')
        {
            i++;
        }
        if (i != str.length() / 2)
        {
            str[i] = 'a';
            return str;
        }
        else
        {
            int j = str.length() / 2 + 1;
            while (j < str.length() && str[j] == 'a')
            {
                j++;
            }
            if (j != str.length() && str[j] != 'a')
            {
                str[j] = 'a';
                return str;
            }
            else
                return "IMPOSSIBLE";
        }
    }
}

int main()
{

    cout<<breakPalindrome("bab")<<endl;

    return 0;
}
