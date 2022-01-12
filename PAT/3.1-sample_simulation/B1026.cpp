#include <bits/stdc++.h>

const double clk_tck = 100.0;

int main() {
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    int h = 0, m = 0, s = 0;
    // double round(double x)--四舍五入
    s = (int)round((c2-c1)/clk_tck);
    m = s/60;
    s = s%60;
    h = m/60;
    m = m%60;
    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}