#include <bits/stdc++.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int posi[N][4], id[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d%d%d", &posi[i][0], &posi[i][1], &posi[i][2], &posi[i][3]);
        id[i] = i+1;
    }
    for (int i = 0; i < M; i++)
    {
        int x, y;
        bool flag = false;
        scanf("%d %d", &x, &y);
        for (int j = N-1; j >= 0; j--) // 每次点到对应窗口后会到顶层
        {
            if (x >= posi[j][0] && x <= posi[j][2] 
            && y >= posi[j][1] && y <= posi[j][3])
            {
                printf("%d\n", id[j]);
                if (j != N-1)
                {
                    // 交换坐标顺序
                    int temp0 = posi[j][0], temp1 = posi[j][1], temp2 = posi[j][2], temp3 = posi[j][3];
                    posi[j][0] = posi[N-1][0];
                    posi[j][1] = posi[N-1][1];
                    posi[j][2] = posi[N-1][2];
                    posi[j][3] = posi[N-1][3];
                    posi[N-1][0] = temp0;
                    posi[N-1][1] = temp1;
                    posi[N-1][2] = temp2;
                    posi[N-1][3] = temp3;
                    temp0 = id[N-1]; // 交换id顺序
                    id[N-1] = id[j];
                    id[j] = temp0;
                }                
                flag = true;
                break;
            }
        }
        if (flag == false) printf("IGNORED\n");
    }
    return 0;
}