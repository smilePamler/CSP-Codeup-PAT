#include <bits/stdc++.h>

int main() {
    double A[5] = { 0.0 };
    int flag[5] = { 0 };
    int N, i, num, j = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num);
        if (num%5==0 && num%2==0)
        {
            A[0] += num;
            flag[0]++;
        }
        if (num%5==1)
        {
            A[1] += pow(-1, j)*num;
            j++;
            flag[1]++;
        }
        if (num%5==2)
        {
            A[2]++;
            flag[2]++;
        }
        if (num%5==3)
        {
            A[3] += num;
            flag[3]++;
        }
        if (num%5==4)
        {
            if (num>A[4]) A[4] = num;
            flag[4]++;
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (flag[i] > 0)
        {
            if (i < 3) printf("%.0f ", A[i]);
            if (i == 3) printf("%.1f ", A[i]/flag[i]);
            if (i == 4) printf("%.0f\n", A[i]);    
        }
        else
        {
            if (i < 4) printf("N ");
            else printf("N\n");
        }
    }
    return 0;
}