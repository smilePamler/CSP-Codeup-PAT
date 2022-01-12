/***70分代码***/
/*
#include <stdio.h>

struct Student
{
    int y;
    int result;
    int cnt;
};

int main() {
    int m, i, j, theta, predict_res;
    scanf("%d", &m);
    struct Student st[m];
    for ( i = 0; i < m; i++)
    {
        scanf("%d %d", &st[i].y, &st[i].result);
        st[i].cnt = 0;
    }
    for ( i = 0; i < m; i++)
    {
        theta = st[i].y;
        for ( j = 0; j < m; j++)
        {
            if (st[j].y >= theta)
            {
                predict_res = 1;
            }
            else
            {
                predict_res = 0;
            }
            if (predict_res == st[j].result)
            {
                st[i].cnt++;
            }
        }    
    }
    int max = st[0].cnt;
    int theta_star = st[0].y;
    for ( i = 1; i < m; i++)
    {
        if (st[i].cnt > max)
        {
            max = st[i].cnt;
            theta_star = st[i].y;
        }
        if (st[i].cnt == max && st[i].y > theta_star)
        {
            theta_star = st[i].y;
        } 
    }
    printf("%d\n", theta_star);
    return 0;
}
*/

/***100分代码***/
#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
    int y;
    int result;
};

const int M = 1e5;
Student stu[M+1];
int prefix[M+2], suffix[M+2];

bool comp(Student a, Student b) {
    return a.y < b.y ? 1 : 0;
}

int main() {
    int m, i, j, temp, cnt = 0, theta = 0;
    cin >> m;
    for (i = 1; i <= m; i++)
    {
        cin >> stu[i].y >> stu[i].result;
    }
    sort(stu+1, stu+m+1, comp); // 快排
    prefix[0] = (suffix[m+1] = 0);
    for (i = 1; i <= m; i++)
    {
        prefix[i] = prefix[i-1] + (stu[i].result ? 0 : 1); // 前缀和思想
    }
    for (i = m; i >= 1; i--)
    {
        suffix[i] = suffix[i+1] + (stu[i].result ? 1 : 0); // 后缀和思想
    }
    for (i = 1; i <= m; i++)
    {
        if (stu[i].y != stu[i-1].y) temp = prefix[i-1] + suffix[i];
        else { // 如果上一个 y 与当前 y 相等，就往前找到第一个不等的 y 所对应的前缀和
            j = i - 1;
            while (stu[j].y == stu[i].y) j--;
            temp = prefix[j] + suffix[i];
        }
        if (temp >= cnt ) {
                cnt = temp;
                theta = stu[i].y;
            }
    }
    cout << theta << endl; 
    return 0;
}

// 20210915
// #include <iostream>
// #include <vector>
// //#include <cmath>
// #include <algorithm>

// using namespace std;

// const int M = 100010;
// int m, res = 0;
// vector<pair<int, int>> input;
// int prefix[M];

// int main()
// {
//     cin >> m;
//     int y, r, cnt = 0;
//     for (int i = 0; i < m; i++)
//     {
//         scanf("%d%d", &y, &r);
//         input.push_back(make_pair(y, r));
//     }
//     sort(input.begin(), input.end()); // 升序排序
//     prefix[0] = input[0].second;
//     for (int i = 1; i < input.size(); i++)
//     {
//         prefix[i] = prefix[i-1] + input[i].second;
//     }
//     for (int i = 0; i < input.size(); i++)
//     {
//         if (i > 0 && input[i].first == input[i - 1].first)
//             continue;
//         else
//         {
//             cnt = prefix[m] - prefix[i-1] + i - prefix[i-1];
//             if (cnt >= res) {
//                 res = cnt;
//                 y = input[i].first;
//             }
//         }
//     }
//     cout << y << endl;
//     return 0;
// }