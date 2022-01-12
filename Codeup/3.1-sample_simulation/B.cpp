#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    char A[20], B[20];
    while(~scanf("%s%s", A, B)) {
        int len1 = strlen(A);
        int len2 = strlen(B);
        int i, k = 1, j = 1, a = 0, b = 0;
        long long res = 0;
        for (i = len1-1; i >= 0; i--)
        {
            switch (A[i])
            {
            case ',':
                break;
            case '-':
                a *= (-1);
                break;
            default:
                // a += (A[i]-'0') * pow(10, k); // pow()函数参数传入两个int型，易出错
                a += (A[i]-'0') * j;
                j *= 10;
                break;
            }
        }
        for (i = len2-1; i >= 0; i--)
        {
            switch (B[i])
            {
            case ',':
                break;
            case '-':
                b *= (-1);
                break;
            default:
                // b += (B[i]-'0') * pow(10, j);
                b += (B[i]-'0') * k;
                k *= 10;
                break;
            }
        }
        // printf("%d %d\n", a, b);
        res = a + b;
        printf("%lld\n", res);
    }
    return 0;
}