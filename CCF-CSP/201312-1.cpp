#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, s, max_num = 0, cnt[10005] = { 0 };
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s);
        cnt[s]++;
        if (s > max_num) max_num = s;
    }
    int max = 0, res = 0;
    for (i = 1; i <= max_num; i++)
    {
        if (cnt[i] > max)
        {
            max = cnt[i];
            res = i;
        }
    }
    printf("%d", res);
    return 0;
}