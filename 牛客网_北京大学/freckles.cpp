#include <bits/stdc++.h>
#define KRUSKCAL
//#define PRIM
using namespace std;


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

#ifdef KRUSKCAL 
    /**
     * 利用kruskcal算法实现,
     * 并查集实现
    */
    void UFset(){//并查集初始化
        for(int i=0;i<n;i++)
            parent[i]=-1;

    }
    int UFfind(int x){
        //找到x节点所在树的根节点
        int ret;
        for(ret=x;parent[ret]>=0;ret=parent[ret]);
        //优化方案 --压缩路径，方便后续查找
        while(ret!=x){
            int tmp=parent[x];
            parent[x]=ret;
            x=tmp;
        }
        return ret;
    }
    void UFunion(int R1,int R2){
        //合并R1 ，R2所在树
        int root1=UFfind(R1);
        int root2=UFfind(R2);
        //parent[root1 root2]都是小于零的数
        if(parent[root1]>parent[root2]){
            parent[root2]+=parent[root1]
            parent[root1]=root2;
            
        }
        else {
            parent[root1]+=parent[root2];
            parent[root2]=root1;
        }
    }
#endif
#ifdef PRIM

#endif
int main(){
    freopen("in.txt","r",stdin);
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            double x,y;
            cin>>x>>y;
            v[i]=point(x,y);
        }
#ifdef KRUSKCAL
        UFset();

        // 构建边集合
        int k=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                double len=sqrt(pow(v[i].x-v[j].x,2)+pow(v[i].y-v[j].y,2));
                e[k++]=edge(i,j,len);
            }
        }
        double sum=0;
        //按边从小到大排序
        sort(e,e+k);
        for(int i=0;i<k;i++){
            int a=e[i].a;
            int b=e[i].b;
            int r1=UFfind(a);
            int r2=UFfind(b);
            if(r1!=r2){
                sum+=e[i].len;
                UFunion(r1,r2);
            }
        }
#endif  
#ifdef PRIM

#endif      
        printf("%.2f\n",sum);
        
      


    }
    return 0;
}
