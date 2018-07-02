#include <bits/stdc++.h>
using namespace std;
bool mark[100000];
int prime[10000];
int primeSize=0;
void init(){
    //求50000以内的质数
    for(int i=2;i<100000;i++){
        if(mark[i]==true)continue;
        prime[primeSize++]=i;
        for(int j=2*i;j<100000;j+=i){
            mark[j]=true;
        }
    }
}

int myfunc(int x){
    int ansp[10000]={0};
    int ansSize=0;
    if(x==1)return 1;
    int flag1=false;
    for(int i=0;i<primeSize;i++){
         int flag=false;
        while(x%prime[i]==0)
        {   flag1=true;
            flag=true;
            ansp[ansSize]++;
            x/=prime[i];

        }
        if(flag)ansSize++;
        if(x==1)break;
    }
    if(flag1==false) return 2;
    if(x!=1)ansp[ansSize++]++;
    int mul=1;

    for(int i=0;i<ansSize;i++){
        mul*=(ansp[i]+1);
    }
    return mul;
}
int main(){
    int n;
    init();
    while(cin>>n&&n){
        while(n--){
            int tmp;
            cin>>tmp;
            cout<<myfunc(tmp)<<endl;
        }
    }
}
