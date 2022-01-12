#include<iostream>
using namespace std;

int main() {
    int x, y, z, i, n, total = 0, num = 0, cnt[4] = { 0 };
    cin >> n;
    while (total < n )
    {
        for(i = 0; i < 4; i++)
        {
            if(total < n) {
                num++;
                x = num / 100;
                y = (num - 100 * x) / 10;
                z = num % 10;
                if(x == 7 || y == 7 || z == 7 || (num % 7) == 0) {
                    cnt[i]++;
                }
                else {
                    total++;
                }
            }
            else
            {
                break;
            }
            
        }
    }
    for (i = 0; i < 4; i++)
    {
        cout << cnt[i] << endl;
    }
    return 0;
}