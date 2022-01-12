#include <bits/stdc++.h>

using namespace std;

int main()
{
   int array[105][105];
   memset(array, 0, sizeof(array));
   int n, x, y, a, b;
   int res = 0;
   scanf("%d", &n);
   for (int i = 0; i < n; i++)
   {
       scanf("%d%d%d%d", &x, &y, &a, &b);
       for (int j = x; j < a; j++)
       {
           for (int k = y; k < b; k++)
           {
               if (array[j][k] == 0)
               {
                   array[j][k] = 1;
                   res++;
               }
           }
       }  
    }
    printf("%d", res);
    return 0;
}
