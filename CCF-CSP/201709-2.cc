/* priority_queue ————— 自动排序
 * 默认用 vector，定义时可以省略，也可以用 deque
 * (默认)最大值优先级队列 priority_queue<int> pq; // 即从大到小排序
 * 最小值优先级队列 priority_queue<int, deque<int>, greater<int> > pq;
 * 本题需要自定义优先级，使得不同情况下满足题目要求的元素位于队首
 */

#include <iostream>
#include <queue>
using namespace std;

struct TeacherOp // 将所有老师取钥匙换钥匙的操作进行优先级排序，依次执行
{
    int num;
    int time;
    bool borrow;
    TeacherOp(int n, int t, bool b):num(n), time(t), borrow(b) {} // 构造函数
    friend bool operator < (TeacherOp t1, TeacherOp t2) {
        if (t1.time != t2.time)
            return t1.time > t2.time;
        else if (t1.borrow != t2.borrow)
            return t1.borrow && !t2.borrow;
        else return t1.num > t2.num; 
    }
};
priority_queue<TeacherOp> q;

int main() {
    int N, K, i, j;
    cin >> N >> K;
    int key[N+1];   // 钥匙编号数组
    for (i = 0; i < N+1; i++)
    {
        key[i] = i;
    }
    for (i = 0; i < K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        q.push(TeacherOp(a, b, true));
        q.push(TeacherOp(a, b+c, false));
    }
    while (!q.empty())
    {
        TeacherOp temp = q.top();
        q.pop();
        if (temp.borrow)
        {
            j = 1; // 借钥匙每次需从头开始查找钥匙位置
            while (key[j] != temp.num)
            {
                j++;
            }
            key[j] = -1; // 取走钥匙置为 -1
        }
        else
        {
            for (i = 1; i < N+1; i++)
            {
                if (key[i] == -1) // 还钥匙放到从左往右第一个空位
                {
                    key[i] = temp.num;
                    break;
                }    
            }
        }
    }
    for (i = 1; i < N+1; i++)
    {
        cout << key[i] << " ";
    }   
    return 0;
}