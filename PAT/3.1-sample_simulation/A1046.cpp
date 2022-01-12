#include <bits/stdc++.h>

int main() {
    int N, M, i, val, circle_dis = 0;
    scanf("%d", &N);
    int total_dis[N+1] = { 0 };
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &val);
        if(i != N) total_dis[i] = total_dis[i-1] + val;
        else total_dis[i] = val; // i=5位置存放第5个出口到第1个出口的距离
        circle_dis += val;
    }
    scanf("%d", &M);
    int shortest_dis[M];
    for (i = 0; i < M; i++)  
    {
        int x, y, temp;
        scanf("%d%d", &x, &y);
        int m = x < y ? x : y; // x、y中最小值
        int n = x > y ? x : y; // x、y中最大值
        if (m!=1)
        {
            temp = total_dis[n-1] - total_dis[m-1];        
            shortest_dis[i] = temp < (circle_dis-temp) ? temp : (circle_dis-temp);
        }
        if (m==1)
            shortest_dis[i] = total_dis[n-1] < (circle_dis-total_dis[n-1]) ? total_dis[n-1] : (circle_dis-total_dis[n-1]);
    }
    for (i = 0; i < M; i++)
        printf("%d\n", shortest_dis[i]);
    return 0;
}