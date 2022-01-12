#include <iostream>
#include <cstdio>

using namespace std;
#define ll unsigned long long

const int N = 100010; 
const int M = 1000000007; 
int n, m;
ll x[N] = { 0 }, y[N] = { 0 }, z[N] = { 0 };

int main() {
    scanf("%d%d", &n, &m);
    int option;
    while(m--) {
        scanf("%d", &option);
        if (option == 1) {
            ll l, r, a, b, c;
            scanf("%llu%llu%llu%llu%llu", &l, &r, &a, &b, &c);
            for (ll i = l; i <= r; i++) {
                x[i] = (a + x[i]) % M;
                y[i] = (b + y[i]) % M;
                z[i] = (c + z[i]) % M;
            }
        }
        else if (option == 2) {
            ll l, r, k;
            scanf("%llu%llu%llu", &l, &r, &k);
            for (ll i = l; i <= r; i++) {
                x[i] = (x[i] * k) % M;
                y[i] = (y[i] * k) % M;
                z[i] = (z[i] * k) % M;
            }
        }
        else if (option == 3) {
            ll l, r;
            scanf("%llu%llu", &l, &r);
            for (ll i = l; i <= r; i++) {
                ll temp = x[i];
                x[i] = y[i];
                y[i] = z[i];
                z[i] = temp;
            }
        }
        else if (option == 4) {
            ll l, r;
            scanf("%llu%llu", &l, &r);
            ll X = 0, Y = 0, Z = 0;
            for (ll i = l; i <= r; i++) {
                X = (X + x[i]) % M;
                Y = (Y + y[i]) % M;
                Z = (Z + z[i]) % M;
            }
            printf("%d\n", ((X * X) % M + (Y * Y) % M + (Z * Z) % M) % M);
        }
    }
    return 0;
}