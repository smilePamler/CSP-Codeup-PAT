#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    int b, s, g, i;
    b = n / 100;
    s = (n % 100) / 10;
    g = n % 10;
    for (i = 0; i < b; i++)
        printf("B");
    for (i = 0; i < s; i++)
        printf("S");
    for (i = 1; i <= g; i++)
        printf("%d", i);
    return 0;
}