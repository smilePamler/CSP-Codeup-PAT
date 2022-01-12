#include <bits/stdc++.h>

const int N = 54;
int start[N+1] = { 0 }, end[N+1] = { 0 }, next[N+1] = { 0 };

int main() {
    int k, i;
    scanf("%d", &k);
    for (i = 1; i <= 54; i++)
    {
        start[i] = i;
        scanf("%d", &next[i]);
    }
    while (k--)
    {
        for (i = 1; i <= 54; i++)
        {
            end[next[i]] = start[i];
        }
        for (i = 1; i <= 54; i++)
        {
            start[i] = end[i];
        }
    }
    for (i = 1; i <= 54; i++)
    {
        if (i < 54)
        {
            if (start[i] <= 13) printf("S%d ", start[i]);
            else if (start[i] <= 26) printf("H%d ", start[i]-13);
            else if (start[i] <= 39) printf("C%d ", start[i]-26);
            else if (start[i] <= 52) printf("D%d ", start[i]-39);
            else if (start[i] == 53) printf("J%d ", start[i]-52);
            else if (start[i] == 54) printf("J%d ", start[i]-52);
        }
        else
        {
            if (start[i] <= 13) printf("S%d\n", start[i]);
            else if (start[i] <= 26) printf("H%d\n", start[i]-13);
            else if (start[i] <= 39) printf("C%d\n", start[i]-26);
            else if (start[i] <= 52) printf("D%d\n", start[i]-39);
            else if (start[i] == 53) printf("J%d\n", start[i]-52);
            else if (start[i] == 54) printf("J%d\n", start[i]-52);
        }
    }
    return 0;
}