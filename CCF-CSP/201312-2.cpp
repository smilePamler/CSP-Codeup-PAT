#include <bits/stdc++.h>

int main() {
    char ISBN[15];
    scanf("%s", ISBN);
    int sum = 0, res, j = 1;
    for (int i = 0; i < 11; i++)
    {
        if (ISBN[i] != '-')
        {
            sum += (ISBN[i] - '0')*j;
            j++;
        }
    }
    res = sum % 11;
    if (res == (ISBN[12]-'0')) printf("Right");
    else if (res == 10 && ISBN[12] == 'X') printf("Right");
    else
    {
        if (res == 10) ISBN[12] = 'X';
        else ISBN[12] = (char)(res + '0');
        printf("%s", ISBN);
    }
    return 0;
}