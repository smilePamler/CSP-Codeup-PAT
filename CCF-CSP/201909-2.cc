#include <iostream>
using namespace std;

struct AppleOp
{
    int m;
    int op[1000];
    bool drop = false;
};

int main() {
    int N, i, j, T = 0, D = 0, E = 0;;
    cin >> N;
    AppleOp appleop[N];
    for (i = 0; i < N; i++)
    {
        int cnt = 0;
        cin >> appleop[i].m;
        for (j = 0; j < appleop[i].m; j++)
        {
            cin >> appleop[i].op[j];
            if (appleop[i].op[j] > 0) cnt = appleop[i].op[j];
            else cnt += appleop[i].op[j];
        }
        T += cnt;
    }
    for (i = 0; i < N; i++)
    {
        for (j = 1; j < appleop[i].m; j++)
        {
            if (appleop[i].op[j] <= 0) appleop[i].op[0] += appleop[i].op[j]; // appleop[i].op[0] 为每棵苹果树最初苹果数
            else {
                if (appleop[i].op[0] != appleop[i].op[j]) {
                    appleop[i].drop = true;
                    D++;
                    break;
                }   
            }
        }
    }
    for (i = 0; i < N; i++)
    {
        if (appleop[i].drop && appleop[(i+1)%N].drop && appleop[(i+2)%N].drop) E++;
    }
    cout << T << " " << D << " " << E;
    return 0;
}