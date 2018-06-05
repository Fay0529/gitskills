#include <bits/stdc++.h>
using namespace std;


struct node{
    int weight;
    char color [15];
    node(int w=0,char * s=""){
        weight=w;
        strcpy(color,s);
    }
    bool operator< (const node &n) const{
        return this->weight>n.weight;
    }
};
struct node data[105];
int main(){
 //   freopen("in.txt","r",stdin);

    int  n;
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            int w;
            char c[15];
            cin>>w>>c;
            data[i]=node(w,c);
        }
        sort(data,data+n);
        for(int i=0;i<n;i++){
            cout<<data[i].color<<endl;
        }

    }

    return 0;
}
