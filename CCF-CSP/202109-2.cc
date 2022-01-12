#include <iostream>
#include <algorithm>

using namespace std;

const int N = 500010;
int n;
int A[N];
int cnt[N];  // 差分数组

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    A[0] = A[n+1] = 0;
    n = unique(A, A+n+2) - A; // 相邻元素去重
    for (int i = 1; i < n-1; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) cnt[A[i]] ++;
        else if (A[i] < A[i-1] && A[i] < A[i+1]) cnt[A[i]] --;
    }
    
    int sum = 0, res = 0;
    for (int i = 10000; i > 0; i--) { // 注意此处的求和顺序
        sum += cnt[i];
        res = max(res, sum);
    }

    cout << res << endl;

    return 0;
}
