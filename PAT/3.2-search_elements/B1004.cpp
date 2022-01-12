#include <bits/stdc++.h>
using namespace std;

struct Stu
{
    char name[20];
    char id[20];
    int grade;
};

bool comp(Stu a, Stu b) {
    return a.grade > b.grade ? 1 : 0;
}

int main() {
    int n, i;
    scanf("%d", &n);
    Stu stu[n];
    for (i = 0; i < n; i++)
    {
        scanf("%s%s%d", &stu[i].name, &stu[i].id, &stu[i].grade);
    }
    sort(stu, stu+n, comp); // 递减排序
    printf("%s %s\n", stu[0].name, stu[0].id);
    printf("%s %s\n", stu[n-1].name, stu[n-1].id);
    return 0;
}