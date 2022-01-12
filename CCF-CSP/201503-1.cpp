#include <iostream>

using namespace std;

const int MAX = 1010;
int A[MAX][MAX];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = m-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }
    return 0;
}
