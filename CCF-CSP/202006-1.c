#include<stdio.h>

struct Point
{
    int x;
    int y;
    char type;
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int i, j;
    struct Point p[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %c", &p[i].x, &p[i].y, &p[i].type);
    }
    int theta[m][3], satisfy[m];
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &theta[i][0], &theta[i][1], &theta[i][2]);
        satisfy[i] = 1;
        int flag;
        if((theta[i][0] + theta[i][1] * p[0].x + theta[i][2] * p[0].y) > 0)
        {
            switch (p[0].type)
            {
            case 'A':
                flag = 1;
                break;
            case 'B':
                flag = 2;
                break;
            default:
                break;
            };
        }
        if((theta[i][0] + theta[i][1] * p[0].x + theta[i][2] * p[0].y) < 0)
        {
            switch (p[0].type)
            {
            case 'A':
                flag = 3;
                break;
            case 'B':
                flag = 4;
                break;
            default:
                break;
            };
        }
        for (j = 1; j < n; j++)
        {
            if(flag == 1)
            {
                if(((theta[i][0] + theta[i][1] * p[j].x + theta[i][2] * p[j].y) > 0 && p[j].type == 'B') || ((theta[i][0] + theta[i][1] * p[j].x + theta[i][2] * p[j].y) < 0 && p[j].type == 'A'))
                {
                    satisfy[i] = 0;
                    break;
                }
            }
            else if(flag == 2)
            {
                if(((theta[i][0] + theta[i][1] * p[j].x + theta[i][2] * p[j].y) > 0 && p[j].type == 'A') || ((theta[i][0] + theta[i][1] * p[j].x + theta[i][2] * p[j].y) < 0 && p[j].type == 'B'))
                {
                    satisfy[i] = 0;
                    break;
                }
            }
            else if(flag == 3)
            {
                if(((theta[i][0] + theta[i][1] * p[j].x + theta[i][2] * p[j].y) < 0 && p[j].type == 'B') || ((theta[i][0] + theta[i][1] * p[j].x + theta[i][2] * p[j].y) > 0 && p[j].type == 'A'))
                {
                    satisfy[i] = 0;
                    break;
                }
            }
            else if(flag == 4)
            {
                if(((theta[i][0] + theta[i][1] * p[j].x + theta[i][2] * p[j].y) < 0 && p[j].type == 'A') || ((theta[i][0] + theta[i][1] * p[j].x + theta[i][2] * p[j].y) > 0 && p[j].type == 'B'))
                {
                    satisfy[i] = 0;
                    break;
                }
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        if (satisfy[i] > 0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}