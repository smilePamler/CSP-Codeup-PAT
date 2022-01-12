#include <iostream>
using namespace std;

struct Kid
{
    int id;
    int flag;
};
Kid kids[1001];

int main() {
    int n, k, i, num = 0;
    cin >> n >> k;
    for (i = 1; i < n+1; i++)
    {

        kids[i].id = i;
        kids[i].flag = 1;
    }
    int cnt = n;
    while (cnt > 1)
    {
        for (i = 1; i < n+1; i++)
        {
            if (kids[i].flag == 1 && cnt > 1)
            {
                num += 1;
                if (num % k == 0 || num % 10 == k)
                {
                    kids[i].flag = 0;
                    cnt--;
                }
            }
        }    
    }
    for (i = 1; i < n+1; i++)
    {
        if(kids[i].flag == 1)
            cout << kids[i].id;
    }
    return 0;
}