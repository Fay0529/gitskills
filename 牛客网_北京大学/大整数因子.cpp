#include <bits/stdc++.h>
using namespace std;
string s;
int func(string s,int n){
/**
 * 大整数除法
 * 返回余数
*/
    int r=0;
    for(int i=0;i<s.length();i++){
        r=r*10+s[i]-'0';
        r=r%n;
    }
    return r;
}
int main(){
    freopen("in.txt","r",stdin);
    while(cin>>s){
        int first=1;
        for(int i=2;i<10;i++){
            if(func(s,i)==0){
                if(first){
                    cout<<i;
                    first=0;
                }
                else cout<<' '<<i;
            }
        }
        if(first==1){
            cout<<"none"<<endl;
        }
        else cout<<endl;
    }


    return 0;
}