#include <bits/stdc++.h>

int days[13]= { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    int n, y, m, d;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d %d", &y, &m, &d);
        d++;
        if (d > days[m])
        {
            m++;
            d = 1;
        }
        if (m > 12)
        {
            y++;
            m = 1;
        }
        printf("%04d-%02d-%02d\n", y, m, d);
    }
    return 0;
}