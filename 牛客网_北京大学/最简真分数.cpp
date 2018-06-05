#include <bits/stdc++.h>
using namespace std;
//判断两个数有没有公约数
bool hasgys(int a,int b){
    int t=a<b?a:b;
    for(int i=2;i<=t;i++){
        if(a%i==0&&b%i==0) return true;
        
    }
    return false;
}
int main(){
    //freopen("in.txt","r",stdin);
    int n;
    int data[605]={0};
    cin>>n;
    while(int i=0;i<n;i++){
        cin>>data[i];
    }
    sort(data,data+n);
    cout<<"data[0]:"<<data[0]<<endl;
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(!hasgys(data[i],data[j]))cnt++;
        }
    }
    cout<<cnt<endl;

    return 0;
}
