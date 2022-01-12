#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; // 格式字符串
    cin >> s;
    vector<int> type(128); // 初始化了128个值为0的元素
    for (int i = 0; i < s.length(); i++)
    {
        type[s[i]] = 1; // 无参选项
        if (i+1 < s.length() && s[i+1] == ':')
        {
            type[s[i]] = 2; // 有参选项
        }
    }
    int N;
    scanf("%d", &N);
    cin.get(); // 吸收换行符
    for (int l = 0; l < N; l++)
    {
        string com, temp, t;
        getline(cin, com); // 读入命令行(可含有空格)
        map<char, string> res; // map键值唯一，且会自动排序，符合题目要求
        stringstream ss(com); // 将 com 复制到字符串流 ss 中
        ss >> temp; // 向temp中写入ss中的第一个单词（即命令行工具）
        while (ss >> temp)
        {
            if (temp.length() == 2 && temp[0] == '-' && type[temp[1]] == 1)
                res[temp[1]] = ""; // 无参对应实值为空字符串
            else if (temp.length() == 2 && temp[0] == '-' && type[temp[1]] == 2 && ss >> t)
                res[temp[1]] = t; // 有参且紧接着有参数时赋值
            else break;
        }
        // 打印输出
        printf("Case %d:", l+1);
        for (map<char, string>::iterator it = res.begin(); it != res.end(); it++)
        {
            printf(" -%c", it->first);
            if(!it->second.empty()) printf(" %s", it->second.c_str()); // 注意：必须先判空，因为空串无法打印输出;且string不能直接%s输出
        }
        printf("\n");
    }
    return 0;
}