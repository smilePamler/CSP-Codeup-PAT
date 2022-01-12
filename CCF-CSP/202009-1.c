#include <stdio.h>
#include <math.h>

int main() {
    int i, j, n, X, Y;
    scanf("%d %d %d", &n, &X, &Y);
    int coord[n][2];
    int dis[n];
    for( i = 0; i < n; i++)
    {
        scanf("%d %d", &coord[i][0], &coord[i][1]);
        dis[i] = pow(X-coord[i][0], 2) + pow(Y-coord[i][1], 2);
    }
    int min_dis, sub;
    for( i = 0; i < 3; i++)
    {
        sub = 1;
        min_dis = dis[0];
        for( j = 1; j < n; j++)
        {
            if(dis[j] < min_dis)
            {
                sub = j + 1;
                min_dis = dis[j];
            }
        }
        printf("%d\n", sub);
        dis[sub-1] = 1000000000;
    }
    return 0;
}

// C++ 版本
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;
// int n, X, Y;
// vector<pair<int, int>> loc;

// bool cmp(pair<int, int> a, pair<int, int> b) {
//     if (a.first == b.first) return a.second < b.second;
//     else return a.first < b.first;
// }

// int main()
// {
//     cin >> n >> X >> Y;
//     int x, y, dis;
//     for (int i = 0; i < n; i++) {
//         scanf("%d%d", &x, &y);
//         dis = (X - x) * (X - x) + (Y - y) * (Y - y);
//         loc.push_back(make_pair(dis, i));
//     }
//     sort(loc.begin(), loc.end(), cmp);
//     cout << loc[0].second + 1 << endl;
//     cout << loc[1].second + 1 << endl;
//     cout << loc[2].second + 1 << endl;
//     return 0;
// }
