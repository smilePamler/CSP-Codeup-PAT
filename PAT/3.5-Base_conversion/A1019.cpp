#include <bits/stdc++.h>

int main() {
    int n, b, ans[31];
    scanf("%d%d", &n, &b);
    int num = 0, i;
    bool flag = true;
    do
    {
        ans[num++] = n % b;
        n = n / b;
    } while (n != 0);
    for (i = 0; i < num/2; i++)
    {
        if (ans[i] != ans[num-i-1])
        {
            flag = false;
        }
    }
    if (flag == true) printf("Yes\n");
    else printf("No\n");
    for (i = num-1; i >= 0; i--)
    {
        if(i > 0) printf("%d ", ans[i]);
        else printf("%d", ans[i]);
    }
    return 0;
}