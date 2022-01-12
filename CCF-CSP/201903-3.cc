 #include <iostream>
 #include <algorithm>
 using namespace std;

struct Disk
{
    string Content;
    int  ID;
};
Disk disk[1000];

bool Comp(Disk d1, Disk d2) {
    return d1.ID > d2.ID ? 0 : 1;
}

int FindDiskBlockID(int BlockNum, int StripeSize, int n) {
    int StripeID = BlockNum / StripeSize;
    int DiskID = StripeID % n;
    int DiskBlockID = ;
}

 int main() {
    int n, s, l, m, i;
    cin >> n >> s >> l; // 阵列硬盘数、阵列条带数、现存硬盘数
    for (i = 0; i < l; i++)
    {
        cin >> disk[i].ID >> disk[i].Content;
    }
    sort(disk, disk+l, Comp);
    cin >> m; // 读操作次数
    int b[m]; // 每次读操作的块号
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (i = 0; i < m; i++)
    {
        
    }
    
    return 0;
 }