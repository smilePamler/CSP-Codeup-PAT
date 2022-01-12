#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, M, k = 0, T = 0, P = 0;
    cin >> N >> M;
    int Apple[N][M+1];
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M+1; j++)
        {
            cin >> Apple[i][j];
            T += Apple[i][j];
        } 
    }
    for (i = 0; i < N; i++)
    {
        int cnt = 0;
        for (j = 1; j < M+1; j++)
        {
            cnt += Apple[i][j];
        }
        if (P < abs(cnt))
        {
            P = abs(cnt);
            k = i + 1;
        }
    }
    cout << T << " " << k << " " << P;
    return 0;
}