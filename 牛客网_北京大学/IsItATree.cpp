#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    set<int>toSet;
    set<int>fromSet;
    int from,to;
    bool flag=true;
    int cnt=0;
    while(flag){
        cnt++;
        toSet.clear();
        fromSet.clear();
        int f=1;
        while(cin>>from>>to&&from&&to){
            
            if(from<0&&to<0){flag=false;break;}
            if(toSet.count(to)==0)toSet.insert(to);
            else {printf("Case %d is not a tree.\n",cnt);
                  f=0;
                  break;
                  
                  }
            if(toSet.count(from)==0)//如果to集合没有有from，就先把它放到from集合里，因为要保证有一个根节点不在to集合里
                fromSet.insert(from);
        }
        //检查from集合里面是不是恰好有个元素是to里面没有的
        if(f==1){
            int cc=0;
            set<int>::iterator it=fromSet.begin();
            while(it!=fromSet.end()){
                if(toSet.count(*it)==0)cc++;
            }
            if(1==cc){
                printf("Case %d is a tree.\n",cnt);
            }
            else printf("Case %d is not a tree.\n",cnt);
        }    
    }
    return 0;
}
