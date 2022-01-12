#include<bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, MAX, MIN;
int A[N], B[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        MAX += B[i];
    }
    MIN += B[0];
    for (int i = 1; i < n; i++) {
        if (B[i] != B[i-1]) {
            MIN += B[i];
        }
    }

    cout << MAX << endl;
    cout << MIN << endl;

    return 0;
}