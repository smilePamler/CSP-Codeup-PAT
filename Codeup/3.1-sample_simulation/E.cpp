// 在输入每两个点之间的距离时就求和，不然超时
#include <bits/stdc++.h>

int main() {
    int N;
    scanf("%d", &N);
    int totalDis[N] = { 0 };
    int i, M, dis, sum = 0;
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &dis);
        sum += dis;
        if (i == N) totalDis[0] = dis; // 下标0处存放第N出口到第1出口的距离
        else totalDis[i] = totalDis[i-1] + dis; // N-1存放第1个出口到第N个出口的总距离
    }
    scanf("%d", &M);
    int x, y, shortDis[M], temp;
    for (i = 0; i < M; i++)
    {
        temp = 0;
        scanf("%d%d", &x, &y);
        if (x>y && y!=1) temp = totalDis[x-1] - totalDis[y-1];
        else if (x>y && y==1) temp = totalDis[x-1];
        else if (x<y && x!=1) temp = totalDis[y-1] - totalDis[x-1];
        else temp = totalDis[y-1];
        shortDis[i] = temp < fabs(sum-temp) ? temp : fabs(sum - temp);
    }
    for (i = 0; i < M; i++) printf("%d\n", shortDis[i]);
    return 0;
}