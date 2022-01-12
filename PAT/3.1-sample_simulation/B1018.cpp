#include <bits/stdc++.h>

int main() {
    char game[3] = { 'B', 'C', 'J'};
    int times1[3] = { 0 }, times2[3] = { 0 };
    int N, i;
    scanf("%d", &N);
    getchar();
    char x, y;
    int cnt1[3] = { 0 }, cnt2[3] = { 0 };
    while (N--)
    {
        x = getchar();
        getchar();
        y = getchar();
        getchar();
        if (x==y) 
        {
            cnt1[1]++;
            cnt2[1]++;
        }
        if ((x==game[0]&&y==game[1])||(x==game[1]&&y==game[2])||(x==game[2]&&y==game[0]))
        {
            cnt1[0]++;
            cnt2[2]++;
            switch (x)
            {
            case 'B':
                times1[0]++;
                break;
            case 'C':
                times1[1]++;
                break;
            case 'J':
                times1[2]++;
                break;
            }
        }
        if ((y==game[0]&&x==game[1])||(y==game[1]&&x==game[2])||(y==game[2]&&x==game[0]))
        {
            cnt1[2]++;
            cnt2[0]++;
            switch (y)
            {
            case 'B':
                times2[0]++;
                break;
            case 'C':
                times2[1]++;
                break;
            case 'J':
                times2[2]++;
                break;
            }
        }    
    }
    printf("%d %d %d\n", cnt1[0], cnt1[1], cnt1[2]);
    printf("%d %d %d\n", cnt2[0], cnt2[1], cnt2[2]);
    int max1 = times1[0], sub1 = 0, max2 = times2[0], sub2 = 0;
    for (i = 1; i < 3; i++)
    {
        if (times1[i]>max1)
        {
            max1 = times1[i];
            sub1 = i;
        }
        if (times2[i]>max2)
        {
            max2 = times2[i];
            sub2 = i;
        }
    }
    printf("%c %c\n", game[sub1], game[sub2]);
    return 0;
}