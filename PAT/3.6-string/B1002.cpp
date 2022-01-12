#include <bits/stdc++.h>

char pinyin[10][10] = { "ling", "yi", "er", "san", "si",
        "wu", "liu", "qi", "ba", "jiu" };

int main() {
    char num[110];
    scanf("%s", num);
    int i, len, sum = 0;
    len = strlen(num);
    for (i = 0; i < len; i++)
    {
        sum += (num[i] - '0');
    }
    int a, b, c;
    a = sum / 100;
    b = (sum % 100) / 10;
    c = sum % 10;
    if (a != 0)
        printf("%s %s %s", pinyin[a], pinyin[b], pinyin[c]);
    else if ( b != 0 )
        printf("%s %s", pinyin[b], pinyin[c]);
    else printf("%s", pinyin[c]);
    return 0;
}