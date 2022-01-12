#include <bits/stdc++.h>

struct Stu
{
    char name[11];
    char gender;
    char id[11];
    int grade;
};

int main() {
    int N, i;
    scanf("%d", &N);
    Stu stu[N];
    int lowest = 100, sub_l = -1, highest = 0, sub_h = -1;
    for (i = 0; i < N; i++)
    {
        scanf("%s", &stu[i].name);
        getchar();
        stu[i].gender = getchar();
        getchar();
        scanf("%s%d", &stu[i].id, &stu[i].grade);
        if (stu[i].gender=='M')
        {
            if (lowest>stu[i].grade)
            {
                lowest = stu[i].grade;
                sub_l = i;
            }
        }
        if (stu[i].gender=='F')
        {
            if (highest<stu[i].grade)
            {
                highest = stu[i].grade;
                sub_h = i;
            }
        }
    }
    if (sub_h != -1) printf("%s %s\n", stu[sub_h].name, stu[sub_h].id);
    else printf("Absent\n");
    if (sub_l != -1) printf("%s %s\n", stu[sub_l].name, stu[sub_l].id);
    else printf("Absent\n");
    if (sub_l != -1 && sub_h != -1) printf("%d", stu[sub_h].grade-stu[sub_l].grade);
    else printf("NA");  
    return 0;
}