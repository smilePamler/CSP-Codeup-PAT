#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int res = 0;
    for (auto i : s) {
        res += i - '0';
    }
    cout << res << endl;
    return 0;
}
