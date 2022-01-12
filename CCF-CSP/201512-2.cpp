#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>

using namespace std;
int a[35][35], b[35][35];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int row = 1, col = 1;
            for (int k = j+1; k < m; k++) {
                if (a[i][k] == a[i][k-1]) row++;
                else break;
            }
            for (int k = i+1; k < n; k++) {
                if (a[k][j] == a[k-1][j]) col++;
                else break;
            }
            if (row >= 3) {
                for (int k = 0; k < row; k++) b[i][j+k] = 0;
            }
            if (col >= 3) {
                for (int k = 0; k < col; k++) b[i+k][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
