#include<bits/stdc++.h>
using namespace std;
int c,n,v,w;
int cc[100];
int main(){
    cin>>c;
    while(c--){
        cin>>n>>v>>w;
        for(int i=0;i<n;i++){
            cin>>cc;
        }
        sort(cc,cc+n);
        double current=cc[0];
        int sumOfV=v;
        int sumOfcc=cc[0];
        int i;       
        for(i=1;i<n;i++){
            if(current>w)break;
            sumOfV+=v;
            sumOfcc+=cc[i];
            current=1.0*sumOfcc/sumOfV*100;
        }
        i--;
        sumOfV-=v;
        sumOfcc-=cc[i]
        printf("%d %.2lf\n",sumOfV,1.0*sumOfcc/sumOfV);
        }
    return 0;
}