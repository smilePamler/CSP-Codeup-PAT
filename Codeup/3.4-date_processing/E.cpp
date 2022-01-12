#include <bits/stdc++.h>

int days[13][2] = { {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31},
    {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
};

int isLeap(int year) {
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0) return 1;
    else return 0;
}

int main() {
    int n, y, m, d, add;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d %d %d", &y, &m, &d, &add);
        while (add--)
        {
            d++;
            if (d > days[m][isLeap(y)])
            {
                m++;
                d = 1;
            }
            if (m > 12)
            {
                y++;
                m = 1;
            }
        }
        printf("%04d-%02d-%02d\n", y, m, d);
    }
    return 0;
}