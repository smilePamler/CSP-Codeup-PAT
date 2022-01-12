#include <iostream>
using namespace std;

int main() {
    int r, y, g, n, i, k, l, totalTime = 0;
    cin >> r >> y >> g;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> k >> l;
        if (k == 0 || k == 1) totalTime += l;
        else if (k == 2) totalTime += (l + r);
        else if (k == 3) continue;
    }
    cout << totalTime << endl;
    return 0;
}