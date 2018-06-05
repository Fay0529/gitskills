#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("in.txt","r",stdin);
    string data;
    while(getline(cin,data)){
        for(int i=0;i<data.length();i++){
            if(data[i]>='A'&&data[i]<='Z'){
                if(data[i]=='Z')data[i]='A';
                else data[i]=(char)(data[i]+1);
            }
            else if(data[i]>='a'&&data[i]<='z'){
                if(data[i]=='z')data[i]='a';
                else data[i]=(char)(data[i]+1);
            }
        }
        cout<<data<<endl;
    }
}
