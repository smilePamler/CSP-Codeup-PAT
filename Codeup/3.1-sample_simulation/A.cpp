#include <cstdio>

int main() {
    int L, m;
    while(~scanf("%d%d", &L, &m)) {
        int a[10001] = { 0 };
        if (L == 0 && m == 0) break;
        int i, j, x, y, cnt = 0;
        for (i = 0; i < m; i++)
        {
            scanf("%d%d", &x, &y);
            for (j = x; j <= y; j++)
            {
                a[j] = -1;
            }
        }
        for (i = 0; i <= L; i++)
        {
            if (a[i] == 0)
            {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}