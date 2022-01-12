#include <iostream>
//#include <vector>
//#include <cmath>
#include <algorithm>

using namespace std;

const int N = 650;
int n, L, r, t, cnt = 0;
int A[N][N] = {0};

int main()
{
    cin >> n >> L >> r >> t;
    int val;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &val);
            A[i][j] = A[i-1][j] + A[i][j-1] - A[i-1][j-1] + val;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x1 = max(1, i - r);
            int x2 = min(n, i + r);
            int y1 = max(1, j - r);
            int y2 = min(n, j + r);
            int sum = A[x2][y2] - A[x1-1][y2] - A[x2][y1-1] + A[x1-1][y1-1];
            if ((double)sum / ((x2-x1+1)*(y2-y1+1)) <= t) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
