#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n, res = 0, pr, p;
    cin >> n;
    cin >> pr;
    for (int i = 1; i < n; i++) {
        cin >> p;
        if (abs(p - pr) > res) res = abs(p - pr);
        pr = p;
    }
    cout << res << endl;
    return 0;
}
