# include <bits/stdc++.h>
using namespace std;

int n;
stack<int>data;
int main(){
   // freopen("in.txt","r",stdin);
    while(cin>>n){
        while(n--){
            char c;
            cin>>c;
            if(c=='P'){
                int d;
                cin>>d;
                data.push(d);
            }
            else if(c=='O'){
                if(!data.empty())data.pop();
            }
            else if(c=='A'){
                if(!data.empty())cout<<data.top()<<endl;
                else cout<<'E'<<endl;
            }
        }
        while(!data.empty())data.pop();
        cout<<endl;
    }
}
