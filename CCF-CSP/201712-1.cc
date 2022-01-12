#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, i, j, relatol = 10000;
    cin >> n;
    int data[n];
    for (i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (fabs(data[i] - data[j]) < relatol)
            {
                relatol = fabs(data[i] - data[j]);
            }    
        }   
    }
    cout << relatol;
    return 0;
}