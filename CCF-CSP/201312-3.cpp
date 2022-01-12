#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m = 0, res = 0;
    scanf("%d", &n);
    int h[n];
    for(int i = 0; i < n; i++) // i 相当于每个元素的别名
    {
        scanf("%d", &h[i]);
    }
    for (int i = 0; i < n; i++)
    {
        m = h[i];
        for (int j = i; j < n; j++)
        {
            m = min(m, h[j]);
            res = max(res, m*(j-i+1));
        }
    }
    printf("%d", res);
    return 0;
}