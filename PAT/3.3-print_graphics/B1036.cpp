// 注：很简单一题，错在了循环条件的控制上，花费了很多时间！！！
#include <bits/stdc++.h>

int main() {
    int n, m, i, j;
    char c;
    scanf("%d %c", &n, &c);
    m = (int)round(n*0.5);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(i!=0 && i!=(m-1))
            {
                if (j>0 && j<(n-1)) printf(" ");
                else printf("%c", c);                
            }
            else printf("%c", c);   
        }
        printf("\n");
    }
    return 0;
}