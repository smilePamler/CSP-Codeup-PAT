#include <bits/stdc++.h>

int main() {
    int A, B, D, Res;
    scanf("%d %d %d", &A, &B, &D);
    Res = A + B;
    int ans[31], i = 0;
    do{
        ans[i++] = Res % D;
        Res = Res / D;
    } while (Res != 0);
    for (i = i-1; i >= 0; i--)
    {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}