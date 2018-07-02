#include <bits/stdc++.h>
using namespace std;
#define isRun(x) x%100!=0&&x%4==0||x%400==0?1:0
int monthDay[13][2]={
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
    int year;
    int month;
    int day;
   void getNext(){
       day++;
       if(day>monthDay[month][isRun(year)]){
           day=1;
           month++;
           if(month>12){
           month=1;
           year++;
            }
       }
       
   }

}
int buf[5001][13][32];


int main(){
    // freopen("in.txt","r",stdin);
    date tmp;
    tmp.year=0;
    tmp.month=1;
    tmp.day=1;
    int cnt=0;
    while(tmp.year!=5001){
        buf[tmp.year][tmp.month][tmp.day]=cnt;
        cnt++;
        tmp.getNext();
    }
    data d1,d2;
    while(scanf("%4d%2d%2d",&d1.year,&d1.month,&d1.day)!=EOF){
        scanf("%4d%2d%2d",&d2.year,&d2.month,&d2.day);
        int res=abs(buf[d1.year][d1.month][d1.day]-buf[d2.year][d2.month][d2.day])+1；
        cout<<res<<endl;
    }
    return 0;
}