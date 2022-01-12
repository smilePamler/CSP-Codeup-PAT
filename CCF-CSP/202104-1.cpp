#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>

using namespace std;
int h[300] = {0};

int main()
{
    int n, m, L, val;
    cin >> n >> m >> L;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &val);
            h[val]++;
        }
    }
    for (int i = 0; i < L; i++) printf("%d ", h[i]);
    return 0;
}
