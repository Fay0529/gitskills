#include <bits/stdc++.h>

using namespace std;
int dr(int x)
{
    if(x<10)return x;
    int sum=0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return dr(sum);
}    
int main(){
    int n;
    while(cin>>n){
        cout<<dr(n)<<endl;
    }
}