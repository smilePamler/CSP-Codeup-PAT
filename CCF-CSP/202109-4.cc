// DFS 10'
#include <iostream>
#include <string.h>
#include <set>
#include <cmath>
#include <iomanip>

using namespace std;

const int N = 20;
int n, k, coin;
double res = 0.0;
double p[N];
int flag[N];
multiset<int> mset;

double calcuRate() {
	int cnt = 0;
	double r = 1.0;
	for (int i = 1; i <= n; i++) {
		cnt = mset.count(i);
        // cout << i << "的个数为" << cnt << ", ";
		r *= pow(p[i], (double)cnt);
	}
    // cout << "r = " << r << " * " << mset.size()-1 << " = " << r << endl;
    r *= (mset.size() - 1);
	return r;
}

int findZero() {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (flag[i] == 0) count++;
	}
	return count;
}

void dfs() {
	int card = findZero();
	double exp;
	if (coin >= card * k || card == 0) {
		exp = calcuRate();
		res += exp;
		return;
	}
	for (int i = 1; i <= n; i++) {
		mset.insert(i);
		if (flag[i] == 1) {
			coin++;
			dfs();
			coin--;
		}
		else {
			flag[i] = 1;
			dfs();
			flag[i] = 0;
		}
		mset.erase(mset.find(i));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	mset.insert(-1);
	dfs();
	
	cout << fixed << setprecision(10) << res << endl;
	
	return 0;
} 
