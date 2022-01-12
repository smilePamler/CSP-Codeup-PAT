#include <bits/stdc++.h>
 
int main() {
    int i;
    double w, t, l, pro;
    double odd = 1.0;
    char s[3];
    for (i = 0; i < 3; i++)
    {
        scanf("%lf%lf%lf", &w, &t, &l);
        double temp = t>l ? t : l;
        double max = w>temp ? w : temp;
        odd *= max;
        if (max == w) s[i] = 'W';
        else if (max == t) s[i] = 'T';
        else s[i] = 'L';
    }
    pro = (odd*0.65 - 1) * 2;
    printf("%c %c %c %.2f", s[0], s[1], s[2], pro);
    return 0;
}