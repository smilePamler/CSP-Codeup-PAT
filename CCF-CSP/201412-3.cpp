#include <iostream>
using namespace std;
typedef long long ll;

struct Tran
{
    string s;
    double a;
    ll b;
};


int main() {
    Tran records[5010];
    int i = 0;
    while (cin >> records[i].s)
    {
        if (records[i].s == "cancel")
        {
            cin >> records[i].b;
        }
        else
        {
            cin >> records[i].a >> records[i].b;
        }
        i++;
    }
    
    return 0;
}