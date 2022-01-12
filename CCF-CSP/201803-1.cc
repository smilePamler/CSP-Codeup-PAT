#include <iostream>
using namespace std;

int main() {
    int num, score = 0, centerCnt = 0;
    while (true)
    {
        cin >> num;
        if (num == 0) break;
        else
        {
            if (num == 1) {
                score++;
                centerCnt = 0;
            }
            else if (num == 2) {
                centerCnt++;
                score += 2*centerCnt;
            }
        }     
    }
    cout << score << endl;
    return 0;
}