#include <bits/stdc++.h>

int main() {
    int N;
    while (~scanf("%d", &N))
    {
        int i, value;
        double j = 0.0;
        int A[6] = { 0 }, flag[6] = { 0 };
        for (i = 0; i < N; i++)
        {
            scanf("%d", &value);
            if (value%5 == 0 && value%2 == 0)
            {
                A[1] += value;
                flag[1]++;
            }
            if (value%5 == 1)
            {
                A[2] += value*pow(-1.0, j);
                j += 1.0;
                flag[2]++;
            }
            if (value%5 == 2)
            {
                A[3]++;
                flag[3]++;
            }
            if (value%5 == 3)
            {
                A[4] += value;
                flag[4]++;
            }
            if (value%5 == 4)
            {
                if (value > A[5]) A[5] = value;
                flag[5]++;  
            }
        }
        for (i = 1; i < 6; i++)
        {
            if (flag[i] > 0)
            {
                if (i == 4) printf("%.1f ", (double)A[4]/flag[i]);
                else if(i == 5) printf("%d\n", A[5]);
                else printf("%d ", A[i]);
            }
            else {
                if (i == 5) printf("N\n");
                else printf("N ");
            }
        }               
    }
    return 0;
}