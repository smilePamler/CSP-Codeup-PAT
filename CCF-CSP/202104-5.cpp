#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int n, m, time = 0;
    map<int, int> path;
    cin >> n >> m;
    int l, x, y;
    int t[510] = { 0 };
    scanf("%d", &l);
    for (int j = 0; j < l; j++)
    {
        scanf("%d %d", &x, &y);
        path.insert(make_pair(x, y));
    }
    map<int, int>::iterator j = path.find(1);
    if (j != path.end())
    {
        while (l > 0)
        {
            time += j->second;
            j++;
            if (j == path.end())
                j = path.begin();
            t[j->first] = time;
            l--;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (t[i] != 0)
            printf("%d\n", t[i]);
        else
            printf("inf\n");
    }
    return 0;
}