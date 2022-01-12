// 类似B1028
#include <bits/stdc++.h>

struct Person
{
    char id[16];
    char sign_in[9];
    char sign_out[9];
};

int main() {
    int M, i;
    scanf("%d", &M);
    Person p[M];
    int ear_h = 23, ear_m = 59, ear_s = 59, sub_ear = 0;
    int lat_h = 0, lat_m = 0, lat_s = 0, sub_lat = 0;
    for (i = 0; i < M; i++)
    {
        scanf("%s%s%s", &p[i].id, &p[i].sign_in, &p[i].sign_out);
        int h_in = (p[i].sign_in[0]-'0')*10+(p[i].sign_in[1]-'0');
        int m_in = (p[i].sign_in[3]-'0')*10+(p[i].sign_in[4]-'0');
        int s_in = (p[i].sign_in[6]-'0')*10+(p[i].sign_in[7]-'0');
        int h_out = (p[i].sign_out[0]-'0')*10+(p[i].sign_out[1]-'0');
        int m_out = (p[i].sign_out[3]-'0')*10+(p[i].sign_out[4]-'0');
        int s_out = (p[i].sign_out[6]-'0')*10+(p[i].sign_out[7]-'0');
        if (h_in<ear_h)
        {
            ear_h = h_in;
            ear_m = m_in;
            ear_s = s_in;
            sub_ear = i;
        }
        else if (h_in==ear_h)
        {
            if (m_in<ear_m)
            {
                ear_m = m_in;
                ear_s = s_in;
                sub_ear = i;
            }
            else if (m_in==ear_m && s_in<ear_s)
            {
                ear_s = s_in;
                sub_ear = i;
            }  
        }
        if (h_out>lat_h)
        {
            lat_h = h_out;
            lat_m = m_out;
            lat_s = s_out;
            sub_lat = i;
        }
        else if (h_out==lat_h)
        {
            if (m_out>lat_m)
            {
                lat_m = m_out;
                lat_s = s_out;
                sub_lat = i;
            }
            else if (m_out==lat_m && s_out<lat_s)
            {
                lat_s = s_out;
                sub_lat = i;
            }  
        }
    }
    printf("%s %s", p[sub_ear].id, p[sub_lat].id);
    return 0;
}