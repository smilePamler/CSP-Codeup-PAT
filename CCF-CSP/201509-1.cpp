#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>

using namespace std;

int main()
{
    int n, cnt = 1;
    int a[1010];
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i > 0 && a[i] != a[i-1]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
