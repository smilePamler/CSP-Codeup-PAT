#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    sort(array, array+n);
    for (int i = 1; i < n; i++)
    {
        if (array[i] - array[i-1] == 1)
        {
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
