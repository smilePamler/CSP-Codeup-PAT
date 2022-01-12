#include <bits/stdc++.h>

int main() {
    char a[10], b[10];
    while (~scanf("%s%s", &a, &b))
    {
        int len1 = strlen(a);
        int len2 = strlen(b);
        int i, j, res = 0;
        for (i = 0; i < len1; i++)
        {
            for (j = 0; j < len2; j++)
            {
                res += (a[i]-'0') * (b[j]-'0');
            }
        }
        printf("%d\n", res);
    }
    return 0;
}