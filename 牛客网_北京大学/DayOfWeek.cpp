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

};
int buf[3001][13][32];
map<string,int>mmap;
map<int,string>dmap;
void init(){
    mmap["January"]=1;
    mmap["February"]=2;
    mmap["March"]=3;
    mmap["April"]=4;
    mmap["May"]=5;
    mmap["June"]=6;
    mmap["July"]=7;
    mmap["August"]=8;
    mmap["September"]=9;
    mmap["October"]=10;
    mmap["November"]=11;
    mmap["December"]=12;
    dmap[0]="Sunday";
    dmap[1]="Monday";
    dmap[2]="Tuesday";
    dmap[3]="Wednesday";
    dmap[4]="Thursday";
    dmap[5]="Friday";
    dmap[6]="Saturday";

    date tmp;
    tmp.year=0;
    tmp.month=1;
    tmp.day=1;
    int cnt=0;
    while(tmp.year<3001){
        buf[tmp.year][tmp.month][tmp.day]=cnt;
        cnt++;
        tmp.getNext();
    }
}

int main(){
    init();
    int d;
    char m[20];
    int y;
    while(scanf("%d%s%d",&d,m,&y)!=EOF){
        int month=mmap[m];
        int diff=buf[y][month][d]-buf[2018][6][8];
        diff+=5;//今天星期5
        
        cout<<dmap[(diff%7+7)%7]<<endl;
    }
}
