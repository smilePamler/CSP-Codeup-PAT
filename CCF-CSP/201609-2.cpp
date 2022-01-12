#include <iostream>
#include <vector>
//#include <cmath>
//#include <algorithm>

using namespace std;

int n;
int seats[21][6] = { 0 };
vector<int> buy;

int find(int *arr, int m) {
    int cnt = 0, idx;
    for (int i = 1; i < 6; i++) {
        if (*(arr+i) == 0) {
            cnt++;
            if (cnt == 1) idx = i;
        }
        else if (cnt >= m) break;
        else if (cnt < m) cnt = 0;
    }
    if (cnt >= m) return idx;
    else return -1;
}

int main()
{
    for (int i = 1; i < 21; i++) seats[i][0] = 5; // 每排余票信息 
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        buy.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        bool match = false;
        for (int j = 1; j < 21; j++) {
            if (seats[j][0] >= buy[i]) {
                int loc = find(seats[j], buy[i]);
                if (loc != -1) {
                    for (int k = 0; k < buy[i] ; k++) {
                        cout << (j-1)*5+ loc + k << " ";
                        seats[j][loc + k] = 1; // 标志已占位
                    }
                    seats[j][0] -= buy[i];
                    match = true;
                    break;
                }
                else continue;
            }
        }
        if (!match) {
            for (int j = 1; j < 21; j++) {
                for (int k = 1; k < 6; k++) {
                    if (buy[i] == 0) break; 
                    if (seats[j][k] != 1) {
                        cout << (j-1)*5+k << " ";
                        buy[i]--;
                        seats[j][0]--;
                    }
                }
                if (buy[i] == 0) break;
            }
        }
        cout << endl;
    }
    return 0;
}
