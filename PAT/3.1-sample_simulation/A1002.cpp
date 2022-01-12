#include <bits/stdc++.h>

const int M = 1001; 
int main() {
    int i, k;
    double coe[M] = { 0.0 };
    int x;
    double y;
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d%lf", &x, &y);
        coe[x] += y;
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d%lf", &x, &y);
        coe[x] += y;
    }
    int cnt = 0;
    for (i = 0; i < M; i++)
    {
        if (coe[i] != 0) cnt++;        
    }
    printf("%d", cnt);
    for (i = M-1; i >= 0; i--)
    {
        if (coe[i] != 0) printf(" %d %.1f", i, coe[i]);
    }
    return 0;
}
