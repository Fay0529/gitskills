#include <bits/stdc++.h>
using namespace std;
vector<int> seq(char a,char b,string s){
    vector<int>res;
    int flag=b=='z'?true:false;
    for(int i=0;i<s.length();i++){
        if(s[i]>=a&&s[i]<=b||(flag&&s[i]=='_')){
            res.push_back(i);
        }
    }
    // cout<<"seq a:"<<endl;
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }
    // cout<<endl;
    return res;
}

vector<int> rotation(vector<int>vec,int k){
    int n=vec.size();
    k=k%n;
    
    vector<int>res;
    for(int i=n-k;i<n;i++){
        res.push_back(vec[i]);
    }
    for(int i=0;i<n-k;i++){
        res.push_back(vec[i]);
    }
//      cout<<"seq b:"<<endl;
// for(int i=0;i<res.size();i++){
//     cout<<res[i]<<" ";
// }
// cout<<endl;
    return res;
    
}
void turn(vector<int>a,vector<int>b,string &s){
    string tmp=s;
    for(int i=0;i<a.size();i++){
        s[a[i]]=tmp[b[i]];
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    int k1,k2,k3;
    string input;
    while(cin>>k1>>k2>>k3&&(k1||k2||k3)){
        cin>>input;
        vector<int>a=seq('a','i',input);
        vector<int>b=rotation(a,k1);
        turn(a,b,input);
        a=seq('j','r',input);
        b=rotation(a,k2);
        turn(a,b,input);
        a=seq('s','z',input);
        b=rotation(a,k3);
        turn(a,b,input);
        cout<<input<<endl;
    }
    return 0;
}
