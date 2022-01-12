#include <bits/stdc++.h>
const int MAX = 1000001;
int school[MAX] = { 0 };
int main () {
    int N, t, s, i, maxid = 0;
    scanf("%d", &N);
    for (i=0; i< N; i++) {
        scanf("%d%d", &t, &s);
        if (t > maxid) maxid = t;
        school[t-1] += s;
    }
    int ms = school[0];
    int id = 1;
    for (i=1; i<maxid; i++) {
        if (school[i] > ms) {
            ms = school[i];
            id = i+1;
        }
    }
    printf("%d %d\n", id, ms);
    return 0;
}