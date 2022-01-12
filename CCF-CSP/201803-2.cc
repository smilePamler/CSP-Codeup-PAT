#include <iostream>
using namespace std;

int direction[100] = { 0 };
int position[100];

int main() {
    int n, L, t, i, j, k;
    cin >> n >> L >> t;
    for (i = 0; i < n; i++)
    {
        cin >> position[i];
        direction[i] = 1;
    }
    for (j = 1; j <= t; j++)
    {
        for (i = 0; i < n; i++)
        {
            position[i] += direction[i];
        }
        for (i = 0; i < n; i++) // 碰到壁
        {
            if (position[i] == L) direction[i] = -1;
            if (position[i] == 0) direction[i] = 1;    
        }
        for (i = 0; i < n-1; i++) // 小球之间的碰撞
        {
            for (k = i+1; k < n; k++) // 因为小球的位置存放并不是按升序存放的，所以得和所有后边的小球比较
            {
                if (position[i] == position[k])
                {
                    direction[i] = -direction[i];
                    direction[k] = -direction[k];
                }    
            }   
        }    
    }
    for (i = 0; i < n; i++)
    {
        cout << position[i] << " ";
    }
    return 0;
}