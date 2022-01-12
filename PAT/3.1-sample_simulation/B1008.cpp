// 三次逆置
// 注意：题目中未说明M < N
// 注意：M可能为0
#include <bits/stdc++.h>

void reverse(int a[], int n, int low, int high)
{
    int i, j, temp;
    for (i = low, j = 0; i <= (high+low)/2; i++, j++)
    {
        temp = a[i];
        a[i] = a[high-j];
        a[high-j] = temp;
    }
}

int main() {
    int N, M, i;
    scanf("%d%d", &N, &M);
    M = M % N;
    int inte[N];
    for (i = 0; i < N; i++)
        scanf("%d", &inte[i]);
    if (M > 0)
    {
        reverse(inte, N, 0, N-1);
        reverse(inte, N, 0, M-1);
        reverse(inte, N, M, N-1);
    }
    for (i = 0; i < N; i++)
    {
        if (i != N-1) printf("%d ", inte[i]);
        else printf("%d\n", inte[i]);   
    }
    return 0;
}