#include <stdio.h>

int main() {
    int n, k, t, xl, yd, xr, yu, i, j, num_pass = 0, num_stay = 0;
    scanf("%d %d %d %d %d %d %d", &n, &k, &t, &xl, &yd, &xr, &yu);
    int P[n][2*t];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2*t; j++)
        {
            scanf("%d", &P[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        int cnt = 0, flag = 0;
        for (j = 0; j < 2*t; j=j+2)
        {
            if (P[i][j] >= xl && P[i][j] <= xr && P[i][j+1] >= yd && P[i][j+1] <= yu)
            {
                cnt++;
                flag++;
            }
            else cnt = 0;
            if (cnt >= k) break;
        }
        if(flag != 0) num_pass++;
        if(cnt >= k) num_stay++;
    }
    printf("%d\n", num_pass);
    printf("%d", num_stay);
    return 0;
}

// C++ 版本
// #include <iostream>
// //#include <vector>
// //#include <cmath>
// //#include <algorithm>

// using namespace std;

// int n, k, t, xl, yd, xr, yu;
// int c1 = 0, c2 = 0;

// int main()
// {
//     cin >> n >> k >> t >> xl >> yd >> xr >> yu;
//     for (int i = 0; i < n; i++) {
//         int x, y, temp = 0;
//         bool flag = false;
//         for (int j = 0; j < t; j++) {
//             scanf("%d%d", &x, &y);
//             if (x >= xl && x <= xr && y >= yd && y <= yu) {
//                 flag = true;
//                 temp++;
//             }
//             else if (temp < k) temp = 0;
//         }
//         if (flag) c1++;
//         if (temp >= k) c2++;
//     }
//     cout << c1 << endl;
//     cout << c2 << endl;
//     return 0;
// }
