#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define INF 0x3f3f3f3f

const int M = 2010;
const int N = 2010;
int n, m, k;
int g[N][N] = {0};
int d[N][N];
int vitalNodes[M] = {0};

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &vitalNodes[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = c;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] != 0)
                d[i][j] = g[i][j];
            else
                d[i][j] = INF;
    floyd();
    int minDist = INF;
    int r1, r2;
    for (int i = 0; i < m-1; ++i) {
        for (int j = i+1; j < m; ++j) {
            if (minDist > d[i][j]) {
                minDist = d[i][j];
                r1 = i, r2 = j;
            }
        }
    }
    printf("%d\n", d[r1][r2]);
    return 0; 
}