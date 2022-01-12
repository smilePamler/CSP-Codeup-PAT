#include <bits/stdc++.h>

int main() {
    int p_Galleon, p_Sickle, p_Knut;
    int a_Galleon, a_Sickle, a_Knut;
    scanf("%d.%d.%d %d.%d.%d", &p_Galleon, &p_Sickle, &p_Knut, &a_Galleon, &a_Sickle, &a_Knut); 
    int price = p_Galleon*17*29 + p_Sickle*29 + p_Knut;
    int money = a_Galleon*17*29 + a_Sickle*29 + a_Knut;
    int charge = money - price;
    if (charge < 0)
    {
        printf("-");
        charge = -charge;
    }
    printf("%d.%d.%d", charge/(17*29), charge%(17*29)/29, (charge%(17*29))%29);
    return 0;
}
    