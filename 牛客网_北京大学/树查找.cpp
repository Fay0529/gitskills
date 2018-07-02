#include <bits/stdc++.h>
using namespace std;
int tree[1005];
int n;
int d;
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>tree[i];
        cin>>d;
        int i=pow(2,d-1)-1;
        if(i>=n)
        {
            cout<<"EMPTY";

        }
        for(;i<pow(2,d)-1&&i<n;i++){
            cout<<tree[i];
            if(i<pow(2,d)-2)cout<<' ';
        }
        cout<<endl;
    }
}
