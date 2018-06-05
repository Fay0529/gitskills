#include <bits/stdc++.h>
using namespace std;
/*
*hs_10003_m   2007-01-17 19:22:53,318     126.622(s)
*/
string data[10001];
struct node{
    char name[20];
    int year;
    int month;
    int date;
    int hour;
    int minute;
    int sec;
    int msec;
    float time;
};
int comp(string a,string b){
    struct node anode,bnode;
    sscanf(a.c_str(),"%s %d-%d-%d %d:%d:%d,%d %f",anode.name,&anode.year,&anode.month,&anode.date,&anode.hour,&anode.minute,&anode.sec,&anode.msec,&anode.time);
    sscanf(b.c_str(),"%s %d-%d-%d %d:%d:%d,%d %f",bnode.name,&bnode.year,&bnode.month,&bnode.date,&bnode.hour,&bnode.minute,&bnode.sec,&bnode.msec,&bnode.time);
    if(anode.time!=bnode.time)return anode.time<bnode.time;
    if(anode.year!=bnode.year)return anode.year<bnode.year;
    if(anode.month!=bnode.month)return anode.month<bnode.month;
    if(anode.date!=bnode.date )return anode.date<bnode.date;
    if(anode.hour!=bnode.hour)return anode.hour<bnode.hour;
    if(anode.minute!=bnode.minute )return anode.minute <bnode.minute;
    if(anode.sec!=bnode.sec) return anode.sec<bnode.sec;
    return anode.msec<bnode.msec;

}
int main(){

   // freopen("in.txt","r",stdin);
    int n=0;
    while(getline(cin,data[n++]));

    sort(data,data+n-1,comp);
    for(int i=0;i<n-1;i++){
        cout<<data[i]<<endl;
    }
    return 0;
}
