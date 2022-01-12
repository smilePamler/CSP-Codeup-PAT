/* 数字排序 */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

multiset<int> mst;
set<int> st;
vector<pair<int, int>> res;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

int main()
{
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        mst.insert(val);
        st.insert(val);
    }
    for (auto i : st) {
        res.push_back(make_pair(i, mst.count(i)));
    }
    sort(res.begin(), res.end(), cmp);
    for (auto i : res) {
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}
