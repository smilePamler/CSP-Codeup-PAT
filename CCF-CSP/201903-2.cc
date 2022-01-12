#include <iostream>
#include <stack>
using namespace std;

// 判断运算符优先级
int Priority(char op) {
    switch (op)
    {
    case '+':
    case '-':
        return 0;
        break;
    case 'x':
    case '/':
        return 1;
        break;
    }
    return -1;
}

// 中缀表达式转后缀表达式
void InfixToSuffix(char array[], stack<char>& suffix) {
    int i, j = 0;
    char temp, rev[7];
    stack<char> optr; // 存放操作符
    for (i = 0; i < 7; i++)
    {
        if (array[i] >= '0' && array[i] <= '9')
        {
            suffix.push(array[i]);
        }
        else
        {
            if (optr.empty()) optr.push(array[i]);
            else
            {
                while (!optr.empty() && Priority(optr.top()) >= Priority(array[i])) {
                    temp = optr.top();
                    optr.pop();
                    suffix.push(temp);
                }
                optr.push(array[i]);
            }
        }
    }
    while (!optr.empty()) {
        temp = optr.top();
        suffix.push(temp);
        optr.pop();
    }
    // 此时的后缀表达式是逆序，需要逆置
    while (!suffix.empty()) {
        rev[j] = suffix.top();
        suffix.pop();
        j++;
    }
    for (i = 0; i < 7; i++)
    {
        suffix.push(rev[i]);
    }
}

// 计算后缀表达式的值
void CaclValue(stack<char> suffixexpression, int& value) {
    int a = 0, b = 0, temp = 0;
    stack<int> operand; // 存放操作数及计算结果
    while (!suffixexpression.empty()) {
        if (suffixexpression.top() >= '0' && suffixexpression.top() <= '9') {
            operand.push(suffixexpression.top() - '0'); // 存入整型数
            suffixexpression.pop();
        }
        else {
            b = operand.top();
            operand.pop();
            a = operand.top();
            operand.pop();
            switch (suffixexpression.top())
            {
            case '+':
                temp = a + b;
                break;
            case '-':
                temp = a - b;
                break;
            case 'x':
                temp = a * b;
                break;
            case '/':
                temp = a / b;
                break;
            }
            operand.push(temp);
            suffixexpression.pop();
        }
    }
    value = operand.top();
}

struct Game
{
    char s[7];
    int Value = 0;
    stack<char> Suffix;
};

int main() {
    int n, i, j;
    cin >> n;
    Game game[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 7; j++)
        {
            cin >> game[i].s[j];
        }
    }
    for (i = 0; i < n; i++)
    {
        InfixToSuffix(game[i].s, game[i].Suffix);
        CaclValue(game[i].Suffix, game[i].Value);
        if (game[i].Value == 24) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}