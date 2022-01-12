#include <bits/stdc++.h>

int main() {
    int ans[10] = { 0 };
    char n[1000];
    int i, len;
    scanf("%s", n);
    len = strlen(n);
    for (i = len-1; i >= 0; i--)
    {
        ans[n[i]-'0']++;
    }
    for (i = 0; i < 10; i++)
    {
        if (ans[i] != 0)
        {
            printf("%d:%d\n", i, ans[i]);
        }
    }
    return 0;
}