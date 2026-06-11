#include <bits/stdc++.h>
using namespace std;

bool isValid(string p)
{
    int n = p.length();
    int c1 = 0, c0 = 0;

    for (int i = 0; i < n; i++) {
        if (p[i] == '0')
            c0++;
        if (p[i] == '1')
            c1++;
    }

    return (c0 == c1) ? true : false;
}

int longestSub(string s)
{
    int max_len = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isValid(s.substr(i, j - i + 1)) && max_len < j - i + 1)
                max_len = j - i + 1;
        }
    }
    return max_len;
}

int main()
{
 
    cout << longestSub(s);

    return 0;
}
