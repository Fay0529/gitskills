#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        a=a%1000;
        int sum=0;
        while(b!=0){
            if(b%2==1){
                sum+=a;
                sum=sum%1000;
            }
            b/=2;
            a*=a;
            a=a%1000;
        }
        cout<<sum<<endl;
    }
} 