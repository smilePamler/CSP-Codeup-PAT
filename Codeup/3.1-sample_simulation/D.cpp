#include <bits/stdc++.h>

int main() {
    int n;
    while (~scanf("%d", &n))
    {
        int value, i, oddNum = 0, evenNum = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &value);
            if (value % 2 == 0) evenNum++;
            else oddNum++;
        }
        if (oddNum >= evenNum) printf("YES\n");
        else printf("NO\n");
    }  
    return 0;
}