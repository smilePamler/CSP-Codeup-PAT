// sort函数：对整个序列进行排序
// lower_bound函数：返回一个迭代器，表示第一个大于等于指定值的元素，如果不存在这样的元素，返回尾迭代器
// upper_bound函数：返回一个迭代器，表示第一个大于指定值的元素，如果不存在这样的元素，返回尾迭代器
// equal_range函数：返回一个pair，其first成员是lower_bound函数返回的迭代器，其second成员是upper_bound函数返回的迭代器
// equal_range() 是STL中一种二分查找的方法
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility> // pair 头文件
using namespace std;

int main () {
    int n, i, temp;
    cin >> n;
    vector<int> a;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp); // 尾部插入
    }
    sort(a.begin(), a.end()); // begin指向第一个元素，end指向最后一个元素之后
    pair<vector<int>::iterator, vector<int>::iterator> it = equal_range(a.begin(), a.end(), a[a.size()/2]);
    if (it.first - a.begin() == a.end() - it.second)
    {
        cout << *(it.first);
    }
    else cout << -1;
    return 0;
}

// 注意：CSP系统不支持 auto