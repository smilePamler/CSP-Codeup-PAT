#include <iostream>
using namespace std;

struct Url
{
    string rule;
    string name;
};
Url U[100];

bool Match(string l, string m, int flag) { // flag = 0(1) 代表检查匹配(打印参数)
    int len1, len2, k1 = 0, k2 = 0, flag1; // flag1 判断参数是否异常
    len1 = l.length();
    len2 = m.length();
    while (k1 < len1 && k2 < len2)
    {
        if (l[k1] == m[k2])
        {
            k1++;
            k2++;
            continue;
        }
        if (l[k1++] != '<') return false; // 无参数(此 k1 先判断再自增 1)
        if (flag) cout << " ";
        if (l[k1] == 'i') // 整型参数
        {
            flag1 = 0;
            while (m[k2] && m[k2] >= '0' && m[k2] <= '9') // 题目要求所有参数必须为非空字符串，故while条件必须加上 m[k2] (空字符 ascii 码值为 0)
            {
                if (m[k2] > '0') flag1 = 1;
                if (flag && flag1) cout << m[k2];
                k2++;
            }
            if (!flag1) return false;
            k1 += 4;
            continue;
        }
        if (l[k1] == 's') // 字符串参数
        {
            flag1 = 0;
            while (m[k2] && m[k2] != '/') // 同上
            {
                flag1 = 1;
                if (flag) cout << m[k2];
                k2++;
            }
            if (!flag1) return false;
            k1 += 4;
            continue;
        }
        if (l[k1] == 'p') // 路径参数
        {
            if (flag)
            {
                while (m[k2]) cout << m[k2++]; // 同上         
            }
            return true;
        }
    }
    return (k1 == len1 && k2 == len2); // 不能直接返回true，因为while循环跳出的原因可能只有单个下标k1或k2不满足，这是也就是出现了多条规则前端重复的情况，会误判
}

int main() {
    int n, m, i, j, flag; // flag = 0(1) 代表匹配不成功(成功)
    cin >> n >> m;
    string ch[m];
    for (i = 0; i < n; i++)
    {
        cin >> U[i].rule >> U[i].name;
    }
    for (i = 0; i < m; i++)
    {
        cin >> ch[i];
    }
    for (i = 0; i < m; i++)
    {
        flag = 0;
        for (j = 0; j < n; j++)
        {
            if (Match(U[j].rule, ch[i], 0))
            {
                flag = 1;
                cout << U[j].name;
                Match(U[j].rule, ch[i], 1);
                break;
            }    
        }
        if (!flag) cout << "404";
        cout << endl;    
    }
    return 0;
}