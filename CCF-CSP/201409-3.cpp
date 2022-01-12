#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s;
    int swch, n;
    cin >> swch >> n;
    vector<string> v1(n);
    vector<int> v2(n);
    if (swch == 0)
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        v1[i] = t; // 此处不能用 push_back(t), 因为 t 是一个变量名，不是一个字符串常量
        if (swch == 0)
            transform(t.begin(), t.end(), t.begin(), ::tolower);
        if (t.find(s) != string::npos)
            v2[i] = 1;       
    }
    for (int i = 0; i < n; i++)
    {
        if (v2[i] == 1)
        {
           printf("%s\n", v1[i].c_str());
        }    
    }
    return 0;
}