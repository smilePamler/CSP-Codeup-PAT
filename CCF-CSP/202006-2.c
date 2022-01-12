#include<stdio.h>
#include<math.h>

int main() {
    int n, a, b, i, idx_a = 0, idx_b = 0;
    long long inner_product = 0;
    scanf("%d %d %d", &n, &a, &b);
    long long u[a][2], v[b][2];
    for (i = 0; i < a; i++)
        scanf("%lld %lld", &u[i][0], &u[i][1]);
    for (i = 0; i < b; i++)
        scanf("%lld %lld", &v[i][0], &v[i][1]);
    while (idx_a < a && idx_b < b)
    {
        if (u[idx_a][0] == v[idx_b][0])
        {
            inner_product += u[idx_a][1] * v[idx_b][1];
            idx_a++;
            idx_b++;
        }
        else if (u[idx_a][0] > v[idx_b][0])
        {
            idx_b++;
        }
        else
        {
            idx_a++;
        }    
    }
    printf("%lld", inner_product);
    return 0;
}

/****version 2.0***/
/*
#include<stdio.h>
#include<math.h>

int main() {
    int n, a, b, i, j = 0, inner_product = 0;
    scanf("%d %d %d", &n, &a, &b);
    int u[a][2], v[b][2];
    for (i = 0; i < a; i++)
        scanf("%d %d", &u[i][0], &u[i][1]);
    for (i = 0; i < b; i++)
    {
        scanf("%d %d", &v[i][0], &v[i][1]);
    	while(j < a)
    	{
    		if (u[j][0] == v[i][0])
    		{
    			inner_product += u[j][1] * v[i][1];
    			j++;
    			break;
    		}
    		else if (u[j][0] < v[i][0])
    		{
    			j++;
    		}
    		else
    		{
    			break;
    		}
    	}
    }
    printf("%d", inner_product);
    return 0;
}
*/