#include <bits/stdc++.h>

int w[17] = { 7, 9, 10, 5, 8, 4, 2, 1,
            6, 3, 7, 9, 10, 5, 8, 4, 2 };
char M[11] = { '1', '0', 'X', '9', '8',
             '7', '6', '5', '4', '3', '2' };

int main() {
    int n, i, j, cnt = 0;
    scanf("%d", &n);
    char id[n][20]; // 字符数组必须比欲存入的字符串长度大，因为最后必须存'\0'
    for (i = 0; i < n; i++)
    {
        scanf("%s", id[i]);
    }
    for (i = 0; i < n; i++)
    {
        int sum = 0;
        for (j = 0; j < 18; j++)
        {
            if (j<17 && id[i][j]>='0' && id[i][j]<='9')
            {
                sum += (id[i][j]-'0') * w[j];
            }
            else if(j<17 && (id[i][j]<'0' || id[i][j]>'9'))
            {
                printf("%s\n", id[i]);
                break;
            }
            else if (j==17)
            {
                if (id[i][j]!=M[sum%11])
                {
                    printf("%s\n", id[i]);
                    break;
                }
                else cnt++;
            }
        }
    }
    if (cnt == n) printf("All passed\n");
    return 0;
}