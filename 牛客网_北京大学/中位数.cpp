#include <bits/stdc++.h>
using namespace std;

int data[10005];
int main(){
    //freopen("in.txt","r",stdin);

    int  n;
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            cin>>data[i];
        }
        sort(data,data+n);
        int tmp=0;
        if(n%2==0){
            tmp=(int)(data[n/2]+data[n/2-1])/2;
        }
        else tmp=data[n/2];
        cout<<tmp<<endl;
    }

    return 0;
}
