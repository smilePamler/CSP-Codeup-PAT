#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>

using namespace std;
int num[1010];

int main()
{
    int n, cnt = 0;
    bool change = false;
    bool changed = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    if (num[1] - num[0] > 0) changed = false;
    else changed = true;
    for (int i = 2; i < n; i++) {
        if (num[i] - num[i-1] > 0) change = false;
        else change = true;
        if(change != changed) {
            cnt++;
            changed = change;
        }
    }
    cout << cnt << endl;
    return 0;
}
