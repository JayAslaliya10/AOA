#include <bits/stdc++.h>
#include <string>

using namespace std;

int changeAds(int num)
{
    vector<int> bin;
    for (int i = 0; num > 0; i++)
    {
        int val = num % 2;
        bin.push_back(val);
        num = num / 2;
    }

    reverse(bin.begin(), bin.end());

    for (int i = 0; i < bin.size(); i++)
    {
        cout << bin[i];
    }
    cout << endl;

    for (int i = 0; i < bin.size(); i++)
    {
        if (bin[i] == 0)
            bin[i] = 1;
        else if (bin[i] == 1)
            bin[i] = 0;
    }

    for (int i = 0; i < bin.size(); i++)
    {
        cout << bin[i];
    }
    cout << endl;

    // std::stringstream str;
    // std::copy(bin.begin(), bin.end(), std::ostream_iterator<int>(str, ""));
    // cout << str.str().c_str() << endl;

    string str="";
    for(auto it:bin)
    {
        str+=std::to_string(it);
    }

    int dec = stoi(str, 0, 2);
    cout << dec << endl;

    return dec;
}

void adRotate(int num)
{
    std::bitset<32> bin(num);
    cout << bin << endl;
    cout << bin.flip() << endl;
}

int main()
{
    int n;

    cin >> n;
    // adRotate(n);
    changeAds(n);

    return 0;
}