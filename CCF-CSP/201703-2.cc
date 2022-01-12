/**** 60分code ****/ 
// #include <iostream>
// using namespace std;

// struct stunode
// {
//     int num;
//     stunode* next;
//     stunode* pre;
// };

// int main() {
//     int n, m, i;
//     cin >> n;
//     cin >> m;
//     stunode* L = new stunode;
//     stunode* P;
//     stunode* Q;
//     L->pre = NULL;
//     L->next = NULL;
//     P = L;
//     Q = L;
//     for (i = 1; i < n+1; i++)
//     {
//         stunode* s = new stunode;
//         s->num = i;
//         s->next = P->next;
//         P->next = s;
//         s->pre = P;
//         P = s;
//     }
//     for (i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         P = L->next;
//         while (P->num != x)
//         {
//             P = P->next;
//         }
//         Q = P;
//         if (y > 0)
//         {
//             while (y)
//             {
//                 Q = Q->next;
//                 y--;
//             }
//             P->pre->next = P->next;
//             if (Q->next)
//             {
//                 P->next->pre = P->pre;
//                 Q->next->pre = P;
//                 P->next = Q->next;
//                 Q->next = P;
//                 P->pre = Q;
//             }
//             else
//             {
//                 P->next = Q->next;
//                 Q->next = P;
//                 P->pre = Q;
//             }  
//         }
//         else if (y < 0)
//         {
//             while (y != 0)
//             {
//                 Q = Q->pre;
//                 y++;
//             }
//             P->pre->next = P->next;
//             if (P->next)
//             {
//                 P->next->pre = P->pre;
//             }
//             Q->pre->next = P;
//             P->pre = Q->pre;
//             Q->pre = P;
//             P->next = Q; 
//         }    
//     }
//     Q = L->next;
//     while (Q)
//     {
//         cout << Q->num << " ";
//         Q = Q->next;
//     }
//     delete(L);
//     return 0;
// }

/***改进***/
//list 容器为双向链表 
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> L;
    int n, m, i;
    cin >> n;
    cin >> m;
    for (i = 1; i <= n; i++)
    {
        L.push_back(i);
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        list<int>::iterator it = L.begin();
        while (*it != x)
        {
            it++;
        }
        it = L.erase(it); // 删除it位置的数据，返回下一个数据的位置
        while (y > 0)
        {
            it++;
            y--;
        }
        while (y < 0)
        {
            it--;
            y++;
        }
        L.insert(it, x); // 在it位置插x元素的拷贝，返回新数据的位置        
    }
    for (list<int>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }    
    return 0;
}