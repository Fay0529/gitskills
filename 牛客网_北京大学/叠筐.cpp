#include <bits/stdc++.h>
using namespace std;
char mymap[90][90];
int n;
char c;
char w;
void draw(int dis,int flag){
   char s=flag?w:c;
   for(int i=45-dis;i<=45+dis;i++){
       mymap[i][45-dis]=s;
       mymap[i][45+dis]=s;
   }
   for(int i=45-dis;i<=45+dis;i++){
       mymap[45-dis][i]=s;
       mymap[45+dis][i]=s;
   }
}
void draw(){
    for(int i=0;i<n/2+1;i++){
        draw(i,i%2);
    }
    if(n/2){
        mymap[45-n/2][45-n/2]=' ';
        mymap[45-n/2][45+n/2]=' ';
        mymap[45+n/2][45-n/2]=' ';
        mymap[45+n/2][45+n/2]=' ';
    }
}
void print(){
    int flag;
    for(int i=0;i<90;i++){
        flag=false;
        for(int j=0;j<90;j++){
            if(mymap[i][j]!='\0'){
                cout<<mymap[i][j];
                flag=true;
            }
        }
        if(flag)
        cout<<endl;
    }
    
}
int main(){
    int flag=false;
    while(cin>>n>>c>>w){
     if(flag)
     cout<<endl;
     flag=true;
     memset(mymap,'\0',sizeof(mymap));
     draw();
     print();
    }

}