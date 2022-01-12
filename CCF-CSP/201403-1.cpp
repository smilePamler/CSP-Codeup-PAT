#include <bits/stdc++.h>

int main() {
    int N, cnt = 0;
    scanf("%d", &N);
    int p_flag[1005] = { 0 }, n_flag[1005] = { 0 }, s;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &s);
        if (s > 0) p_flag[s] = 1;
        else n_flag[-s] = 1;
    }
    for (int i = 1; i <= 1000; i++)
    {
        if (n_flag[i] == 1 && p_flag[i] == 1) cnt++;
    }
    printf("%d", cnt);
    return 0;
}