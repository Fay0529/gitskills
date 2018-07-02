#include <bits/stdc++.h>
using namespace std;
#define N 10000000
bool mark[N];//suppose that all of the number is prime number
int prime[10001];
void init(){
    int primeSize=0;
    for(int i=2;i<N&&primeSize<10001;i++){
        if(mark[i]==true)continue;
        prime[primeSize++]=i;
        for(int j=i*2;j<N;j+=i){
            mark[j]=true;
        }
    }
}
int main(){
    init();
    //for(int i=0;i<10;i++)cout<<mark[i]<<endl;
    int k;
    while(cin>>k){
        cout<<prime[k-1]<<endl;
    }
}

