#include <bits/stdc++.h>
using namespace std;
/**
 * 首先利用kruskcal算法实现,
 * 算法实现的关键是并查集的实现
*/
struct point{
    double x;
    double y;
    point(double a=0,double b=0):x(a),y(b){}
}v[105];
struct edge{
    int a,b;
    double len;
    edge(int x=0,int y=0,double l=0):a(x),b(y),len(l){}
    bool operator< (const edge & e)const{
        return this->len<e.len;
    }
}e[10000];

int n;
int parent[105];
void UFset(){//并查集初始化
    for(int i=0;i<n;i++)
        parent[i]=-1;

}
int UFfind(int x){
    //找到x节点的
}
int main(){
    freopen("in.txt","r",stdin);
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            double x,y;
            cin>>x>>y;
            v[i]=point(x,y);
        }

        // 构建边集合
        int k=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double len=sqrt(pow(v[i].x-v[j].x,2)+pow(v[i].y-v[j].y,2));
                e[k++]=edge(i,j,len);
            }
        }
       
        //按边从小到大排序
        sort(e,e+k);
        
      


    }
    return 0;
}
