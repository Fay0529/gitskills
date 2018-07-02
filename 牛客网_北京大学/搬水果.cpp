# include <bits/stdc++.h>
using namespace std;

int n;
int ans=0;
priority_queue<int,vector<int>,greater<int> >data;

int main(){
    while(cin>>n)
    {   ans=0;
        while(!data.empty())data.pop();
        while(n--){
            int tmp;
            cin>>tmp;
            data.push(tmp);
        }
        while(data.size()>1){
            int a=data.top();
            data.pop();
            int b=data.top();
            data.pop();
            ans+=a+b;
            data.push(a+b);
        }
        cout<<ans<<endl;
    }
}