#include <bits/stdc++.h>

char base[13] = { '0', '1', '2', '3', '4', '5', '6',
                 '7', '8', '9', 'A', 'B', 'C'};

int main() {
    int color[3], rgb[2];
    memset(rgb, -1, sizeof(rgb));
    scanf("%d %d %d", &color[0], &color[1], &color[2]);
    int i;
    printf("#");
    for (i = 0; i < 3; i++)
    {
        int num = 0;
        do
        {
            rgb[num++] = color[i] % 13;
            color[i] = color[i] / 13;
        } while (color[i] != 0);
        if (rgb[1] != -1)
        {
            printf("%c", base[rgb[1]]);
        }
        else printf("0");
        printf("%c", base[rgb[0]]);
    }
    return 0;
}