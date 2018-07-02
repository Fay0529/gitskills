#include <bits/stdc++.h>
using namespace std;
#define isLeap(x) x%100!=0&&x%4==0||x%400==0?1:0
int dayOfMonth[13][2]{ 
    /**
     * 记住了，这个地方要搞错
    */
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};
struct date{
    int y;
    int m;
    int d;
    void getNext(){
        d++;
        if(d>dayOfMonth[m][isLeap(y)]){
            d=1;
            m++;
            if(m>12){
                m=1;
                y++;
            }
        }
    }
};
int buf[5001][13][32];
void init(){
    // freopen("in.txt","r",stdin);
    date tmp;
    tmp.y=0;
    tmp.m=1;
    tmp.d=1;
    int cnt=0;
    while(tmp.y<5001){
        buf[tmp.y][tmp.m][tmp.d]=cnt;
        cnt++;
        tmp.getNext();
    }
}
int main(){
    init();
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        int cnt=buf[m][1][1]+n-1;
        date tmp;
        tmp.y=m;
        tmp.m=1;
        tmp.d=1;
        while(buf[tmp.y][tmp.m][tmp.d]!=cnt){
            tmp.getNext();
        }
        printf("%04d-%02d-%02d\n",tmp.y,tmp.m,tmp.d);
    }

}
