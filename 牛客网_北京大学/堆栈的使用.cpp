# include <bits/stdc++.h>
using namespace std;

int n;
stack<int>data;
int main(){
    
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
                if(!data.isEmpty())data.pop();
            }
            else if(c=='A'){
                if(!data.isEmpty())cout<<data.top()<<endl;
                else cout<<'E'<<endl;
            }
        }
    }
}